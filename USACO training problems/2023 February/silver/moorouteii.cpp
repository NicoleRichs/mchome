#include <bits/stdc++.h>
using namespace std;
struct route{
	int leave, dest, arr;
};
long long cp = 0ll;
const int MAXN = 2e5;
int arrivals[MAXN] = {};
int layovers[MAXN] = {};
vector<route> adjl[MAXN];
void dfs(int node, int time){
	cout<<"visted "<<node<<" "<<cp++<<'\n';
	if(arrivals[node]!=-1){
		arrivals[node] = min(arrivals[node], time);
	}
	else{
		arrivals[node] = time;
	}
	for(route &a : adjl[node]){
		if(a.leave >= time && a.leave != -1){
//			cout<<"Leaving "<<node<<" To "<<a.dest<<" at "<<a.leave<<'\n';
			a.leave = -1;
			dfs(a.dest, a.arr + layovers[a.dest]);
		}
	}
}
int main(){
	//the idea: dfs from airport 1. Once we use an edge, delete it since we would arrive there at the same time again and thus it wouldn't have any benefit. 
	//Store the most recent time in the array. We'll still take less than optimal paths (if a flight from a to b will arrive at b at time c, and another from c to b at time d > c, we still take d to c.
	ifstream in("moorouteii.in");
	ofstream out("moorouteii.out");
	int n, m;
	in >> n >> m;
	fill_n(arrivals, n, -1);
	for(int i = 0; i < m; i++){
		int a, b, t, l;
		in >> a >> b >> t >> l;
		a--; t--;
		adjl[a].push_back({b, t, l});
	}
	for(int k = 0; k < n; k++){
		in >> layovers[k];
	}
	dfs(0,0);
	cout<<"Processing confirm"<<'\n';
	out<<0<<'\n';
	for(int a = 1; a < n; a++){
		if(arrivals[a] != -1){
			out<<arrivals[a] - layovers[a]<<'\n';	
		}
		else{
			out<<-1<<'\n';
		}
	}
}
