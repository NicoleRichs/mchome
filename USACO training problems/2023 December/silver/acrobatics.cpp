#include <bits/stdc++.h>
using namespace std;
struct cow{
	int w, n;
};
bool cmp3(cow a, cow b){
	return a.w < b.w;
}
int main(){
	int n, m, k;
	cin >> n >> m >> k;
	vector<cow> cows;
	for(int i = 0; i < n; i++){
		int a, b;
		cin >> a >> b;
		cows.push_back({a, b});
	}
	sort(cows.begin(), cows.end(), cmp3);
	int mp = 0;
	vector<int> startPos;
	for(int i = 0; i < n; i++){
		for(mp; mp < n; mp++){
			if((cows[mp]).w - (cows[i]).w >= k){
				break;
			}	
		}
		
		startPos.push_back(mp);
	}
	int start = 0;
	int sum = 0;
	int counter = 0;
	while(start < n && counter < m){
		for(start; start< n; start++){
			if((cows[start]).n > 0){
				break;
			}
		}
		int c = start;
		int curs = 0;
		while(c < n){
			cows[c].n--;
			curs++;
			for(startPos[c]; startPos[c] <=n; startPos[c]++){
				if(cows[startPos[c]].n > 0){
					break;
				}
			}
			c = startPos[c];
		}
		sum+=curs;
		counter++;
	}
	cout<<sum<<'\n';
}
