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
#include <fstream> 
using namespace std ;
ofstream file("steps.txt");
// FAST I/O 
#define Osiris cin.tie(0), cout.tie(0), cin.sync_with_stdio(0), cout.sync_with_stdio(0) ;
#define endl '\n' ; 
#define fai(n) for(int i=0;i<n;i++)
typedef long long ll ;
typedef int i ;
typedef double d ;
typedef float f ;
typedef string s ;

const ll   llmin  = -1e18 ;
const ll   llmax  =  1e18 ;
const int  imin   = -1e9  ;
const int  imax   =  1e9  ;

int cnt=0;
int MoveDisks(int count ,int start,int finish,int temp){
if(count>0){
    MoveDisks(count-1,start,temp,finish);
    file<<"Move Disk "<<count<< " from "<<start<<' '<<"to "<<finish<<'\n';
        MoveDisks(count-1,temp,finish,start);
        cnt++;

}
}
/*Removing tail*/
int moveDisks(int count ,int start,int finish,int temp){
        int swap;
        while(count>0){
            moveDisks(count-1,start,temp,finish);
            file<<"Move Disk "<<count<< " from "<<start<<' '<<"to "<<finish<<'\n';
                count--;
                swap =start;
                start=temp;
                temp=swap;
                cnt++;

        }
}


int main()
{
   Osiris
    // freopen("bar.in","r",stdin) ;
    moveDisks(9,1,2,3);
    file<<'\n'<<cnt;
return 0;
}
