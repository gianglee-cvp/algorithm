#include <bits/stdc++.h>
using namespace std ;

int main()
{
int n ,  m ; 
cin >> n >> m ; 
vector<int> result(502 , 0 ) ;
vector<int> a(n+1) ; 
for(int i = 1 ; i <= n ; i++){
  cin >> a[i] ; 
} 
int mod = 1e9 +7 ; 
long long dp[105][505] ; 
memset(dp, 0 , sizeof(dp)) ;
dp[0][0]  = 1;   
for(int i =  1; i <=n ; i++){
  for(int j = 0 ; j <= m ; j++){
    int k = j /a[i] ; 
    for(int l =  1 ; l <= k ; l++){
      dp[i][j] += dp[i-1][j-l*a[i]] ; 
    }
    dp[i][j] %= mod ; 
  }

}
// for(int i =  0; i <=n ; i++){
//   for(int j = 0 ; j <= m ; j++){
//     cout << dp[i][j] <<" " ; 
//   }
//   cout << endl ; 
// }


cout << dp[n][m] %mod ; 
}