#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin >> n;
	vector<int> ord(n,0);
	for(int i = 0; i < n; i++){
		int a;
		cin >> a;
		ord[i] = a;
	}
	vector<vector<int>> dp(n+1, vector<int>(3,0));
	vector<vector<int>> dp2(n+1, vector<int>(3,0));
	for(int i = 1; i <= n; i++){
		//end at 1
		dp[i][0] = dp[i-1][0] + (ord[i-1] == 1 ? 0:1);
		//end at 2
		dp[i][1] = min(dp[i-1][0] + (ord[i-1] == 2 ? 0:1), dp[i-1][1] + (ord[i-1] == 2 ? 0:1));
		//end at 3
		dp[i][2] = min(dp[i-1][1] + (ord[i-1] == 3 ? 0:1), dp[i-1][2] + (ord[i-1] == 3 ? 0:1));
	}
	int fm = min(min(dp[n][0], dp[n][1]),dp[n][2]);
	
	//now backwards!
	
	for(int i = 1; i <= n; i++){
		//end at 1
		dp2[i][2] = dp2[i-1][2] + (ord[i-1] == 3 ? 0:1);
		//end at 2
		dp2[i][1] = min(dp2[i-1][2] + (ord[i-1] == 2 ? 0:1), dp2[i-1][1] + (ord[i-1] == 2 ? 0:1));
		//end at 3
		dp2[i][0] = min(dp2[i-1][0] + (ord[i-1] == 1 ? 0:1), dp2[i-1][1] + (ord[i-1] == 1 ? 0:1));
	}
	int bm = min(min(dp2[n][0], dp2[n][1]),dp2[n][2]);
	cout<<min(bm, fm)<<'\n';
}
