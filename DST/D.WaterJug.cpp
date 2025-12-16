#include <bits/stdc++.h>
using namespace std ;

int main()
{
    int a , b, c ; 
    cin >> a >> b >> c ; 
    map<pair<int , int > , int > v;// cac trang thai da co va so buoc dat den do  
    queue<pair<int, int>>  q; 
    q.push({0,0});
    v[{0,0}] = 0 ; 
    while(!q.empty()){
      int  x = q.front().first ; 
      int  y = q.front().second ;
      q.pop() ; 
      if(x == c  || y == c){
         cout << v[{x, y}] ; 
        break ;
      }
      vector <pair < int , int >> next = {
        {a , y } ,
        {x , b} ,
        {0,y } ,
        {x , 0 } ,
        {min( a, x + y) , x+ y - min(a,x+y) }, // do tu b -> a 
        {x +y - min(b , x+ y) , min (b , x+y)}
      };
      
      for( auto c : next ){
        if(!v.count(c)){
          q.push(c) ; 
          v[c] = v[{x, y}] +1; 
        }
      }
    }

}