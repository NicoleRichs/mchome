#include <bits/stdc++.h>
#define pi std::pair<int,int>
//hoo boy comment time
const int MAXN = 105;
int n;
int litn = 1;
bool lit[MAXN][MAXN] = {false};
bool visited[MAXN][MAXN] = {false};
std::vector<pi> switches[MAXN][MAXN] = {};
void ff(int x, int y){
	//if this grid is out-of-bounds or visited already
	if(x < 0 || x > n || y < 0 || y > n || visited[x][y]){
		return;
	}
	visited[x][y] = true;
	for(pi p: switches[x][y]){
		//put this part in because i was counting the amount of rooms visited first, but it's actually the number of rooms lit. Also there are duplicate switches so this if statement is here.
		if(!lit[p.first][p.second]){
			litn++;
		}
		lit[p.first][p.second] = true;
		//this is to see if we've missed a lit room, for example [x-1][y] lights up [x+1][y] but ff won't be run on it because [x+1][y] gets FF'd first. Check if the room hasn't been visited, then if it's connected.
		if(!visited[p.first][p.second]){
			if(visited[p.first - 1][p.second] || visited[p.first + 1][p.second] || visited[p.first][p.second - 1] || visited[p.first][p.second + 1]){
				ff(p.first,p.second);
			}
		}
	}
	//das recursion
	if(lit[x+1][y]){
		ff(x+1,y);
	}
	if(lit[x-1][y]){
		ff(x-1,y);
	}
	if(lit[x][y+1]){
		ff(x,y+1);
	}
	if(lit[x][y-1]){
		ff(x,y-1);
	}
	if(lit[x+1][y]){
		ff(x+1,y);
	}
}
int main(){
	std::ifstream in("lightson.in");
	std::ofstream out("lightson.out");
	int m;
	in >> n >> m;
	for(int i = 0; i < m; i++){
		int x1,y1,x2,y2;
		in >> x1 >> y1 >> x2 >> y2;
		switches[x1-1][y1-1].push_back(std::make_pair(x2-1,y2-1));
	}
	lit[0][0] = true;
	ff(0,0);
	out<<litn<<std::endl;
}
