#include <bits/stdc++.h>
using namespace std;
int main(){
	int r;
	cin >> r;
	vector<vector<int>> grid;
	for(int i = 0; i < r; i++){
		vector<int> temp;
		for(int j = 0; j<=i; j++){
			int a;
			cin >> a;
			temp.push_back(a);
		}
		grid.push_back(temp);	
	}
	vector<vector<int>> score(r, vector<int>(r,0));
	score[0][0] = grid[0][0];
	for(int i = 0; i < r-1; i++){
		for(int j = 0; j <= i; j++){
			if(score[i+1][j] < score[i][j] + grid[i+1][j]){
				score[i+1][j] = score[i][j] + grid[i+1][j];
			}
			if(score[i+1][j+1] < score[i][j] + grid[i+1][j+1]){
				score[i+1][j+1] = score[i][j] + grid[i+1][j+1];
			}
		}
	}
	int ms = 0;
	for(int i = 0; i < r; i++){
		ms = max(ms, score[r-1][i]);
	}
	cout<<ms<<'\n';
}
