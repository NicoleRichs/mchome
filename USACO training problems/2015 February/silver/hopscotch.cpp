#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;
//the mental imagery of the cows hoppin is pretty funny ngl
//la galissonniere's cat skin from azur lane got me actin unwise
//ik catgirls are the meta but i never said i wasn't a slave to the meta
int main(){
	int r, c, k;
	cin >> r >> c >> k;
	vector<vector<int>> numGrids(100, vector<int>(100,0));
	vector<vector<int>> dp(100, vector<int>(100,0));
	for(int i = 0; i < r; i++){
		for(int j = 0; j < c; j++){
			cin >> numGrids[i][j];
		}
	}
	dp[0][0] = 1;
	for(int i = 0; i < r-1; i++){
		for(int j = 0; j < c-1; j++){
			if(dp[i][j]!=0){
				for(int k = i+1; k < r; k++){
					for(int h = j+1; h < c; h++){
						if(numGrids[i][j] != numGrids[k][h]){
							dp[k][h]+=dp[i][j]; //this line fucked me up, i put dp[k[[h]=dp[i][j]+1 first, then ++. I am retard.
							dp[k][h] %=MOD;
						}
					}
				}
			}
		}
	}
//	for(int i = 0; i < r; i++){
//		for(int j = 0; j < c; j++){
//			cout<<dp[i][j]<<" ";
//		}
//		cout<<'\n';
//	}
	cout<<dp[r-1][c-1]<<'\n';
}
