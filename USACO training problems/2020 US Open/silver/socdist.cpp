#include <bits/stdc++.h>
using namespace std;
bool cmp(pair<long long,long long> &a, pair<long long,long long> &b){
	return a.first < b.first;
}
int main(){
	ifstream in("socdist.in");
	ofstream out("socdist.out");
	int cows, patches;
	in >> cows >> patches;
	vector<pair<long long,long long>> pl;
	for(int i = 0; i < patches; i++){
		long long a, b;
		in >> a >> b;
		pl.push_back(make_pair(a,b));
	}
	sort(pl.begin(),pl.end(),cmp);
	long long lo = 0l;
	long long hi = pl[patches-1].second - pl[0].first + 1;
	long long ans = 0;
	while(lo <= hi){
		//this is our minimum distance
		long long mid = (lo + hi)/2;
		int cowsPlaced = 1;
		long long curIndex = pl[0].first;
		int curPatch = 0;
		while(curIndex + mid < pl[patches-1].second){
			while(curIndex + mid > pl[curPatch].second){
				curPatch++;
			}
			curIndex = max(curIndex + mid, pl[curPatch].first);
			cowsPlaced++;
			if(cowsPlaced == cows){
				break;
			}

		}
		if(cowsPlaced < cows){
			hi = mid-1;
		}
		else if(cowsPlaced >= cows){
			lo = mid+1;
			ans = max(mid, ans); 
		}
	}
	out<<ans<<'\n';
}
