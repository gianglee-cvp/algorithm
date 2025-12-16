#include <bits/stdc++.h>
using namespace std ;

int main()
{
int n ; 
cin >> n ; 
int a[n] ; 
for(int i = 0 ; i < n ; i++){
  cin >> a[i] ; 
}
int l   , r ; 
long long sum , maxsum ; 
sum = 0 ; 
maxsum = -1e9 ;
for(int i = 0 ; i < n ; i++ ){
  sum += a[i] ; 
  if(sum <= 0 ){
    if(sum > maxsum){
      maxsum = sum ; 
    }
    else sum = 0 ; 
  }
  else{
    maxsum = max (maxsum ,  sum ) ;
  }
}
cout << maxsum ; 
}