#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	int x;
	cin >> n >> x;
	vector<int> cost(n);
	vector<int> pages(n);

	for (int i = 0; i < n; i++) { cin >> cost[i]; }
	for (int i = 0; i < n; i++) { cin >> pages[i]; }

	vector<vector<int>> dp(n+1, vector<int>(x + 1));
	for(int i = 1; i <= n; i++){
		int curr_cost = cost[i-1];
		int curr_pages = pages[i-1];
		for(int j = 1; j <= x; j++){
			dp[i][j] = dp[i-1][j];
			if(curr_cost <= j){
				dp[i][j] = max(dp[i][j], dp[i - 1][j - curr_cost] + curr_pages);
			}
		}
	}
	cout<<dp[n][x]<<'\n';
}
