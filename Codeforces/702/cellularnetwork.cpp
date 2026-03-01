#include <bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	int cities, towers;
	cin >> cities >> towers;
	int cp[100000];
	int tp[100001];
	for(int i = 0; i < cities; i++){
		int p;
		cin >> p;
		cp[i] = p;
	}
	tp[0] = -1e9;
	for(int j = 1; j < towers+1; j++){
		int t;
		cin >> t;
		tp[j] = t;
	}
	int mp = 0;
	int ct = 1;
	for(int c = 0; c < cities; c++){
		ct = 1;
//		cout<<"PASS"<<endl;
		int td = INT_MAX;
		while(cp[c] >= tp[ct-1] && ct< towers+1){
			int v = abs(cp[c]-tp[ct]);
			td = min(v,td);
//			cout<<v<<" "<<td<<" "<<cp[c]<<" "<<tp[ct]<<endl;
			ct++;
		}
		mp = max(td,mp);
	}
	cout<<mp;
}

