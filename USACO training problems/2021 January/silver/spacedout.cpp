#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin >> n;
	vector<vector<int>> grid(n, vector<int>(n,0));
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			int a;
			cin >> a;
			grid[i][j] = a;
		}
	}
	//horizontal ps
	vector<int> horizontal(n, 0);
	int ha = 0;
	for(int i = 0; i < n; i++){
		int n1 = 0;
		int n2 = 0;
		for(int j = 0; j < n; j++){
			if(j%2 == 0){
				n2+=grid[i][j];
			}
			else{
				n1+=grid[i][j];
			}
		}
		horizontal[i] = max(n1, n2);
		ha+=max(n1, n2);
	}
	//vertical ps
	vector<int> vertical(n, 0);
	int va = 0;
	for(int i = 0; i < n; i++){
		int n1 = 0;
		int n2 = 0;
		for(int j = 0; j < n; j++){
			if(j%2 == 0){
				n2+=grid[j][i];
			}
			else{
				n1+=grid[j][i];
			}
		}
		vertical[i] = max(n1, n2);
		va+=max(n1, n2);
	}
	cout<<max(va, ha)<<'\n';
}
