#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin >> n;
	vector<int> id;
	for(int i =0 ; i < n; i++){
		int a;
		cin>> a;
		id.push_back(a % 7);
	}
	int lo = -1;
	int hi = n;
	while(lo < hi){
		int mid = lo + (hi - lo + 1)/2;
		int cs = 0;
		for(int i = 0; i < mid; i++){
			cs+=id[i];
		}
		int fi = 0;
		int li = mid-1;
		cs%=7;
		bool works =false;
		while(li < n){
			if(cs == 0){
				works =true;
				break;
			}
			else{
				cs -= id[fi];
				li++;
				fi++;
				cs+=id[li];
				cs%=7;
			}
		}
		if(works){
			lo = mid;
		}
		else{
			hi =mid-1;
		}
	}
	cout<<lo<<'\n';
}