#include <bits/stdc++.h>
//The big brain idea I had here was to have both a undirected and directed graph
//the undirected graph is used to find all the connected components in the graph
//the directed graph is then used to find cycles
//the basic premise of the problem is to find how many nodes are in a cycle, since they will always have cows
//I originally started just using Floyd's algorithm, incorrectly assuming there could only be one cycle
using namespace std;
const int MAXN = 1e5;
vector<int> adjlist[MAXN];
vector<int> dirG;
vector<int> startingPos;
int groups[MAXN] = {};
int ans = 0;
void dfs(int node, int cc){ //It's just finding CC's, nothing major
	groups[node] = cc;
	for(int a : adjlist[node]){
		if(groups[a] == 0){
			dfs(a,cc);
		}
	}
}
void floyd(int node){ //basic implementation of Floyd's Algo
	int p1 = node;
	int p2 = node;
	do{
		p1 = dirG[p1];
		p2 = dirG[dirG[p2]];
	}while(p1!=p2);
	p1 = node;
	while(p1 != p2){
		p1 = dirG[p1];
		p2 = dirG[p2];
	}
	int ta = 1;
	p2 = dirG[p2];
	while(p1!=p2){
		ta++;
		p2 = dirG[p2];
	}
	ans+=ta;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ifstream in("shuffle.in");
	ofstream out("shuffle.out");
	int cows;
	in >> cows;
	for(int i = 0; i < cows; i++){
		int a;
		in >> a;
		a--; //0 indexing
		adjlist[i].push_back(a);
		adjlist[a].push_back(i);
		dirG.push_back(a);
	}
	int group = 1;
	for(int j = 0; j < cows; j++){
		if(groups[j] == 0){
			startingPos.push_back(j); //Simplest way to store each CC
			dfs(j,group);
			group++;
		}
	}
	for(int s : startingPos){
		floyd(s);
	}
	out<<ans<<'\n';
}
