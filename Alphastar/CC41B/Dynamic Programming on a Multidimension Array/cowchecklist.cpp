#include <bits/stdc++.h>
using namespace std;
int getDist(pair<int,int> a, pair<int,int> b){
	return ((a.first - b.first) * (a.first - b.first)) + ((a.second - b.second) * (a.second - b.second));
}
int main(){
	int h, g;
	cin >> h >> g;
	vector<pair<int,int>> ph;
	vector<pair<int,int>> pg;
	for(int i = 0; i < h; i++){
		int a, b;
		cin >> a >> b;
		ph.push_back({a, b});
	}
	for(int i = 0; i < g; i++){
		int a, b;
		cin >> a >> b;
		pg.push_back({a, b});
	}
	//my brain hurts from abstracting all of this
	vector<vector<vector<int>>> dp(h+2, vector<vector<int>>(g+2, vector<int>(2, 2000000000))); //dp[i][j][0] is the shortest way to finish visiting i holsteins and j gurnseys, ending on a holstein. dp[i][j][1] ends on a gurnsey.
	dp[1][0][0] = 0;
	for(int i = 1; i <= h; i++){
		for(int j = 0; j <= g; j++){
			dp[i+1][j][0] = min(dp[i+1][j][0], dp[i][j][0] + getDist(ph[i-1],ph[i]));
			dp[i][j+1][1] = min(dp[i][j+1][1], dp[i][j][0] + getDist(ph[i-1],pg[j]));
			if(j != 0){
				dp[i+1][j][0] = min(dp[i+1][j][0], dp[i][j][1] + getDist(ph[i],pg[j-1]));
				dp[i][j+1][1] = min(dp[i][j+1][1], dp[i][j][1] + getDist(pg[j-1],pg[j]));
			}
//			cout<<i+1<<" "<<j<<" "<<dp[i+1][j][0]<<'\n';
//			cout<<i<<" "<<j+1<<" "<<dp[i][j+1][1]<<'\n';
		}
	}
	cout<<dp[h][g][0]<<'\n';
}
