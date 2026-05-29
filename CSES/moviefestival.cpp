#include <bits/stdc++.h>
using namespace std;
bool bySecond(pair<int, int>& a, pair<int,int>& b){
	return a.second < b.second;
}
int main(){
	int n;
	cin >> n;
	vector<pair<int,int>> movies(n);
	for(pair<int,int>& p : movies){
		cin >> p.first >> p.second;
	}
	sort(movies.begin(),movies.end(),bySecond);
//	for(pair p : movies){
//		cout<<p.first<<" "<<p.second<<endl;
//	}
	int ct = 0;
	int cm = 0;
	int movieswatched = 0;
	while(ct < movies[n-1].second && cm < n){
		ct = movies[cm].second;
		movieswatched++;
		while(movies[cm].first < ct){
			cm++;
		}
	}
	cout<<movieswatched<<endl;
}
