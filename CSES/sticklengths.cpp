#include <bits/stdc++.h>
using namespace std;
int main(){
	int stick;
	cin >> stick;
	vector<int> sticks(stick);
	for(int& s : sticks){
		cin >> s;
	}
	sort(sticks.begin(),sticks.end());
	int median = stick/2;
	long long cost = 0;
	for(int s : sticks){
		if(s < sticks[median]){
			cost+=sticks[median]-s;
		}
		else{
			cost+=s-sticks[median];
		}
		
	}
	cout<<cost<<endl;
}
