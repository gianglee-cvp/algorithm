#include <bits/stdc++.h>
using namespace std ;

int main()
{
int n , maxt , d ; 
int a[1002] ; 
int t[1002] ; 
cin >> n >> maxt >> d; 
for(int i = 0 ; i < n ; i++ ) cin >> a[i] ; 
for(int i = 0 ; i < n ; i++) cin >> t[i] ; 
vector<vector<int>> dp(1005 , vector<int> (105 , 0));
for(int k = 1 ; k <= maxt ; k++){
  for(int i = 0 ; i < n ; i++){
    if(t[i] > k ){
      dp[i][k] = 0 ; 
    }
    else{
      int tmp = 0 ; 
      for(int j = 1 ; j <= d && i-j >=0 ; j++){
        tmp= max(tmp , dp[i-j][k-t[i]]);
      }
      dp[i][k] = tmp + a[i] ; 
    }
  }
}
int sum = 0  ; 
for(int i = 0 ; i < n ; i++){
  sum = max(sum , dp[i][maxt]) ; 
}
cout << sum ; 
}