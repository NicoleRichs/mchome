#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	ifstream in("superbull.in");
	ofstream out("superbull.out");
	in >> n;
//	cin >> n;
	vector<int> teams;
	for(int i = 0; i< n; i++){
		int t;
		in >> t;
//		cin >> t;
		teams.push_back(t);
	}
	bool vis[n];
	int score[n];
	for(int i=  0; i< n; i++){
		vis[i] = false;
		score[i] = 0;
	}
	long long maxs = 0;
	for(int i = 0; i < n; i++){
		int cn = -1;
		for (int j = 0; j < n; j++) {
			if (vis[j]){
				continue;
			}
			if(cn == -1 || score[cn] < score[j]){
				cn = j;
			}
		}
		maxs+=score[cn];
		vis[cn] = true;
		for(int k = 0; k < n; k++){
			if(!vis[k]){
				score[k] = max(score[k], (teams[k] ^ teams[cn]));
			}
		}
	}
//	cout<<maxs<<'\n';
	out<<maxs<<'\n';
}	
