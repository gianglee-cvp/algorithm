#include <bits/stdc++.h> 
using namespace std ; 
struct bl{
  int x , y , h ; 
};

int main(){
  int n ; 
  int i = 1 ; 
  while(cin >> n && n!= 0 ) {
  vector<bl> block  ; 
  for(int i =0 ; i < n ; i++){
    int a , b ,c ; 
    cin >> a >> b >> c; 
    block.push_back({max(a,b) , min(a,b) , c}) ; 
    block.push_back({max(a,c) , min(a,c) , b}) ; 
    block.push_back({max(b,c) , min(c,b) , a}) ; 
  }
  sort(block.begin() , block.end() ,  []( bl  a ,  bl b){
    return a.x*a.y > b.x * b.y ; 
  }) ;
  int m = block.size() ; 
  vector<int> dp(m , 0 ) ; 
  int ans = 0 ; 
  // for(auto c : block){
  //   cout << c.x << c.y << c.h << endl ; 
  // }
  for(int i = 0 ; i < m ; i++){
    dp[i] = block[i].h ; 
    for(int j = 0 ; j < m ; j++){
      if(block[j].x > block[i].x && block[j].y > block[i].y){
        dp[i] = max(dp[i] , dp[j] + block[i].h)  ; 
      }
    }
    ans = max(ans , dp[i])  ; 
   }
  cout << "Case " << i++ << ": maximum height = " <<   ans << endl ; 
  }
}