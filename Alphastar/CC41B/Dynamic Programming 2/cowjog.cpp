#include <bits/stdc++.h>
using namespace std;
int main(){
	int cows, time;
	cin >> cows >> time;
	vector<long long> ep;
	for(int i = 0; i < cows; i++){
		long long a;
		cin >> a;
		long long b;
		cin >> b;
		ep.push_back(-(a + (time*b)));
	}
	vector<long long> tail;
	for(int i = 0; i < cows; i++){
		long long cur = ep[i];
		if(tail.size() == 0){
			tail.push_back(cur);
		}
		else if(tail[tail.size() - 1] <= cur){
			tail.push_back(cur);
		}
		else{
			*upper_bound(tail.begin(), tail.end(), cur) = cur;
		}
	} 
	cout<<tail.size();
}
