#include <bits/stdc++.h>
using namespace std;
int getDist(pair<int,int> a, pair<int,int> b){
	return(abs(a.first - b.first) + abs(a.second - b.second));
}
int main(){
	int n, k;
	cin >> n >> k;
	vector<pair<int,int>> coords;
	for(int i = 0; i < n; i++){
		int a, b;
		cin >> a >> b;
		coords.push_back({a,b});
	}
	vector<vector<int>> dp(n, vector<int>(k+1, 2000000000));	
	dp[0][0] = 0;
	for(int i = 0; i < n-1; i++){ //i is the waypoint we're at now. Ends at n-2 since node n-1 is the endpoint and we won't be starting from it.
		for(int j = 0; j <= k && j <= n; j++){ //this is the current number of waypoints skipped. j<=n to avoid redundant processing, and cases where we can skip more nodes than there are nodes.
			for(int m = 0; m <= k - j; m++){ //this is how many waypoints we will be skipping from this waypoint. Limited to how many remaining skips we have.
				if(i+m+1 < n){ //i+m+1 is the NEXT node AFTER all the nodes we skip
					dp[i+m+1][j+m] = min(dp[i][j] + getDist(coords[i], coords[i+m+1]), dp[i+m+1][j+m]); //we populate the endpoint of our "skip." This approach seems... familiar?
				}
			}
		}
	}
	int ans = 2000000000;
	for(int f = 0; f <= k; f++){ //max number.
		ans = min(ans, dp[n-1][f]);
	}
	cout<<ans<<'\n';
}
