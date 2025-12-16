#include <bits/stdc++.h>
using namespace std ;
int main(){
	int n , k1 , k2 ; 
	cin >> n >> k1 >> k2 ; 
	vector<vector<int> > s(n +1  , vector<int>(2,0 ));  
	
	s[0][0] = s[0][1]=  1 ;  
	for(int i = 1 ; i <= n ; i++){
		s[i][0] = s[i-1][1] ; 
		int j = k1 ; 
		while(j <= k2 && i - j >=0 ){
			s[i][1] += s[i-j][0] ;
			j++;
		}
		
	}
	cout <<s[n][0] + s[n][1]   ; 
}
