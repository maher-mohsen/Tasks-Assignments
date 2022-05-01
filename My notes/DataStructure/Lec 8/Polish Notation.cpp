#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <cctype>
#include <cstdio>
#include <cstdlib>
#include <string>
#include <iomanip>
#include <cmath>
#include <vector>
#include <algorithm>
#include <vector>
#include <utility> 
using namespace std ;

int IsDigit(char c){
    return(c>='0'&&c<='9');
}

int Precedent (char op1,char op2){
    if(op1=='$')return 1;
    if((op1=='*')||(op1=='/'))
        return (op2!='$');
    if((op1=='+')||(op1=='-'))
        return ((op2!='$')&&(op2!='*')&&(op2!='/'));

    return 0;
}

void InfixToPostfix(char infix[],char postfix[]){
    int i,j;
    char c,op;
    Stack s;
    CreateStack(&s);
    for(i=0,j=0;(c=infix[i])!='\0';i++){
        if(IsDigit(c))
            postfix[j++]=c;
        else{
            if(!StackEmpty(&s)){
                StackTop(&op,&s);
                while(!StackEmpty(&s)&&Precedent(op,c)){
                    Pop(&op,&s);
                    postfix[j++]=op;
                    if(!StackEmpty(&s)) StackTop(&op,&s);
                }
            } 
            Push(c,&s);
        }
        while(!StackEmpty(&s)){
            Pop(&op,&s);
            postfix[j++]=op;
        }
        postfix[j]='\0';
    }
}
long Oper(char c,long op1,long op2){
    switch(c){
        case '+': return(op1+op2);
        case '-': return(op1-op2);
        case '*': return(op1*op2);
        case '/': return(op1/op2);
        case '$': return(pow(op1,op2));
    }
}
long EvaluatePostfix(char expr[]){
        int i;
        char c;
        long op1,op2,val;
        Stack s;
        CreateStack(&s)
        for(i=0;(c=expr[i])!='\0';i++){
                if(IsDigit(c))
                    Push((long)(c-'0'),&s);
                else{
                    Pop(&op2,&s);
                    Pop(&op1,&s);
                    val=Oper(c,op1,op2);
                    Push(val,&s);
                }
                Pop(&val,&s);
                return val;
        }







}
int main()
{
  
  
    
return 0;
}