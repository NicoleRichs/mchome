#include <bits/stdc++.h>
using namespace std;
int main(){
	int n, m, c;
	cin >> n >> m >> c;
	vector<vector<int>> adj(n+1);
	vector<int> money;
	money.push_back(-1);
	for(int i = 0; i < n; i++){
		int a;
		cin >> a;
		money.push_back(a);
	}
	for(int j = 0; j < m; j++){
		int f, t;
		cin >> f >> t;
		adj[f].push_back(t);
	}
	vector<vector<int>> dp(n+1, vector<int>(501, -1));
	int mv = 0;
	dp[1][0] = 0;
	for(int d = 0; d < 500; d++){ //500 should be enough so that the cost of the trip outweighs the gains. d is the days passed on trip.
		for(int i = 1; i <= n; i++){//i is our current node.
			if(dp[i][d] != -1){ //if we can be at node i on day d:
				for(int a : adj[i]){ //go through all availible travel options
					dp[a][d+1] = max(dp[i][d] + money[a] + (c * d * d) - (c * (d+1) * (d+1)), dp[a][d+1]); //i forgot to add max :skull:. We add back the previous travel fees and add in the new travel fees.
					if(a == 1){ //if we've simulated a trip "completion"
						mv = max(mv, dp[1][d+1]);
					}
				}
			}
		}
	}
	cout<<mv<<'\n';
//	for(int i = 0; i <= n; i++){
//		for(int j= 0 ; j < 10; j++){
//			cout<<dp[i][j]<<" ";
//		}
//		cout<<endl;
//	}
}