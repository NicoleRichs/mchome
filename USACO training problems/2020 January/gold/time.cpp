#include <bits/stdc++.h>
using namespace std;
int n, m, c;
vector<int> money;
vector<int> adjl[1000];
int main(){
	ifstream in("time.in");
	ofstream out("time.out");
	in >> n >> m >> c;
	for(int i = 0; i < n; i++){
		int a;
		in >> a;
		money.push_back(a);
	}
	for(int j = 0; j < m; j++){
		int a, b;
		in >> a >> b;
		adjl[a-1].push_back(b-1);
	}
	//so looking at the formula for making money, in the best case for bessie every city gives 1000 moonies and cost is all 1. Therefore money earned by the end of each day is 1000d - d^2. She'll break even at d = 1000, so no point simulating past that.
	vector<vector<int>> dp(1001, vector<int>(n, -1));
	dp[0][0] = 0;
	int ans = 0;
	for(int i = 0; i < 1000; i++){ //we simulate where bessie could be every day
		for(int x = 0; x < n; x++){
			if(dp[i][x] != -1){ //we'll future-process values so all cities reachable will not be -1
				for(int a : adjl[x]){
					dp[i+1][a] = max(dp[i][x] + (money[a]), dp[i+1][a]); //value at the city is either what it is, or computed from the current node if that's higher
				}
			}
		}
		ans = max(ans, dp[i][0] - (c * i * i)); //checking the current route ending at 0 vs the answer
	}
	out<<ans<<'\n';
}
