#include <bits/stdc++.h>
using namespace std;
vector<int> adj[200000];
bool connected[200000] = {};
int n, m;
int rep[200000] ={};
int gsize[200000] = {};
void init(int k){
	for(int i = 0; i < k; i++){
		rep[i] = i;
		gsize[i] = 1;
	}
}
int getRep(int a){
	while(rep[a] != a){
		a = rep[a];
	}
	return a;
}
bool inCC(int a, int b){
	return getRep(a) == getRep(b);
}
int getSize(int a){
	return gsize[getRep(a)];
}
int unite(int a, int b){
	if(!inCC(a, b)){
		if(getSize(a) < getSize(b)){
			swap(a,b);
		}
		gsize[getRep(a)] +=gsize[getRep(b)];
		rep[getRep(b)] = getRep(a);
		return getRep(a);
	}
	return -1;
}
int main(){
	ifstream in("closing.in");
	ofstream out("closing.out");
//	cin >> n >> m;
	in >> n >> m;
	for(int i = 0; i < m; i++){
		int a, b;
//		cin >> a >> b;
		in >> a >> b;
		a--;b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	init(n);
	stack<int> tp;
	vector<int> answers;
	for(int x =0 ; x < n; x++){
		int a;
//		cin >> a;
		in >> a;
		a--;
		tp.push(a);
	}
	
	for(int i = 1; i <= n; i++){
		int cn = tp.top();
		tp.pop();
		connected[cn] = true;
		for(int a : adj[cn]){
			if(connected[a]){
				unite(cn, a);
			}
		}
		if(gsize[getRep(cn)] == i){
			answers.push_back(true);
		}
		else{
			answers.push_back(false);
		}
	}
	for(int a = n-1; a >= 0; a--){
		if(answers[a] == true){
//			cout<<"YES"<<'\n';
			out<<"YES"<<'\n';
		}
		else{
//			cout<<"NO"<<'\n';
			out<<"NO"<<'\n';
		}
	}
}

