#include <bits/stdc++.h>
using namespace std;
const int INF = 2e9;
int retCost(int x1, int y1, int x2, int y2){
	return (((x1-x2) * (x1-x2)) + ((y1-y2)*(y1-y2)));
}	
int cn = 0;
int ca = 0;
//literal pain
int main(){
	int n, c;
	cin >> n >> c;
	vector<pair<int,int>> points;
	for(int i = 0; i < n; i++){
		int a, b;
		cin >> a >> b;
		points.push_back({a,b});
	}
	//the idea here is to just take advantage of our low limits for N (2000) and create an adjacency matrix of every single point. That means N^2 relations, or 4 * 1e6 which is fine.
	vector<vector<int>> adj(2000, vector<int> (2000, INF));
	for(int i = 0; i < n; i++){
		adj[i][i] = 0;
	}
	for(int i = 0; i < n; i++){
		for(int j = i+1; j < n; j++){
			int cc = retCost(points[i].first, points[i].second, points[j].first, points[j].second); //we only show the edge if the cost is at least c
//			cout<<cc<<" "<<i<<" "<<j<<'\n';
			if(cc >= c){
				adj[i][j] = cc;
				adj[j][i] = cc;
			}
		}
	}

	vector<bool> vis(2000,false);
	vector<int> dists(2000, INF);
	dists[0] = 0;
	for(int i = 0; i < n-1; i++){
		vis[cn] = true;
		//relaxing distances of edges to the MST
		for(int j = 0; j < n; j++){
			if(!vis[j]){
				if((dists[j] > adj[cn][j])){
					dists[j] = adj[cn][j];
				}
			}
		}
		//finding the new closest node not in the MST
		cn = -1; //the current closest node
		int cd = INF-1; //how close the current closest is
		for(int k = 0; k < n; k++){
			if(!vis[k]){
				if(dists[k] < cd && k!=cn){
//					cout<<"PASS"<<'\n';
					cn = k;
					cd = dists[k];
				}
			}
		}
		if(cn == -1){ //if we cannot create a MST (no unincorporated node found, with still iterations to go)
			ca = -1;
			break;
		}
//		cout<<"NEXT NODE/DIST: "<<cn<<" "<<ca<<'\n';
	}
	if(ca !=-1){
		for(int i = 0; i < n; i++){
			ca+=dists[i]; //sum all the distances
		}
	}
	cout<<ca<<'\n';
}
