#include <bits/stdc++.h>
using namespace std;
int n, x;
int main(){
	cin >> n >> x;
	vector<int> dp(1000001, -1);
	int coinlist[n] = {};
	for(int i = 0; i < n; i++){
		cin >> coinlist[i];
	}
	dp[0] = 0;
	for(int a = 0; a < n; a++){
		dp[coinlist[a]] = 1;
	}
//	cout<<"END IO"<<'\n';	
	for(int p = 1; p < x; p++){
		if(dp[p] != -1){
			for(int m = 0; m < n; m++){
				if(p + coinlist[m] <= x){
					if(dp[p + coinlist[m]] == -1){
						dp[p+coinlist[m]] = dp[p]+1;
					}
					else{
						dp[p+coinlist[m]] = min(dp[p]+1, dp[p+coinlist[m]]);
					}
				}
			}
		}
	}
	cout<<dp[x]<<'\n';
}
