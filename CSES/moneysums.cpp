#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> coinValues;
bool dp[101][100001];
int main(){
	cin >> n;
	for(int i = 0; i < n; i++){
		int a;
		cin >> a;
		coinValues.push_back(a);
	}
	dp[0][0] = true;
	for(int i = 1; i <= n; i++){
		for(int current = 0; current < 100001; current++){
			dp[i][current] = dp[i-1][current];
			int prev = current - coinValues[i-1];
			if(prev >= 0 && dp[i-1][prev]){
				dp[i][current] = true;
			}
		}
	}
	vector<int> possible;
	for(int sum = 1; sum < 100001; sum++){
		if(dp[n][sum]){
			possible.push_back(sum);
		}
	}
	cout<<(int)(possible.size())<<'\n';
	for(int a : possible){
		cout<<a<<' ';
	}
	cout<<'\n';
}
