#include <bits/stdc++.h>
using namespace std;
/**
The problem essentially asks for the maximum edge weight in a minimum spanning tree of all the cows, with the special condition of the edge weights being the distance, squared. 
Possibly for the convenience of not needing to square-root distances when calculating them with Pythagorean Theorem.
Using Kruskal, if we have N^2 edges, we use the C++ built-in sort for N^2 lg(N^2) which should work since N = 1e3.
Everything else in Kruskal should run in much less time so that's our complexity. I honestly think there's a better way to do this (Prim my beloved) but oh well rip
**/

struct edge{ //stores the index of the 2 nodes, and the cost for them to talk.
	int a, b, cost;
};

bool mycmp(edge e1,edge e2){ //sort by cost
	return e1.cost < e2.cost;
}

vector<pair<int,int>> cowloc; //stores the 2-d coordinates of each cow. cow a has coords at cowloc[a].

vector<int> rep(1000); //stores the representative node of each cow.

vector<int> sizes(1000, 1); //stores sizes of each head.

int find(int a){ //compresses our tree
	if(rep[a]!= a){
		rep[a] = find(rep[a]);
	}
	return rep[a];
}

void merge(int a, int b){ //does exactly what it says
	a = find(a); b= find(b);
	if(a == b){
		return;
	}
	if(sizes[a] < sizes[b]){
		swap(a,b);
	}
	else if(sizes[a] == sizes[b]){ //tree increases in height since they're the same height
		sizes[a]++;
	}
	rep[b] = a;
	
}

void init(int t){
	for(int i = 0; i < t; i++){
		rep[i] = i;
	}
}

int retLoc(int a, int b){ //gives squared distance between the cows.
	int x1 = cowloc[a].first;
	int y1 = cowloc[a].second;
	int x2 = cowloc[b].first;
	int y2 = cowloc[b].second;
	x1-=x2;y1-=y2;
	return (x1 * x1 )+ (y1 * y1);
}

vector<edge> edges;
int main(){
	int n;
	cin >> n;
	init(n);
	
	for(int i = 0; i < n; i++){
		int a, b;
		cin >> a >> b;
		cowloc.push_back({a,b});
	}
	
	for(int i = 0; i < n; i++){ //n^2 go BRRRRRRRRRRRRRRRRRRRRRRRRRRR
		for(int j = i+1; j < n; j++){
			edges.push_back({i, j, retLoc(i,j)});
		}
	}
	
	sort(edges.begin(),edges.end(),mycmp); //literally the most computationally expensive thing here. Ouch.
	int maxMin = 0;
	for(edge e : edges){
//		cout<<rep[0]<<" "<<rep[1]<<" "<<rep[2]<<" "<<rep[3]<<'\n';
		if(find(e.a) != find(e.b)){ //if we can actually merge the two trees
			merge(e.a, e.b); //merge trees
			maxMin = max(maxMin, e.cost); //compare if the edge added is the largest so far
//			cout<<e.a<<" "<<e.b<<" "<<e.cost<<'\n';
		}
	}
	cout<<maxMin<<'\n';
}
