#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin >> n;
	vector<int> nums;
	for(int i = 0; i < n; i++){
		int a;
		cin >> a;
		nums.push_back(a);
		
	}
	vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
	for(int i = 0; i < n; i++){
		dp[i][1] = nums[i];
	}
	for(int i = 2; i <=n; i++){
		for(int j = 0; j <= n-i; j++){
			int m = 0;
			for(int k = 1; k < i; k++){
//				cout<<i<<" "<<j<<" "<<k<<" "<<j+k<<" "<<i-k<<'\n';
				m = max(max(dp[j][k], dp[j+k][i-k]), m);
				if(dp[j][k] == dp[j+k][i-k]){
					m = max(dp[j][k]+1, m);
				}
			}
			for(int k = 1; k < i; k++){
//				cout<<i<<" "<<j<<" "<<k<<" "<<j+k<<" "<<i-k<<'\n';
				m = max(max(dp[j][i-k], dp[j+(i-k)][k]),m);
				if(dp[j][i-k] == dp[j+(i-k)][k]){
					m = max(dp[j][i-k]+1, m);
				}
			}
			
			dp[j][i]=m;
		}
	}
	cout<<dp[0][n]<<'\n';
}
