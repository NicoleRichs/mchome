#include <bits/stdc++.h>
using namespace std;
int main(){
	int t, c;
	cin >> t >> c;
	vector<int> instructions;
	set<int> targetLoc;
	for(int i = 0; i < t; i++){
		int a;
		cin >> a;
		targetLoc.insert(a);
	}
	for(int i = 0; i < c; i++){
		char cs;
		cin >> cs;
		if(cs == 'L'){
			instructions.push_back(-1);
		}
		if(cs == 'R'){
			instructions.push_back(1);
		}
		if(cs == 'F'){
			instructions.push_back(0);
		}
	}
	//CHRONOLOGY
}
