#include <bits/stdc++.h>
using namespace std;
int n, x;
const int MOD = 1e9 + 7;
int main(){
	cin >> n >> x;
	vector<int> coins;
	vector<int> ways(x + 1, 0);
	for(int i = 0; i < n; i++){
		int a;
		cin >> a;
		coins.push_back(a);
	}
	ways[0] = 1;
	for(int c = 0; c < n; c++){
		for(int v = 0; v <= x; v++){
			if(v - coins[c] >= 0){
				ways[v] += ways[v - coins[c]];
				ways[v] = ways[v] % (MOD);
			}
		}
	}
	cout<<ways[x]<<'\n';
}
