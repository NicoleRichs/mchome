#include <bits/stdc++.h>
using namespace std;
bool cmp(pair<int,int> &a, pair<int,int> &b){
	return a.second < b.second;
}
int main(){
	vector<pair<int,int>> times;
	multiset<int> openings;
	int movies, members;
	cin >> movies >> members;
	for(int i = 0; i < movies; i++){
		int a,  b;
		cin >> a >> b;
		times.push_back(make_pair(a,b));
	}
	for(int i = 0; i < members; i++){
		openings.insert(0);
	}
	sort(times.begin(),times.end(),cmp);
	int ans = 0;
	for(int m = 0; m < movies; m++){
		auto itr = openings.upper_bound(times[m].first);
		if(itr != begin(openings)){
			openings.erase(--itr);
			openings.insert(times[m].second);
			ans++;
		}
	}
	cout<<ans<<'\n';
}
