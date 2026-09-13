#include <bits/stdc++.h>
//no using namespace std because it was causing problems. FEESHY.
const int MAXN = 1005;
bool grid[MAXN][MAXN];
int visited[MAXN][MAXN] = {};
int size = 0;
int perim = 0;
int sizea = 0;
int perima = 0;
int rows;
void ff(int x, int y, int group){
	if(x < 0 || x > rows-1 || y < 0 || y > rows-1){
		return;
	}
	if(grid[x][y]){
		if(visited[x][y] == 0){
			visited[x][y] = group;
			size+=1;
			if(!grid[x][y+1]){
				perim++;
			}
			if(!grid[x][y-1]){
				perim++;
			}
			if(!grid[x+1][y]){
				perim++;
			}
			if(!grid[x-1][y]){
				perim++;
			}
			ff(x,y+1,group);
			ff(x+1,y,group);
			ff(x-1,y,group);
			ff(x,y-1,group);
			
		}
		
	}
	return;
}
int main(){
	std::ifstream in("perimeter.in");
	std::ofstream out("perimeter.out");
	in >> rows;
	for(int i = 0; i < rows; i++){
		for(int j = 0; j < rows; j++){
			char t;
			in >> t;
			if(t == '#'){
				grid[i][j] = true;
			}
			else{
				grid[i][j] = false;
			}
		}
	}
	int group = 1;
	for(int i = 0; i < rows; i++){
		for(int j = 0; j < rows; j++){
			if(grid[i][j] && visited[i][j]==0){
				ff(i, j, group);
			}
			group++;
			if(size > sizea){
				sizea = size;
				perima = perim;
			}
			else if(size == sizea){
				if(perim < perima){
					perima = perim;
				}
			}
			size = 0;
			perim = 0;
		}
	}
	out << sizea <<" "<<perima<<std::endl;
}
