#include <bits/stdc++.h>
using namespace std;
vector<int> rarity;
int n, k, l;
bool works(int c){
	for(int i = 0; i < c; i++){
		if(rarity[i] - c < -k){
			return false;
		}
	}
	long long change = k * l;
	for(int i = 0; i < c; i++){
		change += min(0, rarity[i] - c);
	}
	return change >= 0;
}
int main(){
	cin >> n >> k >> l;
	for(int i = 0; i < n; i++){
		int a;
		cin >> a;
		rarity.push_back(a);
	}
	sort(rarity.begin(), rarity.end(), greater<int>());
	int lo = 0;
	int hi = n;
	while(lo < hi){
		int mid = lo + (hi - lo + 1)/2;
//		cout<<mid<<'\n';
		if(works(mid)){
			lo = mid;
		}
		else{
			hi = mid-1;
		}
	}
	cout<<lo<<'\n';
}
