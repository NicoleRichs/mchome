#include <bits/stdc++.h>
using namespace std;
int main(){
	ifstream in("helpcross.in");
	ofstream out("helpcross.out");
	int chickens, cows;
	in >> chickens >> cows;
	multiset<int> chickenset;
	vector<pair<int,int>> cowv;
	for(int i=  0; i < chickens; i++){
		int a;
		in >> a;
		chickenset.insert(a);
	}
	for(int j = 0; j < cows; j++){
		int a, b;
		in >> a >> b;
		cowv.push_back(make_pair(b,a));
	}
	int ans = 0;
	sort(cowv.begin(),cowv.end());
	for(int c = 0; c < cows; c++){
		auto choose = chickenset.lower_bound(cowv[c].second);
		if(choose!=chickenset.end() && *choose <= cowv[c].first){
			ans++;
			chickenset.erase(choose);
		}
	}
	out<<ans<<'\n';
	
}
