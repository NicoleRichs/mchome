#include <bits/stdc++.h>
using namespace std;
int main(){
	int n, k;
	cin >> n >> k;
	vector<int> breeds(500001);
	for(int i = 1; i <= n; i++){
		int a;
		cin >> a;
		breeds[i] = a;
	}
	vector<vector<bool>> compatible(51, vector<bool>(51));
	for(int i = 1; i <= k; i++){
		for(int j = 1; j <= k; j++){
			char c;
			cin >> c;
			if(c == '1'){
				compatible[i][j] = true;
			}
			else{
				compatible[i][j] = false;
			}
		}
		compatible[i][0] = compatible[i][breeds[n]];
	}
	breeds[n] = 0; 
	vector<vector<int>> dist(k+1, vector<int>(n+1,-1));
	deque<pair<int,int>> tp;
	tp.push_front(make_pair(breeds[1],1));
	dist[breeds[1]][1] = 0;
	while(!tp.empty()){
		int cb = (tp.front()).first;
		int cc = (tp.front()).second;
		tp.pop_front();
		if(cc - 1 > 0){
			if(dist[cb][cc - 1] == -1){
				dist[cb][cc - 1] = dist[cb][cc] + 1;
				tp.push_back({cb, cc-1});
			}
		}
		if(cc + 1 <= n){
			if(dist[cb][cc+1] == -1){
				dist[cb][cc+1] = dist[cb][cc] + 1;
				tp.push_back({cb, cc + 1});
			}
		}
		if(compatible[cb][breeds[cc]] && dist[breeds[cc]][cc] == -1){
			//pass the message on
			dist[breeds[cc]][cc] = dist[cb][cc];
			tp.push_front({breeds[cc], cc});
		}
	}
	cout<<dist[0][n]<<'\n';
}
