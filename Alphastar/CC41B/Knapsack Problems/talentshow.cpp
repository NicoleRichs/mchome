#include <bits/stdc++.h>
using namespace std;
vector<double> raww;
vector<double> tal;
vector<int> neword;
bool cmp(int a, int b){
	double r1 = raww[a]/tal[a];
	double r2 = raww[b]/tal[b];
	return r1 < r2;
}
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
	double tot = 0;
	double rat = 0;
	sort(neword.begin(),neword.end(), cmp);
	for(int i = 0; i < n; i++){
		if(tot >= w){
			break;
		}
		else{
			int ai = neword[i];
			tot+=raww[ai];
			rat+=tal[ai];
		}
	}
	int adj = (rat/tot) * 1000;
	cout<<adj<<'\n';
}
