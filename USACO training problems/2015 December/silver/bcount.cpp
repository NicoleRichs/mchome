#include <bits/stdc++.h>
using namespace std;
int main(){
	int cows, queries;
	ifstream in("bcount.in");
	ofstream out("bcount.out");
	in >> cows >> queries;
	int pref[cows+1][4];
	pref[0][0] = 0;
	pref[0][1] = 0;
	pref[0][2] = 0;
	pref[0][3] = 0;
	for(int i = 1; i < cows+1; i++){
		int breed;
		in >> breed;
		if(breed == 1){
			pref[i][1] = pref[i-1][1]+1;
			pref[i][2] = pref[i-1][2];
			pref[i][3] = pref[i-1][3];
		}
		else if(breed == 2){
			pref[i][1] = pref[i-1][1];
			pref[i][2] = pref[i-1][2]+1;
			pref[i][3] = pref[i-1][3];
		}
		else if(breed == 3){
			pref[i][1] = pref[i-1][1];
			pref[i][2] = pref[i-1][2];
			pref[i][3] = pref[i-1][3]+1;
		}
	}
	for(int k = 0; k < queries; k++){
		int a,b;
		in >> a >> b;
		int n1 = pref[b][1] - pref[a-1][1];
		int n2 = pref[b][2] - pref[a-1][2];
		int n3 = pref[b][3] - pref[a-1][3];
		out<<n1<<" "<<n2<<" "<<n3<<endl;
	}
}
