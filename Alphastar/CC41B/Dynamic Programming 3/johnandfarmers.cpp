/**
I put your mother in my knapsack-
Dilet, 9/19/2023, 1204 PST
**/
#include <bits/stdc++.h>
using namespace std;
int main(){
	int n, t;
	cin >> n >> t;
	vector<pair<int,int>> games;
	vector<int> mc(50001, 2000000000);
	for(int i=  0; i < n; i++){
		int a, b;
		cin >> a >> b;
		games.push_back(make_pair(a,b));
	}
	mc[0] = 0;
	for(int i = 0; i <= t; i++){
		for(int j = 0; j < n; j++){
			if(i + (games[j]).first > t){
				mc[t] = min(mc[t], mc[i] + (games[j]).second);
			}
			else{
				mc[i + (games[j]).first] = min(mc[i + (games[j]).first], mc[i] + (games[j]).second);	
			}

		}
	}
	cout<<mc[t]<<'\n';
}
