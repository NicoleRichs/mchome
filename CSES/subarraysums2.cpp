#include <bits/stdc++.h>
using namespace std;
int main(){
	//idk why but this makes the IO go fast
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n, x;
	cin >> n >> x;
	vector<int> nums;
	map<long long, long long> sumCounts; //the key is the sum, the value is the number of occurances. changed the values to ll just in case.
	for(int i = 0; i < n; i++){
		int a;
		cin >> a;
		nums.push_back(a);
	}
	long long curSum = 0;
	long long ans = 0; //changed this to a ll
	sumCounts[0]=1;
	for(int c : nums){
		curSum+=c;
		ans+=sumCounts[curSum - x]; //we check how many prefix sums exist that equal curSum -x, which we can then exclude from our subarray and create a subarray sum of x.
		sumCounts[curSum]++; //logging our current prefix sum
	}
	cout<<ans<<'\n';
}
