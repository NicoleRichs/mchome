#include <bits/stdc++.h>
using namespace std;
int main(){
	int n, i, h, r;
	cin >> n >> i >> h >> r;
	vector<int> da(n+1, 0);
	set<pair<int,int>> cs;
	//so cheap they made duplicate ranges
	for(int i = 0; i < r; i++){
		int a, b;
		cin >> a >> b;
		if(a > b){
			swap(a,b);
		}
		if(a != b){
			cs.insert({a,b});
		}

	}
	for(pair<int,int> p : cs){
		int a = p.first;
		int b = p.second;
		da[a+1]--;
		da[b]++;
	}
	int cp = 0;
	vector<int> fh;
	for(int i = 1; i <= n; i++){
		cp+=da[i];
		fh.push_back(h + cp);
	}
	for(int i = 0; i < n; i++){
		cout<<fh[i]<<'\n';
	}
}
