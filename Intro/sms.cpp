#include <bits/stdc++.h>
using namespace std ;

int WordNumber(char w){
  if(w < 'p'){
    return (w - 'a')%3 + 1 ;
  }
  else if ((w > 'o' ) &&( w < 't')) {
    return (w -'p')%4 +1;
  }
  else if ((w > 's' ) &&( w < 'w')) {
    return (w -'t')%3 +1;
  }
  else{
    return (w-'w') + 1 ;
  }
}
int countworld(string s){
  int cnt = 0 ;
  for( int i = 0 ; i< s.length() ; i++){
    if(s[i]== ' ') cnt ++ ; 
    else cnt += WordNumber(s[i]);
  }
  return cnt ;
}
int main()
{
  int n ; 
  int i = 0 ; 
  string s ; 
  cin >> n ; 
  getline(cin , s); 
  while (n > 0 ){
    getline(cin , s) ; 
    i ++ ;
    cout << "Case " <<"#" << i << ": " <<  countworld(s) << endl;
    n-- ;
  }

}