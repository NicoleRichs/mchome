#include <bits/stdc++.h>
using namespace std;
int main(){
	ifstream in("teamwork.in");
	ofstream out("teamwork.out");
	int dp[10000] = {};
	int values[10000] = {}; 
	int n, k;
//	cin >> n >> k;
	in >> n >> k;
	for(int i = 0; i < n; i++){
//		cin >> values[i];
		in >> values[i];
	}
	dp[0] = values[0];
	for(int i = 1; i < n; i++){
		int maxS = values[i];
		for(int j = i; j>=0 && (i - j) < k ; j--){ 
			maxS = max(maxS, values[j]);
			if(j == 0){
				dp[i] = max(dp[i], (i+1) * maxS);
			}
			else{
				dp[i] = max(dp[i], dp[j-1] + ((i-j+1) * maxS));
			}
		}
	}
//	cout<<dp[n-1]<<'\n';
	out<<dp[n-1]<<'\n';
}
