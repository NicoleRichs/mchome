#include <bits/stdc++.h>
using namespace std;
struct node{
	int cn = 101; //stores the least amount of changed entries
	set<int> m; //stores the possible current day counter value
};
int main(){
	int n;
	cin >> n;
	vector<int> rl;
	for(int i = 0; i < n; i++){
		int a;
		cin >> a;
		rl.push_back(a);
	}
	vector<vector<node>> dp(n, vector<node>(n));
	if(rl[0] != 0){
		(dp[0][0]).cn = 1;
		((dp[0][0]).m).insert(0);
	}
	else{
		(dp[0][0]).cn = 0;
		((dp[0][0]).m).insert(0);
	}
	for(int i = 1; i < n; i++){
		if(rl[i] == i){
			(dp[i][0]).cn = (dp[i-1][0]).cn;
			((dp[i][0]).m).insert(i);
		}
		else{
			(dp[i][0]).cn = (dp[i-1][0]).cn + 1;
			((dp[i][0]).m).insert(i);
		}
		for(int j = 1; j <= i; j++){
			//same # breakouts
			//check dp[i-1][j]. 
			if((((dp[i-1][j]).m).find(rl[i]-1)) !=(((dp[i-1][j]).m).end())){ //should be rl[i] -1, not rl[i-1]
				((dp[i][j]).cn) = ((dp[i-1][j]).cn);
			}
			else{
				((dp[i][j]).cn) = ((dp[i][j]).cn) + 1;
			}
			((dp[i][j]).m).insert(rl[i]);
			//add one breakout - check 0
			int tn = (dp[i-1][j-1]).cn;
			if(rl[i] != 0){
				tn+=1;
			}
			if((tn < (dp[i][j]).cn)){
				((dp[i][j]).m).clear();
				((dp[i][j]).m).insert(0);
				((dp[i][j]).cn) = tn;
			}
			else if((tn == (dp[i][j]).cn)){
				((dp[i][j]).m).insert(0);
			}		
		}
	}
//	for(int i = 0; i < n; i++){
//		for(int j = 0; j < n; j++){
//			cout<<(dp[i][j]).cn<<' ';
//		}
//		cout<<endl;
//	}
	for(int i = 0; i < n; i++){
		cout<<(dp[n-1][i]).cn<<'\n';
	}
}
