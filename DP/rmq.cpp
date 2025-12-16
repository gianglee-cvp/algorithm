#include <bits/stdc++.h>
using namespace std ;
int n ; 
vector<int> v ; 
vector<int> lg;
static int rmq[1000005][21];   // chỉnh MAXN theo đề

void build_log() {
    lg.resize(n + 1);
    lg[1] = 0;
    for(int i = 2; i <= n; i++)
        lg[i] = lg[i / 2] + 1;
}
int query(int l , int r){
  int j = lg[r-l+1] ; 
  return min(rmq[l][j], rmq[r-(1<<j)+1][j]); 
}
void build(){
    for(int i = 0 ; i < n ; i++) rmq[i][0] = v[i] ; 
    for(int j = 1 ;(1<<j) <= n ; j++){
      for(int k = 0 ; k + (1<<j) <= n ; k++){
        rmq[k][j] = min(rmq[k][j-1] , rmq[k+(1<<(j-1))][j-1]);
      }
    }
}
int main()
{
ios::sync_with_stdio(false);
cin.tie(nullptr);
cin >> n ; 
build_log() ; 
v.resize(n) ; 
for(int i = 0 ; i  < n ; i++){
  cin >> v[i] ; 
}
build() ; 
int k ; cin >> k ;
int a , b ; 
int sum = 0 ; 
while(k--){
  cin >> a >> b ; 
  sum += query(a,b ) ; 
}
cout << sum ; 

}