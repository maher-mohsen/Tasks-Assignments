#include<iostream>
using namespace std;

class Fraction{
    private:
        int nume;
        int deno;
    public:

//Constructors Section 
    //Default
        Fraction();
    //Copy
        Fraction(Fraction const &);

//Assingment            
        Fraction operator=(const Fraction&);

//Methods Section
    /*Pre : Function takes a Fraction
      Post : Return Deci Number Represent the frac */
    //Frac To Deci
        double FracToDeci();

    /*Pre : Function takes a Fraction
      Post : Return The most simplifed Frac */
    //Reduce Function
             Fraction ReduceFraction();

//Overloading Operators Section
    //Calcultions 
        //on Fraction operations
            //Add     
                Fraction operator+(Fraction&);
            //Substract
                Fraction operator-(Fraction&);

            //Multiplication
                Fraction operator*(const Fraction&);
            //Divide
                Fraction operator/(const Fraction&);
        //on Integer Operations

            //Add
                Fraction operator+(const int&);
            //Substract
                Fraction operator-(const int&);
            //Multiplication
                Fraction operator*(const int&);

            //Divide    
                Fraction operator/(const int&);


    //Comparing
        // Bigger Than
            bool operator>( Fraction&);
        //Smaller Than
            bool operator<( Fraction&);
        //Equality
            bool operator==( Fraction&);
        //Bigger than or equal
            bool operator>=( Fraction&);

        //less than or equal
            bool operator<=( Fraction&);

        
    //Insertion & Extraction
        friend ostream& operator <<(ostream&,const Fraction&);
        friend istream& operator>>(istream&,Fraction&);


};


