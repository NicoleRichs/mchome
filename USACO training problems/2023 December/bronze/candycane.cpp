#include <bits/stdc++.h>
using namespace std;
int main(){
	int n, m;
	cin >> n >> m;
	vector<long long> heights;
	for(int i = 0; i < n; i++){
		long long a;
		cin >> a;
		heights.push_back(a);
	}
	int cm = 0;
	vector<int> cp;
	vector<long long> cheights;
	for(int i = 0; i < n; i++){
		if(heights[i] > cm){
			cp.push_back(i);
			cheights.push_back(heights[i]);
			cm = heights[i];
		}
	}
	for(int j = 0; j < m; j++){
		long long c;
		cin >> c;
		long long oc = c;
		long long ch = 0;
		long long pos = 0;
		while(ch < oc && pos < cheights.size()){
			if(cheights[pos] > ch){
				if(cheights[pos] >= oc){
					cheights[pos]+= oc - ch;
					break;
				}
				long long t = cheights[pos];
				cheights[pos] += (cheights[pos]-ch);
				ch = t;
			}
			pos++;
		}
	}
	for(int i = 0; i < cheights.size(); i++){
		heights[cp[i]] = cheights[i];
	}
	for(int i = 0; i < n; i++){
		cout<<heights[i]<<'\n';
	}
}
//WHEN IN DOUBT BRUTE SIM BRONZE
