#include <bits/stdc++.h>
const int MAXMN = 500;
int m, n;
bool visited[MAXMN][MAXMN] = {false};
int elv[MAXMN][MAXMN] = {0};
std::vector<std::pair<int,int>> wpl;
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
void ff(int x, int y, int d){ //phloodphill
	visited[x][y] = true; //i literally forgot this line
	for(int i = 0; i < 4; i++){
		if(abs(elv[x][y] - elv[x+dx[i]][y+dy[i]]) <= d){
			if(x+dx[i] < 0 || x+dx[i] > m-1 || y+dy[i] < 0 || y+dy[i] > n-1 || visited[x+dx[i]][y+dy[i]]){ //and to stop if it was visited.
//				std::cout<<"fail "<<x<<" "<<y<<" "<<i<<" "<<visited[x+dx[i]][y+dy[i]]<<'\n';
				continue;
			}
			else{
//				std::cout<<"succeeded "<<x<<" "<<y<<" "<<i<<'\n';
//				std::cout<<elv[x][y]<<" "<<elv[x+dx[i]][y+dy[i]]<<" "<<x<<" "<<y<<" "<<x+dx[i]<<" "<<y+dy[i]<<std::endl;
				ff(x+dx[i],y+dy[i],d);	
			}
		}
	}
}
bool all_reach(){
	bool all_vis = true;
	for(std::pair<int,int> p : wpl){
		if(!visited[p.first][p.second]){
			all_vis = false;
		}
	}
	return all_vis;
}
int main(){
	int lo = 0;
	int hi = 1e9; //i changed these to 100 and 100/2 during testing and forgot to change them back. :skull:
	int mid = (1e9)/2;
	std::ifstream in("ccski.in");
	std::ofstream out("ccski.out");
	in >> m >> n;
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			int temp;
			in >> temp;
			elv[i][j] = temp;
		}
	}
	for(int i = 0; i < m; i++){
		for(int j = 0; j < n; j++){
			int temp;
			in >> temp;
			if(temp == 1){
				wpl.push_back(std::make_pair(i,j));
			}
		}
	}
	int min_diff = 1e9;
	//binary search best girl, even though she split lists she will never split from you :D
	while(lo < hi){
		mid = (hi+lo)/2;
////		std::cout<<"LO: "<<lo<<" HI: "<<hi<<'\n';
		ff(wpl[0].first,wpl[0].second,mid);
		if(all_reach()){
			if(mid<min_diff){
				min_diff = mid;
			}
			hi = mid;
		}
		if(!all_reach()){
			lo = mid+1;
		}
////		std::cout<<"CYCLE END"<<'\n';
		for(int i = 0; i < m; i++){ //originally used memset but for some reason it didn't work. Took me way too long to figure out.
			for(int j = 0; j < n; j++){
				visited[i][j] = 0;
			}
		}
////		std::cout<<"CURRENT STATE OF VISITED: \n";
////		for(int i = 0; i < m; i++){
////			for(int j = 0; j < n; j++){
////				std::cout<<visited[i][j]<<'\n';
////			}
////		}
	}
//	ff(wpl[0].first,wpl[0].second,20);
//	for(std::pair<int,int> p: wpl){
		out<<min_diff<<'\n';
//	}
	
	
}
