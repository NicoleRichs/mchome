#include <bits/stdc++.h>
using namespace std;
vector<int> edges[2501];
int n = 0;
int h[2501] = {};
int s1 = 0, s2 = 0, n1 = 0, n2 = 0;
void dfs(int node, int parent, int group){
	int cg = 0;
	if(group == 1){
		cg = 2;
		s1+=h[node];
		n1++;
	}
	else if(group == 2){
		cg = 1;
		s2+=h[node];
		n2++;
	}
	for(int child : edges[node]){
		if(child!=parent){
			dfs(child, node, cg);
		}
	}
}
int main(){
	ifstream in("clocktree.in");
	ofstream out("clocktree.out");
	in >> n;
	for(int i = 1; i <= n; i++){
		in >> h[i];
	}
	for(int i = 0; i < n-1; i++){
		int a, b;
		in >> a >> b;
		edges[a].push_back(b);
		edges[b].push_back(a);
	}
	dfs(1,-1,1);
	if(s1%12 == s2%12){
		out<<n<<'\n';
	}
	else if(s1%12 == (s2+1)%12){
		out<<n1<<'\n';
	}
	else if((s1+1)%12 == s2%12){
		out<<n2<<'\n';
	}
	else{
		out<<0<<'\n';
	}
	
}
