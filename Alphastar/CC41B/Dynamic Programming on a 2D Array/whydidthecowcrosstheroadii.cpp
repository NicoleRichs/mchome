#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin >> n;
	vector<int> s1;
	vector<int> s2;
	for(int i = 0; i < n; i++){
		int a;
		cin >> a;
		s1.push_back(a);
	}
	for(int i = 0; i < n; i++){
		int b;
		cin >> b;
		s2.push_back(b);
	}
	vector<vector<int>> dp(n+1, vector<int>(n+1, 0)); 
	dp[0][0] = (int)((abs(s1[0] - s2[0])) < 5);
	for(int i = 1; i < n; i++){
	    dp[0][i] = max(dp[0][i-1], (int)((abs(s1[0] - s2[i])) < 5));
	}
	for(int i = 1; i < n; i++){
	    dp[i][0] = max(dp[i-1][0], (int)((abs(s1[i] - s2[0])) < 5));
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			int ad = 0;
			if(abs(s1[i] - s2[j]) < 5){
				ad = 1;
			}
			dp[i][j] = max(max(dp[i-1][j-1] + ad, dp[i][j-1]), dp[i-1][j]);
		}
	}
	cout<<dp[n-1][n-1]<<'\n';
}
