#include <bits/stdc++.h>
using namespace std;
int main(){
	int n, m, t;
	cin >> n >> m >> t;
	vector<vector<bool>> field;
	for(int i = 0; i < n; i++){
		vector<bool> temp;
		for(int j = 0; j < m; j++){
			char cur;
			cin >> cur;
			if(cur == '*'){
				temp.push_back(false);
			}
			else{
				temp.push_back(true);
			}
		}
		field.push_back(temp);
	}
	int x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	x1--;
	y1--;
	x2--;
	y2--;
	vector<vector<vector<int>>> ways(t+1, vector<vector<int>>(n, vector<int>(m,0))); //the worst thing i have written in a while
	ways[0][x1][y1] = 1;
	/**
	I feel so dirty writing this O(TNM) code
	ways[a][b][c] stores the ways to get to (b,c) at time a from the start point
	essentially we iterate over every space, and we then look at how many ways we could have gotten to its immediate neighbors the second before, 
	then we tally those up and set the number of ways for the current space of the current second to that. 
	**/
	for(int i = 1; i <= t; i++){
		for(int j = 0; j < n; j++){
			for(int k = 0; k < m; k++){
				if(field[j][k]){
					int rs = 0;
					if(j > 0){
						rs+=ways[i-1][j-1][k];
					}
					if(j < n-1){
						rs+=ways[i-1][j+1][k];
					}
					if(k > 0){
						rs+=ways[i-1][j][k-1];
					}
					if(k < m-1){
						rs+=ways[i-1][j][k+1];
					}
					ways[i][j][k] = rs;
				}
			}
		}
	}
	cout<<ways[t][x2][y2]<<'\n';;
}
