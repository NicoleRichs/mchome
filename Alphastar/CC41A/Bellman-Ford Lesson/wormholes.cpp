#include <bits/stdc++.h>
using namespace std;
const long long BIGNUM = 21474836470000;
struct path{
	int a, b, w;
};
void solve(){	
	vector<path> paths;
	long long adj[502];
	int n, m, w;
	cin >> n >> m >> w;
	for(int i = 1; i <= n; i++){
		adj[i] = BIGNUM;
	}	
	adj[1] = 0;
	for(int i = 0; i < m; i++){
		int from, to, weight;
		cin >> from >> to >> weight;
		path temp;
		temp.a = from;
		temp.b = to;
		temp.w = weight;
		paths.push_back(temp);
	}	
	for(int i = 0; i < w; i++){
		int from, to, weight;
		cin >> from >> to >> weight;
		path temp;
		weight *= -1;
		temp.a = from;
		temp.b = to;
		temp.w = weight;
		paths.push_back(temp);
	}
	
	bool cycle = false;
	for(int i = 1; i <= n-1; i++){
		for(int j = 0; j < (w + m); j++){
			if (adj[paths[j].a] != BIGNUM) {
                adj[paths[j].b] = min(adj[paths[j].b], adj[paths[j].a] + paths[j].w);
            }
		}
	}
	for(int j = 0; j < (w + m); j++){
		if (adj[paths[j].b] > adj[paths[j].a] + paths[j].w){
			cycle = true;
			break;
		}
	}
	
	if(cycle){
		cout<<"YES"<<'\n';
	}
	else{
		cout<<"NO"<<'\n';
	}
}
int main(){
	int farms;
	cin >> farms;
	for(int i = 0; i < farms; i++){
		solve();
	}
}
