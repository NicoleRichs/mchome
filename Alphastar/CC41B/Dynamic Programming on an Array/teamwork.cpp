#include <bits/stdc++.h>
using namespace std;
int main(){
	int n, k;
	cin >> n >> k;
	vector<int> cows(n);
	for(int i = 0; i < n; i++){
		cin >> cows[i];
	}
	vector<int> dp(n); //dp[n] is the best score, using up to the nth cow
	dp[0] = cows[0];
	for(int i = 1; i < n; i++){
		
		int mv = cows[i];
		
		for(int j = i; i + 1 - j <= k && j >= 0; j--){ //iterate through all end indexes
		
			mv = max(mv, cows[j]); //current max value in the last group
		
			if(j == 0){ //this means we only have 1 group
		
				dp[i] = max(dp[i], mv *(i + 1 - j)); //the max score if we just set all first i cows as one group
		
			}
		
			else{
		
				dp[i] = max(dp[i], dp[j-1] + (mv *(i + 1 - j))); //the max score if we make a group from index j to index i, added to the max score using all cows up to j - 1.
		
			}
		
		}
	}
	cout<<dp[n-1]<<'\n';
}
