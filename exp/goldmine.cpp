#include<bits/stdc++.h>
using namespace std ; 
int main(){
	int n , l1 , l2 ; 
	cin >> n >> l1 >> l2 ; 
	vector<int> a(n) ; 
	vector<int> 
	for(int i = 0 ; i < n ; i++){
		cin >> a[i] ; 
	}
	vector<vector<int> > s(n , vector<int>(2,0)) ;
	s[0][0] = 0 ; 
	s[0][1] = a[0] ;	
	for(int i = 1 ; i< n ; i++){
		s[i][0] = max(s[i-1][0] , s[i-1][1]) ; 
		if(i<l1){
			s[i][1]  = a[i] ; 
		}
		else{
			int maxcur = 0 ; 
			for(int k = l1 ; k <= l2 ; k++){
				if(i-k < 0) break ; 
				maxcur = max(maxcur , s[i-k][1]) ; 
			}
		//	cout << maxcur << endl ; 
			s[i][1] = maxcur + a[i] ; 
		}
	//	cout << a[i] << " " << s[i-1][0] <<" " << s[i-1][1] << endl ; 
	}
	cout <<max( s[n-1][1] , s[n-1][0] ); 
}
