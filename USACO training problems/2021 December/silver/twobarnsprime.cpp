#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5;
#define ll long long
vector<int> adjlist[MAXN];
vector<int> components[MAXN];
int comp[MAXN];
void dfs(int node, int group){
	comp[node] = group;
	for(int a : adjlist[node]){
		if(comp[a] == -1){
			dfs(a, group);
		}
	}
} 
ll cost(int a, int b) {
	int dist = MAXN;
	for (int u : components[a]) {
		/*
		 * Finds the closest field in bs' connected
		 * component to field u and updates the minimum
		 * distance. The closest field is found by binary
		 * searching on a sorted array (bs' connected 
		 * component).
		 */
		int i = lower_bound(components[b].begin(), components[b].end(), u) - components[b].begin(); //gives us the index of the value inside b that is the smallest value larger than the component. pointer math is whacky aah
		if (i > 0) { //if there is a largest-smaller-than-u component, we check that
			dist = min(dist, abs(components[b][i - 1] - u));
		}
		//then if there exists a smallest-larger-than-u value we check that
		if (i < components[b].size()) {
			dist = min(dist, abs(components[b][i] - u));
		}
	}
	/* 
	 * Returns the minimum cost of building a path 
	 * between the two components (aka dist^2)
	 */
	return (ll)dist * dist;
}
void solve(){
	int fields, edges;
	cin >> fields >> edges;
	//reset variables
	for(int r = 0; r < fields; r++){
		adjlist[r].clear();
		comp[r] = -1;
		components[r].clear();
	}
	//taking input
	for(int i = 0; i < edges; i++){
		int a, b;
		cin >> a >> b;
		adjlist[a-1].push_back(b-1);
		adjlist[b-1].push_back(a-1);
	}
	//creating connected components
	int cc = -1;
	for(int d = 0; d < fields; d++){
		if(comp[d] == -1){
			dfs(d, ++cc);
		}
	}
	for (int i = 0; i < fields; i++) {
		components[comp[i]].push_back(i);
	}
	ll ans = cost(comp[0], comp[fields-1]); //worse case scenario
	for(int c = 1; c < cc; c++){
		ans = min(ans, cost(c, comp[0]) + cost(c, comp[fields-1]));
	}
	cout<<ans<<'\n';
}
int main(){
	int cases;
	cin >> cases;
	for(int i = 0; i < cases; i++){
		solve();
	}
}
