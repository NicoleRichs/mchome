#include <bits/stdc++.h>
using namespace std;
int main(){
	int nums;
	cin >> nums;
	vector<int> list;
	long long ts = 0;
	for(int i = 0; i < nums; i++){
		int n;
		cin >> n;
		list.push_back(n);
		ts+=n;
	}
	long long min_diff = INT64_MAX;
	for(int i = 0; i < (1 << nums); i++){
		long long rs = 0;
		for(int j = 0; j < nums; j++){
			if(i & (1 << j)){
				rs+=list[j];
			}
		}
		min_diff = min(min_diff, (abs((ts - rs) - rs)));
	}
	cout<<min_diff<<'\n';
}
