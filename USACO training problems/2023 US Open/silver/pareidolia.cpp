#include <bits/stdc++.h>
using namespace std;
int main(){
	string s;
	cin >> s;
	string bessie = {'b','e','s','s','i','e'};
	long long ans = 0l;
	long long waiting[7] = {};
	long long rem = s.length();
	for(char c : s){
		waiting[0]++;
		for(int d = 5; d >= 0; d--){
			if(c == bessie[d]){
				waiting[d+1]+=waiting[d];
				waiting[d]=0;
			}
		}
		ans+=waiting[6] * rem;
		waiting[0]+=waiting[6];
		waiting[6] = 0;
		rem--;
	}
	cout<<ans<<'\n';
}
