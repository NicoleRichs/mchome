#include <bits/stdc++.h>
using namespace std;
int n, b;
vector<int> depth;
vector<pair<int,int>> boots;
bool vis[251][251] = {};
int min_ans = 250;
//HRNNNG I'M FLOODFILLING AGHHHHHH HNGGGG
void ff(int boot, int tile){
	if(vis[boot][tile]){
		return;
	}
	vis[boot][tile] = true;
	if(tile == n-1){
		min_ans = min(min_ans, boot);
		return;
	}
	
	//possible steps
	for(int i = 1; i <= boots[boot].second && tile+i < n; i++){
		if(boots[boot].first >= depth[tile+i]){
			ff(boot, tile+i);	
		}
	}
	//possible swaps
	for(int j = boot+1; j < b; j++){
		if(boots[j].first >= depth[tile]){
			ff(j, tile);
		}
	}
}
int main(){
	ifstream in("snowboots.in");
	ofstream out("snowboots.out");
	in >> n >> b;
	for(int i = 0; i < n; i++){
		int a;
		in >> a;
		depth.push_back(a);
	}
	for(int j = 0; j < b; j++){
		int b, c;
		in >> b >> c;
		boots.push_back(make_pair(b,c));
	}
	ff(0,0);
	out<<min_ans<<'\n';
}
