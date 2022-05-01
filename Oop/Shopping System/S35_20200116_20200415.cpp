/**
*Authors Info :
*
*           Group B, S35
*
*                   Student name         |   Student ID
*           ------------------------------------------------        
*                   maher mohsen         |   20200415
*           ------------------------------------------------                             
*                   Bemwa malak          |   20200116
*                                                
*
*
*           Online shopping Ass#2
*
*   Project Scope : 
*           A basic online-shopping system (using only Classes & arrays)
*
*
*   Project Description :  
*       we developed a simple and basic onilne-shopping system using array and classes, we have tried as much as possible
*   to make it easy to use and Friendly, First u have to enter your information as a "Seller",Then u have more than one option
*  (print your info,add an item,sell an item,print all items,searching for item).
*  
*
**/

#include <iostream>
#include <istream>
#include <ostream>
#include <Windows.h>

using namespace std;


class Item{
    private:
        int ID_,quantity_;
        double price_;
        string name_;
    public:
        static int numberOfItems;
        //Default constructor
        Item(){
            name_ = "";
            quantity_ = 0;
            price_ = 0;
            ID_ = 0;
        }
        //Parameterized constructor
        Item(const string& name, const int& quantity, const double& price){
            name_ = name;
            quantity_ = quantity;
            price_ = price;
            ID_ = numberOfItems;
            numberOfItems++;
        }
        //Copy constructor
        Item(const Item& item){
            name_ = item.name_;
            quantity_ = item.quantity_;
            price_ = item.price_;
            ID_ = item.ID_;
        }
        

        //Setters (Mutators)
        void setName(const string& name){
            if(!ID_){
                ID_ = numberOfItems;
                numberOfItems++;
            }
            name_ = name;
        }
        void setQuantity(const int& quantity){
            quantity_ = quantity;
        }
        void setPrice(const double& price){
            price_ = price;
        }
        static void correctID(){
            numberOfItems--;
        }


        //Getters (Accessors)
        string getName(){
            return name_;
        }
        int getQuantity(){
            return quantity_;
        }
        double getPrice(){
            return price_;
        }
        int getID(){
            return ID_;
        }
        //Overloading Operators
        //== operator
        bool operator==(const Item& item){
            return name_ == item.name_;
        }
        //+= operator
        void operator+=(const Item& item){
            quantity_ += item.quantity_;
        }
        //-= operator
        void operator-=(const int& quantity){
            quantity_ -= quantity;
        }
        //<< operation
        friend ostream& operator<<(ostream& out, const Item& item){
            out << "Item ID: " << item.ID_ << '\n';
            out << "Item name: " << item.name_ << '\n';
            out << "Item price: " << item.price_ << '\n';
            out << "Item quantity: " << item.quantity_ <<'\n';

            return out;
        } 
        //>> operation
        friend istream& operator>>(istream& in, Item& item){
            cout << "Please enter the item name: ";
            in >> item.name_;
            cout << "Please enter the item price : ";
            in >> item.price_;
            cout << "Please enter the item quantity : ";
            in >> item.quantity_;
            
            item.ID_ = Item::numberOfItems;
            Item::numberOfItems++;

            return in;
        }
};
//intiate Static variable
int Item::numberOfItems = 1;


class Seller{
    private:
        int maxItems_;
        int curItems_;
        string name_,email_;
        Item* items_;
    public:
        //Parameterized constructor
        Seller(const string& name, const string& email, const int& maxItems){
            name_ = name;
            email_ = email;
            maxItems_ = maxItems;
            curItems_ = 0;
            items_ = new Item[maxItems_];
        }

    //Seller FNS :
    /*
    Fn Parameters :
        Item
    Fn return type :
        Boolean
    Fn Description :
         A function to add items ,if items is already exist the quantity will changed
        and if there is no capicty we warn user that capcity is full

    */
        bool addAnItem(Item& item){
            for(int i = 0; i < curItems_; i++){
                if(items_[i] == item){
                    Item::correctID();
                    items_[i] += item;
                    cout<<"Item already exist!,Quantity has cahnged "<<'\n'<<'\n';
                    return true;
                }
            }
            if(curItems_ < maxItems_){
                items_[curItems_] = item;
                curItems_++;
                cout<<"Item added!"<<'\n'<<'\n';
                return true;
            }else{
                cout << "There is no place for an additional item in the shop" << '\n';
                return false;
            }
        }
 /*
  Fn Parameters :
        string,integer
    Fn return type :
        Boolean
    Fn description :
        A function which sell items,if there is no quantity or the item is not exist we warn user 
        
 */
        bool sellAnItem(const string& name, const int& quantity){
            for(int i = 0; i < curItems_; i++){
                if(items_[i].getName() == name){
                    if(items_[i].getQuantity() < quantity){
                        cout << "There is only " << items_[i].getQuantity() << "  left for this item." << '\n';
                        return false;
                    }else{
                        items_[i] -= quantity;
                        cout<<"Done !"<<'\n';
                        return true;
                    }
                }
            }
            cout<<"Item not found ! \n";
            return false;
        }
  /*
   Fn Parameters :
        integer
    Fn return type :
        item
    Fn description:
        searching for item by id and if item is not exist we warn user
        
 */
        Item findItemByID(const int& id){
          Item tmp("Error Item not found", 0, 0);
            for(int i = 0; i < curItems_; i++){
                if(items_[i].getID() == id){
                    return items_[i];
                }
            }
            Item::correctID();
            return tmp;
            
        }
/*
    Fn Parameters :
        void
    Fn return type :
        void
    Fn description: 
        print all items
*/
        void printItems(){
            for(int i = 0; i < curItems_; i++){
                cout << items_[i] << '\n';
            }
        }
       //Destructor :
        ~Seller(){
            delete[] items_;
        }
        //Overloadings : 
        //<< operator
        friend ostream& operator<<(ostream& out, const Seller& seller){
            out << "Seller information: " << '\n';
            out << "Seller name: " << seller.name_ << '\n';
            out << "Seller email: " << seller.email_ << '\n';
            out << "Seller shop capacity: " << seller.maxItems_ << '\n';

            return out;
        }
        
        //>>operator
        friend istream& operator>>(istream& in, Seller& seller){
            cout << "Please enter seller name: ";
            in >> seller.name_;
            cout << "Please enter seller email: ";
            in >> seller.email_;
            cout << "Please enter shop capacity: ";
            in >> seller.maxItems_;

            return in;
        }
};

int main(){
    string name,email;
    int maxItems;
    cout << "Welcome to our simple online shopping system project !" << '\n';
    cout << "Please enter your name: ";
    getline(cin,name);
    cout << "Please enter your email: ";
    cin >> email;
    cout << "Please enter your shop capacity: ";
    cin >> maxItems;

    Seller seller(name, email, maxItems);
    system("CLS");
    cout << "Welcome " << name << " to our online shopping system" << '\n';
    Sleep(2000);
    int n = 0;
    string dumb;
    while(n!=6){
        system("CLS");
        cout << "Please choose your operation number: " << '\n';
        cout << "1) Print Seller Info " << '\n';
        cout << "2) Add an item " << '\n';
        cout << "3) Sell an item " << '\n';
        cout << "4) Print items" << '\n';
        cout << "5) Find an item " << '\n';
        cout << "6) Exit " << '\n';
        cin>>n;
        if(n==1){
            system("CLS");
            cout << seller << '\n';
            cout << "Please enter any character and press enter to return to main menu: " << '\n';
            cin >> dumb;
        }
        if(n==2){
            system("CLS");
            Item x;
            cin >> x;
            seller.addAnItem(x);
            cout << "Please enter any character and press enter to return to main menu: " << '\n';
            cin >> dumb;
        }
        if(n==3){
            system("CLS");
            int q;
            string item;
            cout << "Please enter item name: ";
            cin >> item;
            cout << "Please enter quantity: ";
            cin >> q;
            while(q <= 0){
                cout << "Please enter positive value: ";
                cin >> q;
            }
            seller.sellAnItem(item,q);
            cout << "Please enter any character and press enter to return to main menu: " << '\n';
            cin >> dumb;
        }
        if(n == 4){
            system("CLS");
            seller.printItems();
            cout << "Please enter any character and press enter to return to main menu: " << '\n';
            cin >> dumb;
        }
        if(n == 5){
            system("CLS");
            int id;
            cout << "Please enter item ID: ";
            cin >> id;
            if(seller.findItemByID(id).getName() == "Error Item not found"){
                cout << "Error Item not found" << '\n';
            }else{
                cout << seller.findItemByID(id);
            }
            cout << "Please enter any character and press enter to return to main menu: " << '\n';
            cin >> dumb;
        }
    }
    system("CLS");
    cout << "Thanks for using our online shopping system !" << '\n';
    return 0;
}