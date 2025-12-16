#include <bits/stdc++.h>
using namespace std ;
 
int main()
{
  int n , m ; 
  cin >> n >> m ; 
  int x[n+1] , y[m+1] ; 
  for(int i = 1 ; i <= n ; i++) cin >> x[i] ; 
  for(int i = 1 ; i<=m ; i++) cin >> y[i] ; 
  vector<int> prev(m+1 , 0 ); 
  vector<int> cur(m+1 , 0 ) ; 
  for(int i = 1 ; i <=n ; i++){
    for(int j = 1 ; j<=m ; j++){
      if(x[i] == y[j]) {
        cur[j] = prev[j-1] + 1 ; 
      }
      else{
        cur[j] = max(cur[j-1] , prev[j]) ; 
      }
    }
  //  for(auto c : prev ) cout << c <<" " ; 
    cout << endl ; 
    prev = cur ; 
  }
  cout << prev[m] ; 
  
}
