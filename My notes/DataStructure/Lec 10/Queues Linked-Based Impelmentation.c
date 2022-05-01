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
#include <bits/stdc++.h>

using namespace std ;

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

int main()
{
   Osiris
    // freopen("bar.in","r",stdin) ;
  ll n;cin>>n;
   if(n==1){
      cout<<4<<endl;
      return 0;
  }
  Unsigned long long compare=1e12;
  Unsigned long long temp;
 
  for(int i=1;i<=n;i++){
      if(n%i==0){
          compare=min(compare,2*(i+(n/i)));
        if(compare==temp){
            cout<<temp<<endl;
            return 0;
        }
        else{
          temp=compare;
        }

      }
  }
//   for(int i=1;i<factors.size();i+=2){
//       ll x=2*(factors[i]+factors[i-1]);
//       multi.push_back(x);
//   }
//   sort(multi.begin(),multi.end());
//   cout<<multi[0]<<endl;

return 0;
}