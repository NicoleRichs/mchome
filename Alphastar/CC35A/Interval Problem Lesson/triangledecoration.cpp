#include <bits/stdc++.h>
#define lint long long
using namespace std;
bool cmp3(pair<lint,lint> a, pair<lint,lint> b){
	if(a.first == b.first){
		return b.second > a.second;
	}
	else{
		 return a.first > b.first;
	}
}
int main(){
	vector<pair<lint,lint>> intervals;
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		lint x, y;
		cin >> x >> y;
		intervals.push_back({y-x, y+x});
	}
	int ans = n;
	lint ce = -2000000000;
	sort(intervals.begin(), intervals.end(), cmp3);
	for(int i = 0; i < n; i++){
		lint cx = intervals[i].second;
		if(cx <= ce){
			ans--;
		}
		else{
			ce = cx;
		}
	}
	cout<<ans<<'\n';
}
