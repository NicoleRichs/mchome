#include <bits/stdc++.h>
using namespace std;
/**
An excellent lesson in not sticking to dogma. I originally followed Alphastar's solution but that kept being wrong. It didn't really sit well with me so I figured it out
on my own. Essentially you have to simulate all three actions you can take, and I forgot about the +1s.
**/
int main(){
	//it's time to dp all over the place
	string s1, s2;
	cin >> s1;
	cin >> s2;
//	cout<<s1<<" "<<s2<<'\n';
	vector<vector<int>> dp(s1.length()+1,vector<int>(s2.length()+1, 0));
	for(int i = 1; i <= s1.length(); i++){
		dp[i][0] = i;
	}
	for(int j = 1; j <= s2.length(); j++){
		dp[0][j] = j;
	}
	for(int i = 1; i <= s1.length();i++){
		for(int j = 1; j <= s2.length();j++){
			if(s1[i-1] == s2[j-1]){
				dp[i][j] = dp[i-1][j-1];
			}
			else{
				dp[i][j] = dp[i-1][j-1] + 1; //replace the last character
//				cout<<dp[i][j]<<'\n';
				dp[i][j] = min(dp[i][j], dp[i-1][j]+1); //delete our last char. Took me a bit too long to add the +1 to the end of dp[i-1][j].
//				cout<<dp[i][j]<<'\n';
				dp[i][j] = min(dp[i][j], dp[i][j-1]+1); //add in the last char of s2. Ditto line 24.
//				cout<<dp[i][j]<<'\n';
			}
//			for(int i = 0; i <= s1.length(); i++){
//				for(int j = 0; j <= s2.length(); j++){
//					cout<<dp[i][j]<<" ";
//				}
//				cout<<'\n';
//			}
//			cout<<"____________________________"<<'\n';
		}
	}
	cout<<dp[s1.length()][s2.length()];
}
