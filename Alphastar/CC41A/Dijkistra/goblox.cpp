#include <bits/stdc++.h>
using namespace std;
vector<pair<int,int>> adj[101];
vector<pair<long long,int>> dist(101);
const long long INF = 9223372036854775807;
int main(){
	int n, m;
	cin >> n >> m;
	int a, b, w;
	for(int i = 0; i < m; i++){
		cin >> a >> b >> w;
		adj[a].push_back({b,w});
		adj[b].push_back({a,w});
	}
	for(int i= 0; i <= n; i++){
		dist[i] = {INF, -1};
	}
	dist[1] = {0,0};
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> tp;
	tp.push({1,0}); //first is the node number, second is the source
	while(!tp.empty()){
		int n = (tp.top()).first;
		tp.pop();
		for(pair<int,int> a : adj[n]){
			if((dist[a.first]).first > (dist[n]).first + a.second){
				dist[a.first] = {(dist[n]).first + a.second, n};
				tp.push({a.first, n});
			}
		}
	}
//	for(int i = 1; i <= n; i++){
//		cout<<(dist[i]).first<<" "<<(dist[i]).second<<'\n';
//	}
	if((dist[n]).first == INF){
		cout<<0<<'\n';
	}
	else{
		long long orig = dist[n].first;
		int ml = 0;
		int md = 0;
		int ms = 0;
		int c = n;
		int s = (dist[n]).second;
		while(s!=0){
			if(ml < (dist[c]).first - (dist[s]).first){
				ml = (dist[c]).first - (dist[s]).first;
				md = s;
				ms = c;
			}
			c = s;
			s = (dist[c]).second;
		}
//		cout<<ml<<" "<<md<<" "<<ms<<'\n';
		pair<int,int> tr1 = {ms, ml};
		pair<int,int> tr2 = {md, ml};
		for(pair<int,int> &a : adj[md]){
			if(a.first == ms){
				a.second*=2;
				break;
			}
		}
		for(pair<int,int> &a : adj[ms]){
			if(a.first == md){
				a.second*=2;
				break;
			}
		}
		for(int i = 0; i <= n; i++){
			dist[i] = {INF, -1};
		}
		dist[1] = {0,0};
		tp.push({1,0}); //first is the node number, second is the source
		while(!tp.empty()){
			int n = (tp.top()).first;
			tp.pop();
			for(pair<int,int> a : adj[n]){
				if((dist[a.first]).first > (dist[n]).first + a.second){
					dist[a.first] = {(dist[n]).first + a.second, n};
					tp.push({a.first, n});
				}
			}
		}
		cout<<(dist[n].first) - orig<<'\n';
	}
}
