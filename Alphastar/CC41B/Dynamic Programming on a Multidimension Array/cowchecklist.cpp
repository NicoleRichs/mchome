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
	for(int i = 0; i < h; i++){
		int a, b;
		cin >> a >> b;
		pg.push_back({a, b});
	}
	vector<vector<int>> dp(h+1, vector<int>(g+1, 2147483647));
	dp[1][0] = 0;
	for(int i =1; i < h-2; i++){
		for(int j = 0; j < g-1; j++){
			//choice 1: to next H
			dp[i+1][j] = min(dp[i+1][j], dp[i][j] + dist)
			//choice 2: to next G
			
		}
	}
}
