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
	int result = 0;
	for(int l = 1; l <=n; l++){
		for(int s = 0; s + l <= n; s++){
			int j = s+l-1;
			dp[s][j] = -1;
			if(l == 1){
				dp[s][j] = nums[s];
			}
			for(int k = s; k < j; k++){
				if(dp[s][k] == dp[k+1][j] && dp[s][k] > 0){
						dp[s][j] = max(dp[s][j], dp[s][k] + 1);
				}
			}
			result = max(result, dp[s][j]);
		}
	}
	cout<<result<<'\n';
}
