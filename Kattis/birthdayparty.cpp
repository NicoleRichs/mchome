#include <bits/stdc++.h>
using namespace std;
const int MAXP = 105;
//adjacency list, for easily removing edges
bool adj[MAXP][MAXP];
bool vis[MAXP];
int a, b;
void dfs(int node){
	vis[node] = true;
	for(int t = 0; t < a; t++){
		if(adj[node][t] && !vis[t]){
			dfs(t);
		}
	}
}
void run_case(){
	memset(adj, false, sizeof(adj)); //when you forgor to reset :skull: :skull:
	vector<pair<int,int>> edges; //to remember what edges do exist so we can iterate through and delete an edge
	for(int i = 0; i < b; i++){
		int x, y;
		cin >> x >> y;
		adj[x][y] = true;
		adj[y][x] = true;
		edges.push_back(make_pair(x,y));
	}
	for(pair<int,int> x : edges){
		//remove the edge
		adj[x.first][x.second] = false;
		adj[x.second][x.first] = false;
		memset(vis,false,sizeof(vis));//RESET THE VISITED LIST
		dfs(0);
		for(int i = 0; i < a; i++){
			if(!vis[i]){
				cout<<"Yes"<<endl;
				return;
			}
		}
		//reset the edge back into existence
		adj[x.first][x.second] = true;
		adj[x.second][x.first] = true;
	}
	cout<<"No"<<endl;
		return;
	
}
int main(){
	while(cin >> a >> b && (a || b)){
		run_case();
	}
}
