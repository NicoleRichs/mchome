#include <bits/stdc++.h>
using namespace std;
int n, k, r;
vector<vector<vector<int>>> blocked(101, vector<vector<int>>(101, vector<int>(4, 1))); //0 = north. 1 = south. 2 = east. 3 = west. The naming is bad, if blocked[x][y][a] is 1, we can go there.
vector<vector<int>> cl(101, vector<int>(101, -1));
vector<pair<int,int>> cowList;
vector<vector<bool>> vis(101, vector<bool>(101, false));
vector<vector<bool>> reachable(101, vector<bool>(101, false));
void dfs(int x, int y){
	vis[x][y] = true;
	if(y < n){
		if(blocked[x][y][0] && !vis[x][y+1]){
			dfs(x, y+1);
		}
	}
	if(y > 1){ //this being >0 totally fucked me over for 30 minutes
		if(blocked[x][y][1] && !vis[x][y-1]){
			dfs(x, y-1);
		}
	}
	if(x < n){
		if(blocked[x][y][2] && !vis[x+1][y]){
			dfs(x+1, y);
		}
	}
	if(x > 1){ //same here
		if(blocked[x][y][3] && !vis[x-1][y]){
			dfs(x-1, y);
		}
	}
}
int main(){
	cin >> n >> k >> r;
	for(int i = 0; i < r; i++){
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		int dir = -1;
		int dir2 = -1;
		if(b + 1 == d){
			dir = 0;
			dir2 = 1;
		}
		else if(b - 1 == d){
			dir = 1;
			dir2 = 0;
		}
		else if (a + 1 == c){
			dir = 2;
			dir2 = 3;
		}
		else if (a -1 ==c){
			dir = 3;
			dir2 = 2;
		}
		blocked[a][b][dir] = 0; //thou shalt not pass - brian dean to me, in regards to usaco silver
		blocked[c][d][dir2] = 0;
	}
	int pairs = 0;
	for(int i = 0; i < k; i++){
		int a, b;
		cin >> a >> b;
		cowList.push_back({a,b});
		cl[a][b] = i;
	}
	for(int i = 0; i < k; i++){
		dfs(cowList[i].first, cowList[i].second);	
		for(int j = 0; j < i; j++){ //to avoid overcounting pairs
			if(!vis[cowList[j].first][cowList[j].second]){ //cannot reach a cow's coordinates
				pairs++;
			}
		}
		vis.clear();
		vis.resize(101, vector<bool>(101, false));
		
	}
	cout<<pairs;
}