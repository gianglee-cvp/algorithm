#include <bits/stdc++.h>
using namespace std ;
int n , k ; 
int c[3005] ; 
int a[3005] ; 
vector<vector<int>> dp ; 

int main()
{
  cin >> n >> k ; 
  dp.assign(k+ 3 , vector<int> (n+3 , -1)) ; 
  for(int i = 1 ; i <= n ; i++){
    cin >> c[i] ; 
  }
  for(int i = 1 ; i <= n ; i++){
  cin >> a[i] ; 
  }
  dp[1][1] = c[1] ; 
  for(int i = 1 ; i <= k ; i++){
    for(int j = 1 ; j <n ; j++){
      if(dp[i][j] == -1) continue ; 
      for(int l = 1 ; l <= a[j] && j+l <= n  ; l++ ){
        if(dp[i+1][j+l] == -1){
          dp[i+1][j+l] = dp[i][j] + c[j+l];
        }else{
          dp[i+1][j+l] = max(dp[i+1][j+l] , dp[i][j] + c[j+l]);
        }
      }
    }
  }
  // for(auto c : dp){
  //   for(auto d : c){
  //     cout << d << " " ; 
  //   }
  //   cout << endl ; 
  // }
  int sum = -1 ; 
  for(int i = 2 ; i <= k+1 ; i++ ){
    if(dp[i][n] == -1 ) continue ; 
    else sum = max(sum , dp[i][n]) ; 
  }
  cout << sum ; 
}