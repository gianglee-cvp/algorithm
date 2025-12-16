#include<bits/stdc++.h> 
using namespace std ; 
vector<pair<int,int>> leftSide, rightSide; // (khoảng cách, số hàng)
unsigned long long calcdis( vector<pair<int , int >> & v , int load){
  unsigned long long sum =0 ;
  int i = v.size() - 1 ; 
  unsigned long long curload = 0 ;
  while (i >= 0 ){
    int cns = v[i].second - curload ; 
    if( cns == 0 ){
      curload = 0 ; 
    }
    else if(cns < 0){
      curload -= v[i].second ; 
    }
    else if(cns > 0){
      if(cns % load == 0 ){
        sum += 2LL * v[i].first*(cns / load ) ; 
        curload = 0 ; 
      }
      else{
        sum +=  2LL * v[i].first*(cns / load + 1 ) ; 
        curload = load - cns %load ; 
      }
    }
    i-- ;
  }
  return sum ; 
}

int main(){
  int n , load ; 
  cin >> n >> load ; 
  int c ,d ; // c vi tri  , d la don hang 
    for (int i = 0; i < n; i++) {
        int c, d;
        cin >> c >> d;
        if (c < 0) leftSide.emplace_back(-c, d); // lưu giá trị dương
        else {
          rightSide.emplace_back(c, d);
        } 
        // nếu c == 0 => không cần đi đâu
    }
  sort(leftSide.begin() , leftSide.end()) ; 
  sort(rightSide.begin() , rightSide.end());
  cout << calcdis(leftSide ,load ) +calcdis(rightSide ,load ) ; 
}