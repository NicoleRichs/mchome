#include <bits/stdc++.h>
//the idea: We can represent this as a directional graph, a node will lead to another if the cow prefers that gift over its own. If a node is part of a cycle, then all cows in the cycle can shift their gifts by one and get an upgrade. We basically DFS for each node to see which nodes it can visit, and then we check for each node
//in order of its preference list if it is reachable from one of its desired nodes. If so, it is in a cycle with that node and thus we can redistrubite it.
using namespace std;
bool vis[501][501] = {};
vector<int> pref[501];
void dfs(int orig, int cur){
	vis[orig][cur] = true;
	for(int a : pref[cur]){
		if(!vis[orig][a]){
			dfs(orig, a);	
		}
	}
}
int main(){
	int n;
	cin >> n;
	for(int i = 1; i < n+1; i++){
		for(int j = 0; j < n; j++){
			int b; 
			cin >> b;
			pref[i].push_back(b);
		}
		while(pref[i].back()!=i){
			pref[i].pop_back();
		}
	}
	for(int i = 1; i <= n; i++){
		dfs(i, i);
	}
	for(int j = 1; j <= n; j++){
		for(int g : pref[j]){
			if(vis[g][j]){
				cout<<g<<'\n';
				break;
			}
		}
	}
}
