#include <bits/stdc++.h>
using namespace std;
const int MAXC = 1e5+5;
vector<bool> visited(MAXC+5);
vector<int> adj[MAXC+5][2]; //the first index is the city number, the second is the reachable from list (0) or the reachable from list(1), the third is the list of cities reachable from/to.
void dfs(int node, int tr){
	visited[node] = true;
	for(int a : adj[node][tr]){
		if(!visited[a]){
			dfs(a,tr);
		}
	}
}
int main(){
	int cities, flights;
	cin >> cities >> flights;
	for(int i = 0; i < flights; i++){
		int a, b;
		cin >> a >> b;
		a --; b--; //zero indexing
		adj[a][0].push_back(b); //a can reach b
		adj[b][1].push_back(a); //b is reachable from a
	}
	dfs(0,0); //we dfs to see if all places can reach all other places
	for(int i = 0; i < cities; i++){
		if(!visited[i]){
			cout<<"NO"<<endl;
			cout<<1<<" "<<i+1<<endl;
			return 0;
		}
	}
	fill(visited.begin(),visited.end(), false);
	dfs(0,1); //then if all places can be reached
	for(int i = 0; i < cities; i++){
		if(!visited[i]){
			cout<<"NO"<<endl;
			cout<<i+1<<" "<<1<<endl;
			return 0;
		}
	}
	//crabby
	cout<<"YES"<<endl;	
}
