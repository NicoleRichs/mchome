#include <bits/stdc++.h>
using namespace std;
char grid[10][100] = {};
bool vis[10][100] = {};
int dX[4] = {0,1,0,-1};
int dY[4] = {1,0,-1,0};
int cn = 0;
set<pair<int,int>> cc;
int n = 0, k = 0;
bool in_bounds(int x, int y){
	if(x < 0 || x > 9){
		return false;
	}
	if(y < (100-n) || y > 99){
		return false;
	}
	return true;
} 
void dfs(int x, int y){
	cn+=1;
	cc.insert({x,y});
	vis[x][y] = true;
	for(int i = 0; i < 4; i++){
		if(in_bounds(x+dX[i], y + dY[i]) && grid[x+dX[i]][y+dY[i]] == grid[x][y] && !vis[x+dX[i]][y+dY[i]]){
//			cout<<"hello"<<'\n';
			dfs(x+dX[i], y + dY[i]);
		}
	}
}
int main(){
	ifstream in("mooyomooyo.in");
	ofstream out("mooyomooyo.out");
	in >> n >> k;
	for(int i = (100 - n); i < 100; i++){
		for(int j = 0; j < 10; j++){
			char a;
			in >> a;
			grid[j][i] = a;
		}
	}
	bool trigger = false;
	do{
		trigger = false;
//		cout<<"pass"<<'\n';
		for(int a = (100-n); a < 100; a++){
			for(int b = 0; b < 10; b++){
				if(!vis[b][a] && grid[b][a] != '0'){
					dfs(b,a);
					if(cn >= k){
						trigger = true;
						auto it = cc.begin();
						while(it != cc.end()){
//							cout<<(*it).first<<" "<<(*it).second<<'\n';
							grid[(*it).first][(*it).second] = '0';
							it++;
		 				}
					}
					cn = 0;
	 				cc.clear();
				}
			}
		}	
		for(int c = 98; c >= (100-n); c--){
			for(int d = 0; d < 10; d++){
				int cx =d;
				int cy = c;
				char r = grid[cx][cy];
				while(c < 99){
					if(grid[cx][cy+1] == '0'){
						cy++;
					}
					else{
						break;
					}
				}
				grid[d][c] = '0';
				grid[cx][cy] = r;
			}
		}
		for(int i = (100 - n); i < 100; i++){
			for(int j = 0; j < 10; j++){
				vis[j][i] = false;
			}
		}
	}while(trigger);
	for(int i = (100 - n); i < 100; i++){
		for(int j = 0; j < 10; j++){
			out<<grid[j][i];
		}
		out<<'\n';
	}
}
