#include <bits/stdc++.h>
using namespace std;
int dist[50000] = {};
const int INF = 2147483647;
vector<pair<int,int>> adj[50000];
int main(){
	int v, e, s;
	cin >> v  >> e >> s;
	for(int i = 0; i < v; i++){
		dist[i] = INF;
	}
	dist[s-1] = 0;
	for(int i = 0; i < e; i++){
		int a, b, c;
		cin >> a >> b >> c;
		adj[a-1].push_back(make_pair(b-1,c));
		adj[b-1].push_back(make_pair(a-1,c));
	}
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > tp;
	tp.push({0,s-1});
	while(!tp.empty()){
		int c = (tp.top()).first;
		int n = (tp.top()).second;
		tp.pop();
		for(pair<int,int> a : adj[n]){
			if(dist[a.first] > dist[n] + a.second){
				dist[a.first] = dist[n] + a.second;
				tp.push({n, a.first});
			}
		}
	}
	for(int i = 0; i < v; i++){
		if(dist[i] == INF){
			cout<<-1<<'\n';
		}
		else{
			cout<<dist[i]<<'\n';			
		}
	}
}
