#include <bits/stdc++.h>
using namespace std;
int main(){
	int cases;
	cin >> cases;
	for(int i = 0; i < cases; i++){
		vector<int> ca;
		int cs;
		cin >> cs;
		for(int i = 0; i < cs; i++){
			int a;
			cin >> a;
			ca.push_back(a);
		}
		int cd = 0;
		int cp = ca[0];
		for(int i = 1; i < cs; i++){
			cd = max(cd, cp-ca[i]);
			cp = max(cp, ca[i]);
		}
		int ans = 0;
		while(cd > 0){
			cd -= (1 << ans);
			ans++;
		}
		cout<<ans<<'\n';
	}
}
