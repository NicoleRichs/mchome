#include <bits/stdc++.h>
int n, k, r;
const int MAXN = 100;
bool has_road[MAXN][MAXN][MAXN][MAXN] = {false};
bool visited[MAXN][MAXN] = {false};
int dy[4] = {0,1,0,-1};
int dx[4] = {1,0,-1,0};
void ff(int x, int y){
	if(x < 1 || x > n || y < 1 || y > n || visited[x][y]){
		return;
	}
	visited[x][y] = true;
	for(int i = 0; i < 4; i++){
		if(!has_road[x][y][x+dx[i]][y+dy[i]]){
			ff(x+dx[i],y+dy[i]);	
		}
		
	}
}
int main(){
	std::ifstream in("countcross.in");
	std::ofstream out("countcross.out");
	in >> n >> k >> r;
	for(int i = 0; i < r; i++){
		int x1, y1, x2, y2;
		in >> x1 >> y1 >> x2 >> y2;
		has_road[x1][y1][x2][y2] = true;
		has_road[x2][y2][x1][y1] = true;
	}
	int ans = 0;
	int ca[k][2];
	for(int j = 0; j < k; j++){
		int i1,j1;
		in >> ca[j][0] >> ca[j][1];
	}
	
	for(int i = 0; i < k; i++){
		for(int j = 0; j < k; j++){
			if(i!=j){
				int sx, sy, ex, ey;
				sx = ca[i][0];
				sy = ca[i][1];
				ex = ca[j][0];
				ey = ca[j][1];
				ff(sx,sy);
				if(!visited[ex][ey]){
					ans++;
				}
				memset(visited, 0, sizeof(visited));
			}		
		}
	}
	std::cout<<ans/2<<'\n'; //we double count but eh whatever man
}
