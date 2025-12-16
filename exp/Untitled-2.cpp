  #include <bits/stdc++.h>
  using namespace std ;
  bool check(vector<int> &tmp , vector<int> &tp){
    for(int i = 0 ; i < tmp.size() ; i++){
      if(tmp[i] == tp[0]){
        for(int j = 0 ; j < tp.size() ; j++){
          if( i+j > tmp.size()  - 1 || tmp[i+j] != tp[j] ){
            break ; 
          }
          if(j == (tp.size() - 1) ) return true ; 
        }
      }
    }
    return false ; 
  }
  int main()
  {
  
  int n ; 
  cin >> n ; 
  string s ; 
  cin >> s ; 
  getline(cin , s)  ; 
  vector<int> v ; 
  if(s.length() == 1){
    return 0 ; 
  }
  v.resize(s.length()) ; 
  for(int i = 0 ; i < s.length() ; i++){
    v[i] = s[i] -'0' ; 
  }
  vector<int> F1head(s.length() -1 , -1) ; 
  vector<int> F2head(s.length() -1 , -1) ; 
  vector<int> F1tail(s.length() -1 , -1) ; 
  vector<int> F2tail(s.length() -1 , -1) ; 
  vector<int> tmp1(s.length() -1 , -1) ; 
  vector<int> tmp2(s.length() -1 , -1) ; 
  F1head[0] = 0 ; 
  F2head[0] = 1 ;
  F1tail[s.length() - 2 ] = 0 ; 
  F2tail[s.length() - 2] = 1;
  
  vector<int> temp( 2*(s.length() - 1)) ; 
  int s1 = 0 ; 
  int s2 = 0 ; 
  int s3 = 0 ; 
  for(int i = 2 ; i <= n  ; i++){
    int flag  = 0 ;
    int l = 0 ; 
    for(auto c : F2tail){
      temp[l++] = c ; 
    }
    for(auto c : F1head){
      temp[l++] = c  ; 
    }
    s3  = s1 +s2 ; 
    if(check(temp , v)){
      s3++ ; 
    }
    s1 = s2  ; 
    s2 = s3 ; 
    tmp1= F2head ; 
    tmp2 = F2tail ; 
    l= 0 ; 
    if(F2head[s.length() - 2 ] == -1){
      for(int i = 0 ; i < F2head.size() ; i++){
        if(l>= F1head.size()) break ; 
        if(F2head[i] != -1){
          continue ; 
        }
        else if(F1head[l] !=  -1 ){
          F2head[i] = F1head[l++] ; 
        }
        else if(F1head[l] == -1){
          break ; 
        }
      }
    }
    for(int j =  s.length() -2 ; j >= 0 ; j--){
      if(F1tail[j] != -1){
        F2tail[j] = F1tail[j] ; 
      }
      else{
        int k = s.length() - 2 ; 
        while(j >=0 && tmp2[k] != -1 && k>-1) {
          F2tail[j--] = tmp2[k--] ; 
        }
        break ; 
      }
    }
    F1head = tmp1 ; 
    F1tail = tmp2 ; 
  }
  cout << "Case 1: " <<  s3 ; 
  
  }
