#include <bits/stdc++.h>
using namespace std;
//i swear not doing usaco for a week has got be a bit rusty
//getting ready to say goodbye to my long haircut in a week
//gold here i come, praise be to brian dean
//calculates the result of each game. H = 0, P =1, S =2. Returns 0 if FJ win, 1 if Bessie wins.
int bw(int f, int b){
	if(f == 0){
		if(b == 1){
			return 1;
		}
	}
	if(f == 1){
		if(b == 2){
			return 1;
		}
	}
	if(f == 2){
		if(b == 0){
			return 1;
		}
	}
	return 0;
}
int main(){
	int n, k;
	cin >> n >> k;
	vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(k+1, vector<int>(3,0))); 
	//dp[i][j][k] - the maximum wins at game i, with j switches, with the current gesture as k. (0 is hoof, 1 is scissor, 2 is paper)
	vector<int> play;
	for(int i = 0; i < n; i++){
		char c;
		cin >> c;
		if(c == 'H'){
			play.push_back(0);
		}
		if(c == 'P'){
			play.push_back(1);
		}
		if(c == 'S'){
			play.push_back(2);
		}
	}
	//starting states
	dp[0][0][0] = bw(play[0], 0);
	dp[0][0][1] = bw(play[0], 1);
	dp[0][0][2] = bw(play[0], 2);
	int ans = 0;
	for(int i = 0; i < n-1; i++){ //in iteration i, we are calculating the states of dp[i+1].
		for(int j = 0; j <= k && j <= i; j++){ //looping through all the possible current move change #s
			for(int m = 0; m <= 2; m++){ //looping through currently played move for Bessie - h, p, or s.
				
				//option 1 - continue as-is				
				dp[i+1][j][m] = max(dp[i+1][j][m], dp[i][j][m] + bw(play[i+1], m));
				ans = max(ans, dp[i+1][j][m]);
				//option 2 - add 1 to our move # then mod 3
				if(j < k){
					dp[i+1][j+1][(m+1)%3] = max(dp[i+1][j+1][(m+1)%3], dp[i][j][m] + bw(play[i+1], (m+1)%3));
					ans = max(ans, dp[i+1][j+1][(m+1)%3]);
				}
				//option 3- add 2 to our move # then mod 3
				if(j < k){
					dp[i+1][j+1][(m+2)%3] = max(dp[i+1][j+1][(m+2)%3], dp[i][j][m] + bw(play[i+1], (m+2)%3));
					ans = max(ans, dp[i+1][j+1][(m+2)%3]);
				}
				
			} 
		}
	}
	cout<<ans<<'\n';
//	for(int i = 0; i < n; i++){
//		for(int j = 0; j <= k; j++){
//			cout<<"["<<dp[i][j][0]<<" "<<dp[i][j][1]<<" "<<dp[i][j][2]<<']'<<' ';
//		}
//		cout<<'\n';
//	}
}