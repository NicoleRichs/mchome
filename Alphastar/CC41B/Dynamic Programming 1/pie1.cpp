#include <bits/stdc++.h>
using namespace std;
int main(){
	int r, c;
	cin >> r >> c;
	vector<vector<int>> grid;
	for(int i = 0; i < r; i++){
		vector<int> temp;
		for(int j = 0; j < c; j++){
			int a;
			cin >> a;
			temp.push_back(a);
		}
		grid.push_back(temp);
	}
	vector<vector<int>> mc (r, vector<int>(c, 0));
	mc[0][0] = grid[0][0];
	for(int cc = 1; cc < c; cc++){ //i forgot what mc[i][j] meant and swapped around rows and columns. RIP BOZO
		for(int cr = 0; cr <= cc && cr < r; cr++){ //changed cr<cc to cr<=cc since that makes more sense in context. If we've only traveresed n columns we can go at max n columns down, to index n (cr<cc would give up to n-1).
//			cout<<cc<<" "<<cr<<'\n';
			int cm = 0;
			if(cr > 0){
				cm = max(cm, mc[cr-1][cc-1]);
//				cout<<"we live 1"<<'\n';
			}
			if(cr < r-1){
				cm = max(cm, mc[cr+1][cc-1]);
//				cout<<"we live 2"<<'\n';
			}
			cm = max(cm, mc[cr][cc-1]);
//			cout<<"we live 3"<<'\n';
			mc[cr][cc] = cm + grid[cr][cc];
//			cout<<"we live 444sqn"<<'\n';
		}
	}
	cout<<mc[r-1][c-1]<<'\n';
//	for(int i = 0; i < r; i++){
//		for(int j = 0; j < c; j++){
//			cout<<mc[i][j]<<" ";
//		}
//		cout<<'\n';
//	}
}
//"cow pie" seems a bit
//SUS
