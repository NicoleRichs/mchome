#include <bits/stdc++.h>
using namespace std;
//holy hell i can't do prefix sums ahh
//easy problem, difficult brain
int main(){
	int n, q;
	cin >> n >> q;
	string s;
	cin >> s;
	vector<int> pref;
	pref.push_back(0);
	vector<int> suf;
	suf.push_back(0);
	int prev = 0;
	stack<char> cp;
	cp.push('0');
	for(int i = 0; i < n; i++){
		while(cp.top() > s[i]){
			cp.pop();
		}
		if(cp.top() < s[i]){
			cp.push(s[i]);
			prev++;
		}
		pref.push_back(prev);
	}
//	for(int i = 0; i < n; i++){
//		cout<<pref[i]<<' ';
//	}
	reverse(s.begin(), s.end());
	prev = 0;
	while(!cp.empty()){
		cp.pop();
	}
	cp.push('0');
	for(int i = 0; i < n; i++){
		while(cp.top() > s[i]){
			cp.pop();
		}
		if(cp.top() < s[i]){
			cp.push(s[i]);
			prev++;
		}
		suf.push_back(prev);
	}
//	for(int i = 0; i < n; i++){
//		cout<<suf[i]<<' ';
//	}
	
	for(int i = 0; i < q; i++){
		int a, b;
		cin >> a >> b;
		cout<<pref[a-1] + suf[n-b]<<'\n';
	}
}