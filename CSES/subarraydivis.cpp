#include <bits/stdc++.h>
using namespace std;
int main(){
	//heavily based on my subarray sum ii code, since it's a similar problem
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> nums;
	map<long long, long long> modCounts;
	for(int i = 0; i < n; i++){
		int a;
		cin >> a;
		nums.push_back(a);
	}
	long long curMod = 0;
	long long ans = 0;
	for(int c : nums){
		curMod+=(c%n);
		curMod%=n;
		if(curMod < 0){ //fixes an edge case where you have negative modulos, we're converting them to positive ones.
			curMod+=n;
		}
		ans+=modCounts[curMod];
		modCounts[curMod]++;
		if(curMod == 0){ //accounts for the case where our modulo for this subarray is also 0.
			ans++;
		} 
	}
	cout<<ans<<'\n';
}
