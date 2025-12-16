// (a+b) mod (10^9+7) a and b is in long long type
#include <bits/stdc++.h> 
using namespace std ; 
int main(){
  unsigned long long a, b ; 
  cin >> a >> b ; 
  int d = 1e9 +7 ;
  cout << (((a%d) + (b%d))%d);
}