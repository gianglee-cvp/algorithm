#include <bits/stdc++.h>
using namespace std ;
long long m , k ; 
vector<long long> p ; 
vector<long long> cutPos ; 
bool check(long long mid){
    long long sum = 0;
    long long cnt = 1;
    for(long long i = 0; i < m; i++){
        if(sum + p[i] > mid){
            cnt++;
            sum = p[i];
        } else {
            sum += p[i];
        }
    }
    return cnt <= k;
}
int main()
{
long long test ; 
cin >> test ; 
while (test --){
  cin >> m >> k ; 
  p.resize(m) ;
  cutPos.assign(m , 0 )  ; 
  long long high = 0 , low = 0 ; 
  for(long long i = 0 ; i < m ; i++){
    cin >> p[i] ; 
    high += p[i] ; 
    low = max(low , p[i]) ; 
  }
 // cout << low << high  ; 
 long long mid ; 
while(low < high ){
  mid = (low +high) /2 ; 
  if(check(mid)){
    high = mid ; 
  }
  else low = mid +1 ; 
}
long long sum = 0 ; 
long long groupLeft = k ; 
for(long long i = m-1 ; i >= 0 ; i--){
  if (sum +p[i] > high || i + 1 < groupLeft) {
    cutPos[i] = 1;
    groupLeft--;
    sum = p[i];
}else {
  sum += p[i] ; 
}
}
for (long long i = 0; i < m; i++) {
            cout << p[i];
            if (i != m - 1) cout << " ";
            if (cutPos[i])
                cout << "/ ";
        }
        cout << "\n";
}
}