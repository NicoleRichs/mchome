#include <bits/stdc++.h>
using namespace std;
bool cmp4(pair<int,bool> a, pair<int,bool> b){
	return a.first < b.first;
}
int main(){
	int n;
	cin >> n;
	vector<pair<int,bool>> ep;
	for(int i = 0;i < n; i++){
		int a, b;
		cin >> a >> b;
		ep.push_back({a, true});
		ep.push_back({b+1, false});
	}
	sort(ep.begin(), ep.end(), cmp4);
	int cur = 0;
	int ans = 0;
	for(int i = 0; i < 2 * n; i++){
		if(ep[i].second == true){
			cur++;
		}
		else{
			cur--;
		}
		while(i < 2 * n - 1 && ep[i+1].first == ep[i].first) {
			i++;
			if(ep[i].second == true){
				cur++;
			}
			else{
				cur--;
			}
		}
		ans = max(ans, cur);
	}
	cout<<ans<<'\n';
}
