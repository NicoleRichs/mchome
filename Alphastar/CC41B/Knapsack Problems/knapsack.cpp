#include <bits/stdc++.h>
using namespace std;
int main(){
	int n, c;
	cin >> n>>c;
	vector<pair<int,int>> items;
	for(int i= 0; i  < n; i++){
		int a, b;
		cin >> a >> b;
		items.push_back(make_pair(a,b));
	}
	vector<int> mv(c+1, 0);
	for(int i= 0; i < n; i++){
		int cs = (items[i]).first;
		int cv = (items[i]).second;
		for(int j = c-cs; j >= 0; j--){ //go from right to left to avoid using knapsack items multiple times
			mv[j+cs] = max(mv[j+cs], mv[j] + cv);
		}
	}
	int m = 0;
	for(int i = 0; i<=c; i++){
		m =max(m, mv[i]);
	}
	cout<<m<<'\n';
	
}
