#include<iostream>
using namespace std;


/*Iterative Factroial V1.0*/
long factorial(int n){
    int count;
    long product;
    for(product=1,count=2;count<=n;count++)
        product*=count;
     return product;
   
}
 
/*Iterative Factroial V1.1 : saves one variable*/
long Factorial(int n){
   long product;
   for(product=1;n>=1;n--)
        product*=n;
    return product;
}

/*Recursive Factroial Version*/
long F (int n){
    return (n==0)?1:(n*F(n-1));
}

/*Recursive Fibonacci Version*/
long fibonacci (int n){
return (n<=0)?0 : (n==1)? 1: (fibonacci(n-1)+fibonacci(n-2));
}

/*Iterative Fibonacci Version*/
long Fibonacci (int n){
    long i;
    long twoback;
    long oneback;
    long current;
    if(n<=0)
        return 0;
    else if(n==1)
        return 1;
    else{
        twoback=0;
        oneback=1;
        for(i=2;i<=n;i++){
            current=twoback+oneback;
            twoback=oneback;
            oneback=current;
        }
        return current;
    }
}


int main(){

    cout<<factorial(5)<<'\n';
    cout<<Factorial(5)<<'\n';
    cout<<F(5)<<'\n';
    cout<<fibonacci(12)<<'\n';
    cout<<Fibonacci(12)<<'\n';
}