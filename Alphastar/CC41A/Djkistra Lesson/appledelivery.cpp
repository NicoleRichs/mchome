#include <bits/stdc++.h>
using namespace std;
vector<pair<int,int>> adj[100001];
int dists[100001];
int dist1[100001];
const int INF = 2147483647;
int main(){
	int c, p, pb, pa, pc;
	cin >> c >> p >> pb >> pa >> pc;
	int a, b, d;
	for(int i = 0; i < c ; i++){
		cin >> a >> b >> d;
		adj[a].push_back({b,d});
		adj[b].push_back({a,d});
	}
	for(int i = 0; i <= c; i++){
		dists[i] = INF;
		dist1[i] = INF;
	}
	dists[pb] = 0;
	dist1[pa] = 0;
	//dijkstra, distance from start
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > tp;
	tp.push({0,pb});
	int f = pb;
	while(!tp.empty()){
		f = (tp.top()).second;
		tp.pop();
		for(pair<int,int> a : adj[f]){
			if(dists[a.first] > dists[f] + a.second){
				dists[a.first] = dists[f] + a.second;
				tp.push({a.second, a.first});
			}
		}
	}
	tp.push({0,pa});
	while(!tp.empty()){
		f = (tp.top()).second;
		tp.pop();
		for(pair<int,int> a : adj[f]){
			if(dist1[a.first] > dist1[f] + a.second){
				dist1[a.first] = dist1[f] + a.second;
				tp.push({a.second, a.first});			
			}
		}
	}
	cout<<min(dists[pa] + dist1[pc], dists[pc] + dist1[pc])<<'\n';
}
