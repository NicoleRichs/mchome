#include <bits/stdc++.h>
using namespace std;
struct point{
	int id;
	int p;
	bool s;
};
bool cmp(point a, point b){
	return a.p < b.p;
}
int main(){
	int n;
	cin >> n;
	vector<point> ranges;
	for(int i = 0; i < n; i++){
		int a, b;
		cin >> a >> b;
		ranges.push_back({i, a, true});
		ranges.push_back({i, b, false});
	}
	int line = 0;
	int num = 0;
	vector<int> solo(n, 0);
	sort(ranges.begin(), ranges.end(), cmp);
//	for(int i = 0; i < 2 * n; i++){
//		cout<<ranges[i].id<<" "<<ranges[i].p<<" "<<ranges[i].s<<'\n';
//	}
	set<int> cc;
	int tr = 0;
	int minC = 1e9;
	for(int i = 0; i < 2 * n; i++){
		if(num == 1){
			solo[*(cc.begin())] = (ranges[i].p - ranges[i-1].p);
//			cout<<"ADDED "<<ranges[i].p - ranges[i-1].p<<"TO "<<(*(cc.begin()))<<'\n';
		}
		if(ranges[i].s == false){
			cc.erase(ranges[i].id);
			num--;
		}
		if(ranges[i].s == true){
			cc.insert(ranges[i].id);
			num++;
		}
		if(num > 0 && i < (2 * n) - 1){
			tr+=(ranges[i+1].p - ranges[i].p);
		}
	}
	
	for(int i = 0; i < n; i++){
		minC = min(minC, solo[i]);
	}
	cout<<tr - minC<<'\n';
}
