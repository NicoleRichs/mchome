#include <bits/stdc++.h>
using namespace std;
int len =0;
char str[1500] = {};
//idea for this problem: have a sliding window of two pointers, check the maximum number of the specified charcaters we can stick into it, and just find the largest value. really cutting it close for time complexity.
void solve(){
	int maxReplace = 0;
	char favChar;
	cin >> maxReplace>> favChar;
	int p1 = 0;
	int p2 = 0;
	int ca = maxReplace;
	//aah
	while(p1 <len && p2 < len){
		int cl = 0;
		while(p2 < len){
			if(str[p2] != favChar){
//				cout<<"incorrect char found"<<'\n';
				if(maxReplace == 0){
					break;
				}
				maxReplace--;
			}
			p2++;
		}
		ca = max(ca, p2 -p1);
		maxReplace+=(str[p1++] != favChar);
	}
	cout<<ca<<'\n';
}
int main(){
	cin >> len;
	for(int i= 0; i < len; i++){
		char c;
		cin >> c;
		str[i] = c;
	}
	int passes;
	cin >> passes;
	for(int i =0 ; i < passes; i++){
//		cout<<"S"<<'\n';
		solve();
	}
}
