#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin >> n;
	int sum = 0;
	for(int i = 1; i <= n; i++){
		sum+=i;
	}
	if(sum%2 != 0){
		cout<<0<<'\n';
		return 0;
	}
	vector<long long> ways(sum+1, 0ll);
	ways[0] = 1;
	int cm = 0;
	for(int i = 1; i <= n; i++){
		for(int j = cm; j >=0; j--){
			if(ways[j+i] == 0){
				ways[j+i] = ways[j];
			}
			else{
				ways[j+i]+=ways[j];
			}
		}
		cm+=i;
	}
	cout<<ways[sum/2]/2<<'\n';
}
