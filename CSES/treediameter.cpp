#include <bits/stdc++.h>
using namespace std;
const int MAXN = 2 * 1e5;
vector<int> adjlist[MAXN];
bool vis[MAXN] = {};
bool vis2[MAXN] = {};
int fn = 1;
int dist = 0;
int sn = -1;
int rad = 0;
void dfs1(int node, int cd){
	vis[node] = true;
	if(cd > dist){
		dist = cd;
		fn = node;
	}
	for(int n : adjlist[node]){
		if(!vis[n]){
			dfs1(n, cd+1);
		}
	}
}
void dfs2(int node, int cd){
	vis2[node] = true;
	if(cd > rad){
		rad = cd;
	}
	for(int n : adjlist[node]){
		if(!vis2[n]){
			dfs2(n, cd+1);
		}
	}
}
int main(){
	int nodes;
	cin >> nodes;
	for(int i = 1; i < nodes; i++){
		int a, b;
		cin>>a>>b;
		a--;
		b--;
		adjlist[a].push_back(b);
		adjlist[b].push_back(a);
	}
	dfs1(0,dist);
	dfs2(fn, rad);
	cout<<rad<<'\n';
}
