#include "fractions.h";
#include<iostream>
using namespace std;


// Function to return GCD of two numbers---Uses for common deno
long long gcd(long long int a, long long int b)
{
  if (b == 0)
    return a;
  return gcd(b, a % b);
}
 
// Function to return LCM of two numbers---Uses for common deno
long long lcm(int a, int b)
{
    return (a / gcd(a, b)) * b;
}

Fraction Fraction::operator=(const Fraction& frac){
    this->deno=frac.deno;
    this->nume=frac.nume;
    return *this;
}
Fraction::Fraction(){
    nume=0;
    deno=0;
}
Fraction::Fraction(Fraction const &frac){
            nume=frac.nume;
            deno=frac.deno;
        }   
double Fraction::FracToDeci(){
        double x=(double)this->nume/(double)this->deno;
        return x;
}
Fraction Fraction::ReduceFraction(){
         Fraction fr,fr2;
                    fr.deno=this->deno;
                    fr.nume=this->nume;
                    int denom;
                    denom = gcd(nume,deno);
                    fr.nume=nume/=denom;
                    fr.deno=deno/=denom;
                    return fr; 
}

Fraction Fraction::operator+(Fraction&frac){
    Fraction fr;
                    fr.deno=this->deno;
                    fr.nume=this->nume;
                    if(deno==frac.deno){
                        fr.deno=deno;
                    fr.nume=nume+frac.nume;
                    }
                    else{
                        int lc = lcm(frac.deno,deno);
                        int x = nume*frac.deno;
                        int y = frac.nume *deno;
                        fr.deno = lc;
                        fr.nume=x+y;
                    }
                    return fr.ReduceFraction();
}
Fraction Fraction::operator-(Fraction& frac){
                    Fraction fr;
                    fr.deno=this->deno;
                    fr.nume=this->nume;
                    if(deno==frac.deno){
                        fr.deno=deno;
                    fr.nume=nume-frac.nume;
                    }
                    else{
                        int lc = lcm(frac.deno,deno);
                        int x = nume*frac.deno;
                        int y = frac.nume *deno;
                        fr.deno = lc;
                        fr.nume=x-y;
                    }
                    return fr.ReduceFraction();
                }

Fraction Fraction::operator*(const Fraction& frac){
                    Fraction fr;
                    fr.deno=this->deno;
                    fr.nume=this->nume;
                    fr.nume=nume*=frac.nume;
                    fr.deno=deno*=frac.deno;
                    return fr.ReduceFraction();
                }

Fraction Fraction::operator/(const Fraction& frac){
                    Fraction fr;
                    fr.deno=this->deno;
                    fr.nume=this->nume;
                    fr.nume=nume*frac.deno;
                    fr.deno=deno*frac.nume;
                    return fr.ReduceFraction();
                }

Fraction Fraction::operator+(const int& x){
                    Fraction frac;
                    Fraction fr;
                    fr.deno=this->deno;
                    fr.nume=this->nume;
                    frac.deno=1;
                    frac.nume=x;
                    int lc = lcm(frac.deno,deno);
                        int b = nume*frac.deno;
                        int y = frac.nume *deno;
                        fr.deno = lc;
                        fr.nume=b+y;
                    return fr.ReduceFraction();
                }
Fraction Fraction::operator-(const int& x){
                    Fraction frac;
                    Fraction fr;
                    fr.deno=this->deno;
                    fr.nume=this->nume;
                    frac.deno=1;
                    frac.nume=x;
                    int lc = lcm(frac.deno,deno);
                        int b = nume*frac.deno;
                        int y = frac.nume *deno;
                        fr.deno = lc;
                        fr.nume=b-y;
                        return fr.ReduceFraction();
            }

Fraction Fraction::operator*(const int& frac){
                    Fraction fr;
                    fr.deno=this->deno;
                    fr.nume=this->nume;
                    fr.nume=nume*=frac;
                    fr.deno=deno*=1;
                    return fr.ReduceFraction();
                }

Fraction Fraction::operator/(const int& frac){
                        Fraction fr;
                        fr.deno=this->deno;
                        fr.nume=this->nume;
                        fr.nume=nume*1;
                        fr.deno= deno*frac;
                        return fr.ReduceFraction();
                    }


 bool Fraction::operator>( Fraction &frac){
                Fraction fr,fr2;
                if(deno==frac.deno){
                    return(nume>frac.nume);
                    
                    }
                    else{
                        int lc = lcm(frac.deno,deno);
                        fr.nume = nume*frac.deno;
                        fr2.nume = frac.nume *deno;
                        fr.deno = lc;
                        return(fr2.nume<fr.nume);
                    }
            }

bool Fraction::operator<( Fraction &frac){
                    Fraction fr,fr2;
                    if(deno==frac.deno){
                        return(nume<frac.nume);
                        }

                        else{
                            int lc = lcm(frac.deno,deno);
                            fr.nume = nume*frac.deno;
                            fr2.nume = frac.nume *deno;
                            fr.deno = lc;
                            return(fr2.nume>fr.nume);
                        }
                }

 bool Fraction::operator==( Fraction &frac){
                    Fraction fr,fr2;
                    if(deno==frac.deno){
                        return(nume==frac.nume);
                        }

                        else{
                            int lc = lcm(frac.deno,deno);
                            fr.nume = nume*frac.deno;
                            fr2.nume = frac.nume *deno;
                            fr.deno = lc;
                            return(fr2.nume==fr.nume);
                        }
                }
bool Fraction::operator>=( Fraction &frac){
                    Fraction fr,fr2;
                    if(deno==frac.deno){
                        return(nume==frac.nume||nume>frac.nume);
                        }

                        else{
                            int lc = lcm(frac.deno,deno);
                            fr.nume = nume*frac.deno;
                            fr2.nume = frac.nume *deno;
                            fr.deno = lc;
                            return(fr2.nume==fr.nume||fr2.nume<fr.nume);
                        }
                }
    
bool Fraction::operator<=( Fraction &frac){
                    Fraction fr,fr2;
                    if(deno==frac.deno){
                        return(nume==frac.nume||nume<frac.nume);
                        }

                        else{
                            int lc = lcm(frac.deno,deno);
                            fr.nume = nume*frac.deno;
                            fr2.nume = frac.nume *deno;
                            fr.deno = lc;
                            return(fr2.nume==fr.nume||fr2.nume>fr.nume);
                        }
                }

  ostream& operator <<(ostream& out,const Fraction& frac){
            out<<frac.nume<<'/'<<frac.deno;
            return out;
            } 
  istream& operator>>(istream& in,Fraction& frac){
            char dumb;
            in>>frac.nume>>dumb>>frac.deno;
            while(frac.deno==0){
               cout<< "Please enter valid fraction you can not divide on zero !..."<<'\n';
                in>>frac.nume>>dumb>>frac.deno;
            }
            return in;
        }

        class FractionCalculator{
    private:
        Fraction fr1,fr2,ans;
        void MainMenu(){
            char selector='y';
            bool ansr=0;
            while(selector!='7'){
                cout<<"Welcome To Fractions Calculator..,,"<<'\n';
                cout<<"----------------------------------------"<<'\n'<<'\n';
                cout<<"Please Enter Fraction 1 : ex : (a/b) ...."<<'\n';
                cin>>fr1;
                cout<<"Please Enter Fraction 2 : ex : (a/b) ...."<<'\n';
                cin>>fr2;
                cout<<"Please Choose Your Operation..."<<'\n'<<'\n';
                cout<<"1 . Add "<<'\n';
                cout<<"2 . Substract "<<'\n';
                cout<<"3 . Multiplication "<<'\n';
                cout<<"4 . Divide "<<'\n';
                cout<<"5 . Reduce fraction "<<'\n';
                cout<<"6 . Fraction to decimal  "<<'\n';
                cout<<"7 . End  "<<'\n';
                cin>>selector;
                system("CLS");
                if(selector=='1'){
                    char s;
                    if(ansr){
                        cout<<"Choose which operation ..."<<'\n'<<'\n';
                        cout<<"1 . Frac 1 + Frac 2"<<'\n';
                        cout<<"2 . Frac 1 + Ans"<<'\n';
                        cout<<"3 . Frac 2 + Ans"<<'\n';
                        cin>>s;
                        if(s=='1'){
                            ans = fr1 + fr2;
                            cout<<fr1+fr2<<endl;
                        }
                        else if(s=='2'){
                            cout<<fr1+ans<<endl;
                            ans = fr1+ans;
                        }
                        else if(s=='3'){
                            cout<<fr2+ans<<endl;
                            ans = fr2+ans;
                        }
                        s='0';
                    }
                    else{
                        cout<<fr1+fr2<<endl;
                        ans=fr1+fr2;
                        ansr=1;
                    }
                    cout<<"Continue Y/N"<<endl;
                    cin>>s;
                    if(s=='n'||s=='N'){
                        cout<<"Thanks for using fractions calculator...."<<'\n';
        break;
                    }
                }
            else if(selector=='2'){
                char s;
                if(ansr){
                        cout<<"Choose which operation ..."<<'\n'<<'\n';
                        cout<<"1 . Frac 1 - Frac 2"<<'\n';
                        cout<<"2 . Frac 2 - Frac 1"<<'\n';
                        cout<<"3 . Frac 1 - Ans"<<'\n';
                        cout<<"4 . Frac 2 - Ans"<<'\n';
                        cout<<"5 . Ans    - Frac 1"<<'\n';
                        cout<<"6 . Ans    - Frac 2"<<'\n';
                        cin>>s;
                        if(s=='1'){
                            cout<<fr1-fr2<<endl;
                            ans=fr1-fr2;
                        }
                        else if(s=='2'){
                            cout<<fr2-fr1<<endl;
                            ans=fr2-fr1;
                        }
                        else if(s=='3'){
                            cout<<fr1-ans<<endl;
                            ans=fr1-ans;
                        }
                        else if(s=='4'){
                            cout<<fr2-ans<<endl;
                            ans=fr2-ans;
                        }
                        else if(s=='5'){
                            cout<<ans-fr1<<endl;
                            ans=ans-fr1;
                        }
                        else if(s=='6'){
                            cout<<ans-fr2<<endl;
                            ans=ans-fr2;
                        }

                }
            else{
                cout<<"Choose which operation ..."<<'\n'<<'\n';
                        cout<<"1 . Frac 1 - Frac 2"<<'\n';
                        cout<<"2 . Frac 2 - Frac 1"<<'\n';
                        cin>>s;
                    if(s=='1'){
                        cout<<fr1-fr2<<endl;
                        ans=fr1-fr2;
                    }
                    else if(s=='2'){
                        cout<<fr2-fr1<<endl;
                        ans=fr2-fr1;
                    }
                    ansr=1;
                    s='0';
            }
             cout<<"Continue Y/N"<<endl;
                    cin>>s;
                    if(s=='n'||s=='N'){
                        cout<<"Thanks for using fractions calculator...."<<'\n';
        break;
                    }
            }
        else if(selector=='3'){
            char s;
            if(ansr){
                cout<<"Choose which operation ..."<<'\n'<<'\n';
                cout<<"1 . Frac 1 * Frac 2"<<'\n';
                cout<<"2 . Frac 1 * Ans"<<'\n';
                cout<<"3 . Frac 2 * Ans"<<'\n';
                cin>>s;
                if(s=='1'){
                            ans = fr1 * fr2;
                            cout<<fr1*fr2<<endl;
                        }
                        else if(s=='2'){
                            cout<<fr1*ans<<endl;
                            ans = fr1*ans;
                        }
                        else if(s=='3'){
                            cout<<fr2*ans<<endl;
                            ans = fr2*ans;
                        }
                        s='0';
            }
            else{
                cout<<fr1*fr2<<endl;
                ans = fr1*fr2;
                ansr=1;
                s='0';
            }
             cout<<"Continue Y/N"<<endl;
                    cin>>s;
                    if(s=='n'||s=='N'){
                        cout<<"Thanks for using fractions calculator...."<<'\n';
        break;
                    }
        }
        else if(selector=='4'){
                char s;
                if(ansr){
                        cout<<"Choose which operation ..."<<'\n'<<'\n';
                        cout<<"1 . Frac 1 / Frac 2"<<'\n';
                        cout<<"2 . Frac 2 / Frac 1"<<'\n';
                        cout<<"3 . Frac 1 / Ans"<<'\n';
                        cout<<"4 . Frac 2 / Ans"<<'\n';
                        cout<<"5 . Ans    / Frac 1"<<'\n';
                        cout<<"6 . Ans    / Frac 2"<<'\n';
                        cin>>s;
                        if(s=='1'){
                            cout<<fr1/fr2<<endl;
                            ans=fr1/fr2;
                        }
                        else if(s=='2'){
                            cout<<fr2/fr1<<endl;
                            ans=fr2/fr1;
                        }
                        else if(s=='3'){
                            cout<<fr1/ans<<endl;
                            ans=fr1/ans;
                        }
                        else if(s=='4'){
                            cout<<fr2/ans<<endl;
                            ans=fr2/ans;
                        }
                        else if(s=='5'){
                            cout<<ans/fr1<<endl;
                            ans=ans/fr1;
                        }
                        else if(s=='6'){
                            cout<<ans/fr2<<endl;
                            ans=ans/fr2;
                        }

                }
            else{
                cout<<"Choose which operation ..."<<'\n'<<'\n';
                        cout<<"1 . Frac 1 / Frac 2"<<'\n';
                        cout<<"2 . Frac 2 / Frac 1"<<'\n';
                        cin>>s;
                    if(s=='1'){
                        cout<<fr1/fr2<<endl;
                        ans=fr1/fr2;
                    }
                    else if(s=='2'){
                        cout<<fr2/fr1<<endl;
                        ans=fr2/fr1;
                    }
                    ansr=1;
                    s='0';
            }
             cout<<"Continue Y/N"<<endl;
                    cin>>s;
                    if(s=='n'||s=='N'){
                        cout<<"Thanks for using fractions calculator...."<<'\n';
        break;
                    }
        }
        else if(selector=='5'){
            char s;
            if(ansr){
                cout<<"Choose which Fraction ..."<<'\n'<<'\n';
                cout<<"1 . Frac 1"<<'\n';
                cout<<"2 . Frac 2"<<'\n';
                cout<<"3 . Ans   "<<'\n';
                cin>>s;
                if(s=='1'){
                    fr1.ReduceFraction();
                    cout<<fr1<<endl;
                    ans=fr1;
                }
                else if(s=='2'){
                    fr2.ReduceFraction();
                    cout<<fr2<<endl;
                    ans=fr2;
                }
                else if(s=='3'){
                    ans.ReduceFraction();
                    cout<<ans<<endl;
                }
            }
            else{
                cout<<"Choose which Fraction ..."<<'\n'<<'\n';
                cout<<"1 . Frac 1"<<'\n';
                cout<<"2 . Frac 2"<<'\n';
                cin>>s;
                if(s=='1'){
                    fr1.ReduceFraction();
                    cout<<fr1<<endl;
                    ans=fr1;
                
                }
                else if(s=='2'){
                    fr2.ReduceFraction();
                    cout<<fr2<<endl;

                    ans=fr2;
                }
                ansr=1;
                s='0';
            }
             cout<<"Continue Y/N"<<endl;
                    cin>>s;
                    if(s=='n'||s=='N'){
                        cout<<"Thanks for using fractions calculator...."<<'\n';
                            break;
                    }
        }
    else if(selector=='6'){
        char s;
            if(ansr){
                cout<<"Choose which Fraction ..."<<'\n'<<'\n';
                cout<<"1 . Frac 1"<<'\n';
                cout<<"2 . Frac 2"<<'\n';
                cout<<"3 . Ans   "<<'\n';
                cin>>s;
                if(s=='1'){
                    cout<<fr1.FracToDeci()<<endl;
                    ans=fr1;
                }
                else if(s=='2'){
                    cout<<fr2.FracToDeci()<<endl;
                    ans=fr2;
                }
                else if(s=='3'){
                    cout<<ans.FracToDeci()<<endl;
                }
            }
            else{
                cout<<"Choose which Fraction ..."<<'\n'<<'\n';
                cout<<"1 . Frac 1"<<'\n';
                cout<<"2 . Frac 2"<<'\n';
                cin>>s;
                if(s=='1'){
                    
                    cout<<fr1.FracToDeci()<<endl;
                    ans=fr1;
                
                }
                else if(s=='2'){
        
                    cout<<fr2.FracToDeci()<<endl;

                    ans=fr2;
                }
                ansr=1;
                s='0';
            }
             cout<<"Continue Y/N"<<endl;
                    cin>>s;
                    if(s=='n'||s=='N'){
                        cout<<"Thanks for using fractions calculator...."<<'\n';
                     break;
                    }
    }
    else if(selector=='7'){
        cout<<"Thanks for using fractions calculator...."<<'\n';
        break;
    }
    }






        }

    public:
    FractionCalculator(){
        MainMenu();
    }
    ~FractionCalculator(){

    }


};