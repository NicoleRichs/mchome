#include <bits/stdc++.h>
using namespace std;
void solve(){
	int characters;
	cin >> characters;
	map<int, long long> sum_dist; //had to change the key to an int to ensure compatability
	vector<int> numbas (characters+1);
	for(int i = 1; i <= characters; i++){
		char c;
		cin >> c;
		numbas[i]= (c-'0');
	}
	for(int j =1 ; j <= characters; j++){
		numbas[j]+=numbas[j-1];
	}
	for(int k = 0; k <= characters; k++){
		sum_dist[numbas[k] - k]++;
	}
	long long good_arrays = 0;
	for (const auto& [_, f]: sum_dist) {
		// calculate # of possible unordered pairs with f values of i
		good_arrays += f * (f - 1) / 2;
	}
	cout<<good_arrays<<'\n';
}
int main(){
	int cases;
	cin >> cases;
	for(int i= 0; i < cases; i++){
		solve();
	}
}
