#include <bits/stdc++.h>
using namespace std;
/*
Honestly whack problem. The one and only observation here is that if you permute the portals so p1 and p3 are together and p2 and p4 are together, p1 and p2 are still in the same cc and same with p3 and p4. 
I basically guessed this since there was nothing else that came to mind. The official analysis doesn't really elaborate either. Honestly my brain still hertz
Implementation wise the only thing different is that we treat each portal as a node. Not much else.
*/
vector<int> rep(200000);
vector<int> sizes(200000);
int getRep(int a){
	if(rep[rep[a]] != rep[a]){
		rep[a] = getRep(rep[a]);
	}
	return rep[a];
}
void merge(int a, int b){
	a = getRep(a); b= getRep(b);
	if(a!=b){
		if(sizes[a] < sizes[b]){
			swap(a,b);
		}
		if(sizes[a] == sizes[b]){
			sizes[a]++;
		}
		rep[b] = a;
	}
}
void init(int v){
	for(int i = 0; i < 2*v; i++){
		rep[i] = i;
		sizes[i] = 1;
	}
}
struct edge{
	int a; 
	int b;
	int c;
};
bool cmp2(edge e1, edge e2){
	return e1.c < e2.c;
}
int main(){
	int n;
	cin >> n;
	init(n);
	vector<edge> edges;
	vector<vector<int>> raw(n,vector<int>(5));
	for(int i = 0; i < n; i++){
		int q, w, e, r, t;
		cin >> q >> w >> e >> r >> t;
		raw[i] = {q,w,e,r,t};
		edges.push_back({w,e,0});
		edges.push_back({r,t,0});
		edges.push_back({t,w,q});
	}
	sort(edges.begin(),edges.end(),cmp2);
	long long cost = 0;
	for(edge e : edges){
//		cout<<"pass"<<e.a<<" "<<e.b<<" "<<e.c<<'\n';
//		cout<<getRep(e.a)<<'\n';
		if(getRep(e.a)!=getRep(e.b)){
//			cout<<"time to merge"<<'\n';
			merge(e.a,e.b);
//			cout<<"merge success"<<'\n';
			cost+=e.c;
		}
	}
	cout<<cost<<'\n';
}
