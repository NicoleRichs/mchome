#include <bits/stdc++.h>
using namespace std;
vector<pair<int,int>> adj[100000];
int main(){
	int n, m;
	cin >> n >> m;
	for(int i= 0; i < m; i++){
		int a, b, c;
		cin >> a >> b>> c;
		adj[a-1].push_back({b-1,c});
		adj[b-1].push_back({a-1,c});
	}
	priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> tp;
	vector<pair<int,int>> dts(n);
	for(int i = 0; i < n; i++){
		dts[i] = {-1,-1};
	}
	dts[0] = {0,-1};
	tp.push({0,0});
	for(int i = 0; i < n; i++){
		sort(adj[i].begin(),adj[i].end());
	}
	while(!tp.empty()){
		int cn = (tp.top()).second;
		int cd = dts[cn].first;
//		cout<<cn<<" "<<cd<<'\n';
		tp.pop();
		for(pair<int,int> a :adj[cn]){
//			cout<<a.first<<" "<<a.second<<'\n';
			if(dts[a.first].first == -1 || dts[a.first].first > cd + a.second){
				dts[a.first].first = cd + a.second;
				dts[a.first].second = cn;
				tp.push({a.second, a.first});
			}
		}
	}
	vector<int> pn;
	int cn = n-1;
	while(cn != -1){
		pn.push_back(cn);
		cn = dts[cn].second;
	}
	sort(pn.begin(),pn.end());
	for(int a : pn){
		cout<<a+1<<" ";
	}
	cout<<endl;
}
