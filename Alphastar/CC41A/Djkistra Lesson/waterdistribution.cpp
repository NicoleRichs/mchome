#include <bits/stdc++.h>
using namespace std;
struct pipe{
	int dest, flow, cost;
};
vector<pipe> adj[1000];
const int INF = 2147483647;
int main(){
	int n, m;
	cin >> n >> m;
	//narrowing our range of flow rates to the lowest and highest
	int lf = 1000;
	int hf = 0;
	for(int i = 0; i < m; i++){
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		a--; b--; //zero indexing
		lf = min(lf, d);
		hf = max(hf, d);
		adj[a].push_back({b,d,c});		
		adj[b].push_back({a,d,c});
	}
	long long ans = 0;
	double dist[1000] = {};
	for(int i = hf; i >= lf; i--){
		//dijkstra for shortest path to n from 1, using only edges with flow rate >=i. Check the maximum flow rate and calculate flow rate / cost, multiplied by 1e6 and rounded down. Compare with ans.
		for(int i = 0; i < n; i++){
			dist[i] = INF;
		}
		dist[0] = 0;
		priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> tp;
		tp.push({0, 0});
		double lf = 1000;
		while(!tp.empty()){
			int cn = (tp.top()).second;
			tp.pop();
			for(pipe &a : adj[cn]){
				if(a.flow >= i){
					if(dist[a.dest] > dist[cn] + a.cost){
//						cout<<"hello"<<'\n';
						lf = min(hf, a.flow); 
						dist[a.dest] = dist[cn] + a.cost;
						tp.push({a.cost, a.dest});
					} 
				}
			}
		}
//		cout<<lf<<'\n'<<" "<<dist[n-1]<<'\n';
		if(dist[n-1] != INF){
			long double top = 1e6 * i; //not sure why it isn't 1e6 * lf. Maybe the datasets were bad, but it does pass the test cases. Whack.
			long double bottom = 1e6 * dist[n-1];
			long double ra = top / bottom;
			long long ca = ra * 1e6; 
	//		cout<<ca<<'\n';
			ans = max(ans, ca);
		}
		
	}
	cout<<ans<<'\n';
}
