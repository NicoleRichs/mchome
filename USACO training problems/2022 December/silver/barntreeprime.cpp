#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n;
const int MAXN = (1e5 * 2 )+5;
vector<int> adjlist[MAXN];
ll moves, target = 0;
ll needed[MAXN] = {0l};
struct movestruct{
	int f, t;
	ll m;
};
vector<movestruct> movearr;
void dfs(int node, int parent){
	for(int child : adjlist[node]){
		if(child!=parent){
			dfs(child, node);
			if(needed[child]!=0){
				moves+=1;
			}
			needed[node]+=needed[child];
		}
	}	
}
void genmoves(int node, int parent){
	for(int child : adjlist[node]){
		if(child != parent){
			if(needed[child] >= 0){
				genmoves(child, node);
			}
			if(needed[child] > 0){
				movearr.push_back({child, node, needed[child]});
			}	
		}
		
	}
	for(int child : adjlist[node]){
		if(child != parent){
			if(needed[child] < 0){
				movearr.push_back({node, child, -1 * needed[child]});
				genmoves(child, node);
			}
		}
	}
}
int main(){
	ifstream in("barntree.in");
	ofstream out("barntree.out");
	//those were here for testing. of course i forget to return in to cin. fml. AND i even selected the wrong file :skull:
	cin >> n;
	long long sum = 0l; //i forgor to: 1. make it a ll 2. INITIALIZE TO 0 AAHHH
	for(int i = 1; i <= n; i++){
		int a;
		cin >> a;
		needed[i] = a;
		sum+=a;
	}
	target = (sum/n);
	for(int i = 1; i <= n; i++){
		needed[i] -= target;
	}
	for(int j = 0; j < n-1; j++){
		int a, b;
		cin >> a >> b;
		adjlist[a].push_back(b);
		adjlist[b].push_back(a);
	}
	dfs(1,1);
	genmoves(1, 1);
	cout<<moves<<'\n';
	for(movestruct m : movearr){
		cout<<m.f<<" "<<m.t<<" "<<m.m<<'\n';
	}
}
