#include <bits/stdc++.h>
using namespace std;
int main(){
	int n, k;
	cin >> n >> k;
	vector<int> da(n+1, 0);
	for(int i = 0; i < k; i++){
		int s, e;
		cin >> s >> e;
		da[s]++;
		if(e < n){
			da[e+1]--;
		}
	}
	vector<int> stacks;
	int prev = 0;
//	for(int i = 0; i <= n; i++){
//		cout<<da[i]<<" ";
//	}
//	cout<<'\n';
	for(int i = 1; i <= n; i++){
		stacks.push_back(prev + da[i]);
		prev = prev+da[i];
	}
//	for(int i = 0; i < n; i++){
//		cout<<stacks[i]<<" ";
//	}
//	cout<<'\n';
	sort(stacks.begin(), stacks.end());
	cout<<stacks[(n/2)]<<'\n';
}
