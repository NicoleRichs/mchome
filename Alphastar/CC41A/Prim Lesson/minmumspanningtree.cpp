#include <bits/stdc++.h>
using namespace std;
//stayin hungry and greedy on the edge
//its about drive its about power
//we stay hungry we devour
//put in the work put in the hours
//and take what's ours
//a favorite quotation of Daniel Chai, NHS classmate and comrade
int main(){
	vector<pair<int,int>> edges[50001];
	int v, e;
	cin >> v >> e;
	for(int i= 0; i < e; i++){
		int a, b, c;
		cin >> a >> b >> c;
		edges[a].push_back({c,b});
		edges[b].push_back({c,a});
	}
	int ans = 0;
	vector<bool> vis(v, false);
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> tp;
	tp.push({0,1});
	while(!tp.empty()){
		int cn = (tp.top()).second;
		int cw = (tp.top()).first;
		tp.pop();
		if(vis[cn]){
			continue;
		}
		ans+=cw;
		vis[cn] = true;
		for(pair<int,int> &p : edges[cn]){
			if(!vis[p.second]){
				tp.push({p.first, p.second});
			}
		}
	}
	cout<<ans<<'\n';
}
