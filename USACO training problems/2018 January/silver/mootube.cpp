#include <bits/stdc++.h>
using namespace std;
const int MAXN = 5000;
vector<pair<int,int>> adjl[MAXN];
vector<bool> vis;
int cows = 0;
int rel = 0;
int ans = 0;
int threshold = 0;
void find_rel(int node){
	vis[node] = true;
	for(pair<int,int> &p : adjl[node]){
		if(!vis[p.first] && p.second >= threshold){
			ans++;
			find_rel(p.first);
		}
	}
}
int main(){
	ifstream in("mootube.in");
	ofstream out("mootube.out");
	in >> cows >> rel;
	for(int i = 0; i < cows-1; i++){
		int a, b, r;
		in >> a >> b >> r;
		a--;
		b--;
		adjl[a].push_back({b,r});
		adjl[b].push_back({a,r});
		
	}
	vis.resize(cows);
	for(int j = 0; j < rel; j++){
		threshold = 0;
		ans = 0;
		vis = vector<bool>(cows);
		int cs;
		in >> threshold >> cs;
		cs--;
		find_rel(cs);
		out<<ans<<'\n';
	}
}
