#include <bits/stdc++.h>
using namespace std;
struct edge{
	int to, val;
};
int minll(long long a, long long b){
	if(a < b){
		return a;
	}
	else{
		return b;
	}
}
int maxll(long long a, long long b){
	if(a > b){
		return a;
	}
	else{
		return b;
	}
}
int main(){
	int v, e, k;
	cin >> v >> e >> k;
	vector<vector<edge>> adj(e);
	vector<pair<int,int>> ps;
	vector<int> id(e, 0);
	for(int i = 0; i < e; i++){
		int a, b, c;
		cin >> a >> b >> c;
		adj[a-1].push_back({b-1,c});
		if(b == v){
			ps.push_back({a-1, c});
		}
		id[b-1]++;
	}
	stack<int> zid;
	zid.push(0);
	vector<int> neword;
	while(!zid.empty()){
		int c = zid.top();
		zid.pop();
		for(edge a : adj[c]){
			id[a.to]--;
			if(id[a.to] == 0){
				zid.push(a.to);
			}
		}
		neword.push_back(c);
	}
	vector<vector<long long>> dp(v, vector<long long>(k+1, -1));
	dp[v-1][0] = 0;
	for(pair<int,int> y : ps){
		dp[y.first][0] = maxll(dp[y.first][0],y.second);
	}
	for(int j = v-1; j >= 0; j--){
		for(int a = 0; a <=k; a++){
			int cn = neword[j];
			//case 1: no slip
			int temp1 = 0;
			for(edge e : adj[cn]){
				temp1 = maxll(e.val + dp[e.to][a], temp1);
			}
			//case 2: slip
			int temp2 = 2147483647;
			if(a > 0){
				for(edge e : adj[cn]){
					temp2 = minll(e.val + dp[e.to][a-1], temp2);
				}
			}
			dp[cn][a] = minll(temp1, temp2); 
		}
	}
	cout<<dp[0][k]<<'\n';
//	for(int i = 0; i <=k; i++){
//		for(int j = 0; j < v; j++){
//			cout<<dp[j][i]<<' ';
//		}
//		cout<<'\n';
//	}
}
