#include <bits/stdc++.h>
using namespace std;
int main(){
	int t;
	int a;
	int b;
	ifstream in("feast.in");
	ofstream out("feast.out");
//	cin >> t >> a >> b;
	in >> t >> a >> b;
	vector<int> dp(5000000, 0); //0 - state not reached. 1 - state reached, water not drank. 2 - state reached, water drank. If a state is already at 1, state 2 will not override.
	dp[a] = 1;
	dp[b] = 1;
	int ans = max(a,b);
	//ohhhh yeah time to MEMOIZE ALL OVER THE PLACE
	for(int i = 0; i <= t; i++){
		if(dp[i] == 1 || dp[i] == 2){
			if(i + a <= t){
				dp[i + a] = 1;
				ans = max(i+a, ans); 	
			}
			if(i + b <= t){
				dp[i + b] = 1;
				ans = max(i+b, ans);
			}
			if(i > 0){
				if(dp[i] == 1){
					if(dp[(i/2)] == 0){
						dp[(i/2)] = 2;
					}
				}
			}
		}
	}
	//go thru again to clean up the 2's
	for(int i = 0; i <= t; i++){
		if(dp[i] == 2){
			if(i + a <= t){
				if(dp[i+a] == 0){
					dp[i+a] = 2;
					ans = max(i+a, ans);
				}
			}
			if(i + b <= t){
				if(dp[i+b] == 0){
					dp[i+b] = 2;
					ans = max(i+b, ans);
				}
			}
		}
	}
//	cout<<ans<<'\n';
	out<<ans<<'\n';
}
