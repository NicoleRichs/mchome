#include <bits/stdc++.h>
//me when the O(N^3) :skull:
using namespace std;
int main(){
	int n;
	cin >> n;
	vector<int> ord;
	for(int i = 0; i < n; i++){
		int a;
		cin >> a;
		ord.push_back(a);
	}
	vector<vector<int>> dp(n, vector<int>(n, 1000));
	dp[0][0] = (ord[0] != 0); //dp[i][j] - minimum # when at day i, with j-1 breakouts, the last breakout is on day i.
	for(int i = 0; i < n -1; i++){
		for(int j = 0; j < n -1; j++){
			int d = 0;
			for(int m = i+1; m < n; m++){
				dp[m][j+1] = min(dp[i][j] + d + (ord[m] != 0), dp[m][j+1]);
				if(ord[m] != m - i){
					d++;
				}
			}
		}
	}
	vector<int> minB(n, 1000);
	for(int i = 0; i < n; i++){ //for each dp[i][j], we see how many entries after entry i we have to modify to get it correct (dp[i][j] is # of corrections from entry 0 to i we need to change to get j breakouts by day i, with day i as the last breakout).
		for(int j = 0; j < n; j++){
			int mc = 0;
			for(int k = i+1; k < n; k++){
				if(ord[k]!=(k-i)){
					mc++;
				}
			}
			minB[j] = min(minB[j], dp[i][j] + mc); //take the minimum for #entries changed needed for each # of breakouts
		}
	}
	for(int i = 0; i < n; i++){
		cout<<minB[i]<<'\n';
	}
	//brute force best force
}
