#include <bits/stdc++.h>
using namespace std;
vector<pair<int,int>> cowlist;
vector<int> rep(100000);
vector<int> sizes(100000, 1);
struct edge{
	int a, b;
	long long c;
};
bool cmp3(edge &e1, edge &e2){
	return e1.c < e2.c;
}
long long getDist(int a, int b){
	long long x1 = cowlist[a].first;
	long long x2 = cowlist[b].first;
	long long y2 = cowlist[b].second;
	long long y1 = cowlist[a].second;
	return ((x1 - x2)* (x1 - x2)) + ((y1 - y2)*(y1 - y2));
}
int getRep(int a){
	if(rep[a]!=rep[rep[a]]){
		rep[a] = getRep(rep[a]);
	}
	return rep[a];
}
void unite(int a, int b){
	a = getRep(a); b =getRep(b);
	if(a!=b){
		if(sizes[a]<sizes[b]){
			swap(a,b);
		}
		sizes[a]+=sizes[b];
		rep[b]=a;
	}
}
void init(int n){
	for(int i=  0; i < n; i++){
		rep[i] = i;
		sizes[i] = 1;
	}
}
int main(){
	int cows;
	cin >> cows;
	cowlist.resize(cows);
	rep.resize(cows);
	sizes.resize(cows);
	init(cows);
	for(int i = 0; i < cows; i++){
		int x, y;
		cin >> x >> y;
		cowlist[i] = {x,y};
	}
	sort(cowlist.begin(),cowlist.end());
	vector<int> highestEdges(11, -1);
	vector<edge> edges;
//	cout<<"________________________"<<'\n';
//	for(pair<int,int> a : cowlist){
//		cout<<a.first<<" "<<a.second<<'\n';
//	}
//	cout<<"________________________"<<'\n';
	/*
	We sweepline through our farm, only adding edges from each cow to the closest cow from each y-coordinate since there's only 11. This cuts down our edge count significantly.
	*/
	for(int j = 0; j < cows; j++){
		pair<int,int> a = cowlist[j];
		for(int i = 0; i < 11; i++){
				if(highestEdges[i]!=-1){
//					cout<<j<<" "<<highestEdges[i]<<" "<<i<<'\n';
					edges.push_back({j, highestEdges[i], getDist(j,highestEdges[i])});
				}
			
		
//				cout<<j<<" "<<i<<'\n';
		}
//		cout<<"_______________________"<<'\n';
		highestEdges[a.second] = j;
	}
	sort(edges.begin(), edges.end(), cmp3);
	long long cost = 0ll;
	for(int f = 0; f < edges.size(); f++){
		int x = edges[f].a;
		int y = edges[f].b;
		long long ccost =edges[f].c;
		if(getRep(x)!=getRep(y)){
			unite(x,y);
			cost+=ccost;
		}
	}
	cout<<cost<<'\n';
}
