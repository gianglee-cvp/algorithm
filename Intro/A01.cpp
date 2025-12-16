/*Alice có a
 cái kẹo, Bob cho Alice b
 cái kẹo, hỏi Alice có tổng cộng bao nhiêu cái kẹo. Yêu cầu viết chương trình bằng ngôn ngữ C/C++

Lưu ý giới hạn: a,b<1019
 dẫn đến c
 có thể vượt quá khai báo long long */
#include <bits/stdc++.h> 
using namespace std ; 
int main(){
  long long a, b ; 
  cin >> a >> b ; 
  
  long long c = a/10 + b/10 ; 
  if(c > 1e17){
    if((a%10 + b%10) > 9 ){
      cout << c + 1 << (a%10 + b %10 -10) ; 
    }
    else {
      cout << c << (a%10 + b %10) ; 
    
    }
  }
  else cout << a + b ;
}