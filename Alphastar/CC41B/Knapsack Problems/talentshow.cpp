#include <bits/stdc++.h>
using namespace std;
vector<double> raww;
vector<double> tal;
vector<int> neword;
//for make build on best sols - we can sort weights by decreasing ratio since we always get better result sorting from beeg to smol ratio
bool cmp(int a, int b){
	double r1 = raww[a]/tal[a];
	double r2 = raww[b]/tal[b];
	return r1 < r2;
}
//i hate debugging
int main(){
	int n, w;
	cin >> n >> w;
	for(int i = 0; i < n; i++){
		double w, t;
		cin >> w >> t;
		raww.push_back(w);
		tal.push_back(t);
		neword.push_back(i);
	}
	sort(neword.begin(),neword.end(),cmp);
	vector<int> dp(w+2,0); //max talent with max weight. dp[w+1] stores max ratio (l + bozo) of all combos beeger than or equal to w. I  had to make it dp[w+1] since with dp[w] the program thought the ratio 
	//was the total talent for weight w.
	int a = 0; //answer
	dp[0] = -1;
	for(int i = 0; i < n; i++){ //loop through all cows
		int ci = neword[i]; //normalized index for weight & talent, sorted by best to worst ratio
		for(int j = w; j >= 0; j--){ //loop through all weights
			double cw = j + raww[ci];
			int ct = dp[j] + tal[ci];
			if(j == 0){ct++;} //this is to offset setting dp[0] to -1.
			int convr = (ct/cw) * 1000;  //our converted answer, ratio * 1000 floored.
			if(dp[j] != 0){ //i set dp[0] to -1 to avoid triggering this for the base case.
//				cout<<i<<" "<<j<<" "<<cw<<" "<<ct<<'\n';
				if(cw > w){
					dp[w+1] = max(dp[w+1], convr);
				}
				else{
					dp[cw] = max(dp[cw], ct);
				}
				if(cw >= w){
					a = max(a, convr);
				}
			}

		}
	}
	cout<<a<<'\n';
}
