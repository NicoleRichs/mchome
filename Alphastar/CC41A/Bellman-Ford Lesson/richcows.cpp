#include <bits/stdc++.h>
using namespace std;
long long adj[10001] = {};
bool cycle[10001] = {};
vector<vector<int>> cc;
vector<int> adjl[10001];
bool vis[10001] = {};
const long long BIGNUM = 9223372036854775807;
struct edge{
	int a, b, w;
};
vector<edge> paths;
void dfs(int node){ //standard enough DFS, just with the added operation of flagging the visited node as an infinity node.
	vis[node] = true;
	cycle[node] = true;
	for(int a : adjl[node]){
		if(!vis[a]){
			dfs(a);
		}
	}
}
//the key for this problem: We want to detect negative cycles, but we also realize that any node whose path from node 1 can go through a cycle node is also infinite money (you can go around the cycle forever then get to the destination). 
//My solution was to DFS the connected component with the source at the found cycle node and flagging all those DFS'd as infinite nodes. 
//A previous incorrect solution was to create CC's immediately with 1 as the source, but that is flawed as it doesn't represent the nodes that actually have a path from 1 to the cycle node to the node itself.
int main(){
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int from, to, weight;
		cin >> from >> to >> weight;
		edge temp;
		temp.a = from;
		temp.b = to;
		temp.w = weight;
		paths.push_back(temp);
		adjl[from].push_back(to);
	}
	for(int i = 1; i <= n; i++){ //for some reason if we remove this windows gets mad. Don't ask me, ask gill bates, the MacroHard CEO.
		for(int a : adjl[i]){
			break;
		}
	}
	for(int i = 1; i <= n; i++){ //initialization
		adj[i] = BIGNUM;
		cycle[i] = false;
		vis[i] = false;
	}
	int cur = 0;
	adj[1] = 0;
	for(int i = 0; i < n-1; i++){ //standard Bellman-Ford
		for(int j = 0; j < m; j++){
			int from = paths[j].a;
			int to = paths[j].b;
			int weight = paths[j].w;
			if(adj[from] != BIGNUM){
				if(adj[to] > adj[from] + weight){
					adj[to] = adj[from] + weight;
				}		
			}
		}
	}
	for(int j = 0; j < m; j++){ //cycle detection
		int from = paths[j].a;
		int to = paths[j].b;
		int weight = paths[j].w;
		if(adj[to] > adj[from] + weight){
			cycle[to] = true; //could work without this line but eh
			dfs(from);	//the sekrit sos
		}
	}
	for(int i = 1; i <= n; i++){
		if(!cycle[i]){
			cout<<adj[i]<<'\n';
		}
		else{
			cout<<"moo"<<'\n';
		}
	}
}
