#include <bits/stdc++.h>
using namespace std;
long long n, x;
int main(){
//	ifstream in("coincombinations.in");
	cin >> n >> x;
	vector<long long> coins;
	vector<long long> values(1000001,0);
	for(int i = 0; i < n; i++){
		int a;
		cin >> a;
		coins.push_back(a);
	}
	values[0] = 1;
	for(int j = 1; j <= x; j++){
		for(int c = 0; c < n; c++){
			if(j - coins[c] >= 0){
				values[j]+=values[j-coins[c]];
			}
		}
		values[j] = values[j] % (int(1e9 + 7));
	}
	cout<<(values[x])<<'\n';
}
