#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> cc;
vector<int> myVec;
vector<bool> vis(1e5+2, false);
void dfs(int node, int ind){
	if(!vis[myVec[node]]){
		cc[ind].push_back(myVec[node]);
		vis[myVec[node]] =true;
		dfs(myVec[node], ind);
	}
	else{
		return;
	}
}
int main(){
	int n, k;
//	ifstream in("dancemooves.in");
	cin >> n >> k;
	vector<pair<int,int>> changes;
	vector<set<int>> visn(n+1);
	myVec.push_back(0);
	
	for(int i = 1; i <= n; i++){
		myVec.push_back(i);
		(visn[i]).insert(i);
	}
	for(int i = 0 ; i < k; i++){
		int a, b;
		cin >> a >> b;
		visn[myVec[a]].insert(b); //not myVec[b]. I am ridiculously retarded.
		visn[myVec[b]].insert(a);
		int t = myVec[a];
		myVec[a] = myVec[b];
		myVec[b] = t;
//		cout<<"!!"<<myVec[a]<<" "<<myVec[b]<<'\n';
	}
//	for(int i= 1; i <= n; i++){
//		cout<<myVec[i]<<" ";
//	}
//	cout<<'\n';
	int groups = 0;
	for(int i = 1; i <= n; i++){
		if(!(vis[i])){
			vis[i] = true;
			cc.push_back({i});
			dfs(i, groups);
			groups++;
		}
	}
//	for(vector<int> x : cc){
//		for(int a : x){
//			cout<<a<<" ";
//		}
//		cout<<'\n';
//	}
	vector<int> ans(n+1, 0);
	for(vector<int> a : cc){
		set<int> tn;
		for(int x : a){
			for(int c : visn[x]){
				if(tn.count(c) == 0){
					tn.insert(c);
//					cout<<c<<" ";
				}
			}
//			cout<<'|';	
		}
//		cout<<'\n';
		for(int x : a){
			ans[x] = tn.size();
		}
	}
	for(int i = 1; i <= n; i++){
		cout<<ans[i]<<'\n';
	}
}
