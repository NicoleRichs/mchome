#include <bits/stdc++.h>
using namespace std;
struct edge{
	int a, w, s;
};
int main(){
	int n, m, k;
	cin >> n >> m >> k;
	vector<edge> adj[n];
	for(int i= 0; i< m; i++){
		int a, b, w;
		cin >> a >> b >> w;
		adj[a-1].push_back({b-1,w, 0});
		adj[b-1].push_back({a-1,w, 0});
	}
	vector<vector<int32_t>> dist1(k + 1, vector<int32_t>(n));
	for(int i = 0; i <= k; i++){
		dist1[i][0] = 0;
		for(int j = 1; j < n; j++){
			dist1[i][j] = INT32_MAX;
		}
	}
	dist1.shrink_to_fit();	
	priority_queue<edge, vector<edge>, function<bool(const edge&, const edge&)>> tp([](const edge& e1, const edge& e2){return e1.w > e2.w;});
	tp.push({0,0,0});
	while(!tp.empty()){
		int cn = (tp.top()).a;
		int ck = (tp.top()).s;
		tp.pop();
		for(edge v : adj[cn]){
			if(ck < k){
				if(dist1[ck + 1][v.a] == INT32_MAX || dist1[ck + 1][v.a] > dist1[ck][cn]){
					dist1[ck + 1][v.a] = dist1[ck][cn];
					tp.push({v.a, v.w, ck + 1});
				}
			}
			if(dist1[ck][v.a] == INT32_MAX || dist1[ck][v.a] > dist1[ck][cn] + v.w){
				dist1[ck][v.a] = dist1[ck][cn] + v.w;
				tp.push({v.a, v.w, ck});
			}
		}
	}
	cout<<dist1[k][n-1]<<'\n';
}
