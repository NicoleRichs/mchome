#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin >> n;
	vector<int> cows;
	for(int i= 0; i < n; i++){
		int a;
		cin >> a;
		cows.push_back(a);
	}
	sort(cows.begin(), cows.end(), greater<int>());
	int inl = 0;
	for(int i = 0; i < n; i++){
		if(cows[i] >= inl){
			inl++;
		}
	}
	cout<<inl<<'\n';
}