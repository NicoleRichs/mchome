#include <bits/stdc++.h>
using namespace std;
int main(){
	int k, n;
	cin >> k >> n;
	vector<int> vals;
	for(int i = 0; i < n; i++){
		int a;
		cin >> a;
		vals.push_back(a);
	}
	sort(vals.begin(),vals.end());
	if(vals[0]!=1){
		return 0;
	}
	int mv = vals[n-1] * k;
	vector<int> w(mv+1, 1000);
	for(int i = 0; i < n; i++){
		w[vals[i]] = 1;
	}
	for(int i = 0; i < n; i++){ //it's like the subset sum but we go from left to right since we can repeat subset elements
		int v = vals[i];
		for(int j = 1; j <= mv - v; j++){ //max time complexity is 2e6 * k, or 4e8. real sketch.
			w[j+v] = min(w[j+v], w[j]+1);	
		}
	}
	for(int i = 1; i <= mv; i++){
//		cout<<w[i]<<'\n';
		if(w[i]==1000 || w[i] > k){
			cout<<i-1<<'\n';
			return 0;
		}
	}
	cout<<mv<<'\n'; //lmao forgot this
	
}
