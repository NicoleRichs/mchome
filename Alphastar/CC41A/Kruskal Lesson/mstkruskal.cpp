#include <bits/stdc++.h>
using namespace std;
struct edge{
	int a, b, c;
};
bool cmp1(edge x, edge y){
	return x.c < y.c;
}
vector<int> rep(50000);
vector<int> sizes(50000, 1);
int getRep(int a){ //compresses our tree
	if(rep[a]!= a){
		rep[a] = getRep(rep[a]);
	}
	return rep[a];
}
void merge(int a, int b){
	a = getRep(a); b = getRep(b);
	if(a != b){
		
		if(sizes[a] < sizes[b]){
			swap(a,b);
		}
		
		if(sizes[a] == sizes[b]){
			sizes[a]++;
		}
		
		rep[b] = a;
	}
}
void init(int n){
	for(int a = 0; a < n; a++){
		rep[a] = a;
	}
}
int main(){
	int v; int e;
	cin >> v >> e;
	init(v);
	vector<edge> edges;
	for(int i = 0; i < e; i++){
		int a, b, c;
		cin >> a >> b >> c;
		edges.push_back({a,b,c});
	}
	sort(edges.begin(),edges.end(),cmp1);
	long long cost = 0ll;
	for(int i = 0; i < e; i++){
		int a = edges[i].a;
		int b = edges[i].b;
		int c = edges[i].c;
		if(getRep(a)!=getRep(b)){
			merge(a, b);
			cost+=c;
		}
//		cout<<"hello!"<<'\n';
	}
	cout<<cost<<'\n';
}
