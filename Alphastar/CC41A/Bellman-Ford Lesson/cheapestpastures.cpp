#include <bits/stdc++.h>
using namespace std;
int n, m;
const int BIGNUM = 2147483647;
int adj[10001] = {};
struct edge{
	int u, v;
	int weight;
};
vector<edge> edges;
int main(){
	cin >> n >> m;
	for(int a = 0; a <= n; a++){
		adj[a] = BIGNUM;
	}
	for(int i = 0; i < m; i++){
		int a, b, c;
		cin >> a >> b >> c;
		edge temp;
		temp.u = a;
		temp.v = b;
		temp.weight = c;
		edges.push_back(temp);
	}
	adj[1] = 0;
	for(int r = 0; r < n-1; r++){
		for(int i = 0; i < m; i++){
			int u = (edges[i]).u;
			int v = (edges[i]).v;
			int c = (edges[i]).weight;
			if(adj[u]!=BIGNUM){
				if(adj[u] + c < adj[v]){
					adj[v] = adj[u] + c;
				}
			}
		}
	}
	for(int i = 0; i < m; i++){
		int u = edges[i].u;
		int v = edges[i].v;
		int c = edges[i].weight;
		if(adj[u]!=BIGNUM){
			if(adj[u] + c < adj[v]){
				cout<<"moo"<<endl;
				return 0;
			}
		}	
	}
	for(int i = 1; i <= n; i++){
		cout<<adj[i]<<'\n';
	}
}
