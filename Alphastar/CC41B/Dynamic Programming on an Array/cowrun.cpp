/*
The trick here: each state is the max distance ran by the end of minute i, at exhaustion j.
We update the current cell by assuming we ran here from the previous cell, this helps deal with the fact that once we stop running, we stop until we're fully rested.
We then check if we stop runnig after this minute, we can reach 0 exhaustion by the time end. If so, that's a valid solution and we update that square to have a viable state that can be ran from, and the answer.
Again, we only update values of cells that can be gotten to by running, not resting.
*/
#include <bits/stdc++.h>
using namespace std;
int main(){
	int n, m;
	cin >> n >> m;
	vector<int> dists(n,0);
	for(int i = 0; i < n; i++){
		cin >> dists[i];
	}
	vector<vector<int>> dp(n+1, vector<int>(m+1,-1)); //dp[i][j] is the maximum distance ran by the end of minute i, at exhaustion j.
	
	for(int i = 0; i < n; i++){
		dp[i][0] = 0;
	}
	int md = dists[0];
	dp[0][1] = dists[0]; //this line and 17 were originally ahead of line 12 (so they got overwritten), and that led me to finding the real issue. 
	dp[1][0] = dists[0];
	for(int i = 1; i < n; i++){
		dp[i][0] = max(dp[i][0], dp[i-1][0]); //i forgot this and it broke ALL the cases (the case where we rest even though we're at 0 exhaustion)
		for(int j = 1; j <= m; j++){
			
			if(dp[i-1][j-1] != -1){ //this only equals -1 if there is a way we can get to that state while we aren't resting.
			
				dp[i][j] = max(dp[i][j], dp[i-1][j-1] + dists[i]); //we continue running in this minute.	
			
				if(i + j < n){
//				cout<<"We can stop running after minute "<<i<<" with exhaustion "<<j<<" and have 0 at "<<i + j<<'\n';
		
					dp[i + j][0] = max(dp[i+j][0], dp[i][j]); //we see when we reach an exhaustion of 0, since that's when we can run agian and also meet the criteria for a solution.
//					cout<<"accessed dp"<<i + j<<'\n';
					md = max(md, dp[i][j]);
//					cout<<"md is now "<<md<<"at state "<<i<<" "<<j<<"versus"<<dp[i][j]<<'\n';
		
				}			
		
			}
					
		}

	}
	cout<<md<<'\n';
}
