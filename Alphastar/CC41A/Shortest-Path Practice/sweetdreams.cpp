//1145 PST, 07/17/2023
#include <bits/stdc++.h>
using namespace std;
const int BIGNUM = 2147483647;
//idea here:
/**
1. To get the normal shortest paths, just run a dijikstra from n-1 to all nodes
2. create an artificial node, n. Create directed (from n) edges to all donut nodes. The weight of each edge represents the shortest path from that node to n, subtracting the enjoyment of the donuts. 
3. Now we dijikstra from the new node and find the new distance to each node. If it is less than previous answer, output yes.
**/
int main(){
	int n, m, k;
	cin >> n >> m >> k;
	//had to convert these to all vectors on the alphastar submissions because their compiler doesn't like dis
	
	vector<pair<int,int>> adj[n+2]; //adjacency list
	
	int dists[n+1] = {}; //distance from node n-1
	
	int nd[n+1] = {}; //from node n
	
	vector<pair<int,int>> dn; //list of donut nodes and the enjoyment values
	
	//input for edges
	for(int i= 0; i < m; i++){
		int a, b, c;
		cin >> a >> b >> c;
		a--;b--;
		adj[a].push_back({b,c});
		adj[b].push_back({a,c});
	}
	//input for donut vertices
	for(int j = 0; j < k; j++){
		int a, b;
		cin >> a >> b;
		a--;
		dn.push_back({a,b});
	}
	//initialize all distances to beeg numbah
	for(int i=  0; i < n; i++){
		dists[i] = BIGNUM;
		nd[i] = BIGNUM;
	}
	
	dists[n-1] = 0;
	nd[n] = 0;
	priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> tp;
	tp.push({0,n-1});
	//standard dijikstra
	while(!tp.empty()){
		int cn = (tp.top()).second;
		int cw = (tp.top()).first;
		tp.pop();
		for(pair<int,int> a : adj[cn]){
			if(dists[a.first] > cw + a.second){
				dists[a.first] = cw + a.second;
				tp.push({dists[a.first], a.first});
			}
		}
	}
	//creating the artificial edges
	for(pair<int,int> d : dn){
		int nd = dists[d.first] - d.second; //adjusted distance from each donut edge to n-1 accouting for their donuts
		adj[n].push_back({d.first, nd});
	}
	tp.push({0, n});
	nd[n] = 0;
	while(!tp.empty()){ //literally a copy and paste of above, just swapped out updating dists with nd
		int cn = (tp.top()).second;
		int cw = (tp.top()).first;
		tp.pop();
		for(pair<int,int> a : adj[cn]){
			if(nd[a.first] > cw + a.second){
				nd[a.first] = cw + a.second;
				tp.push({nd[a.first], a.first});
			}
		}
	}
	//checking if we've improved distances
	for(int i= 0; i < n-1; i++){
		cout<<(nd[i] <= dists[i])<<'\n'; //i feel very proud of this ultra-efficient line
	}
}
