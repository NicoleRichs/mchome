#include <bits/stdc++.h>
using namespace std;
int n, xs, ys, xe, ye;
const int INF = 2147483647;
unordered_map<int,vector<int>> xl;
unordered_map<int,vector<int>> yl;
vector<pair<int,int>> posts;
int main(){
	ifstream in("lasers.in");
	ofstream out("lasers.out");
	in >> n;
	for(int i = 0; i < n + 2; i++){
		int a, b;
		in >> a >> b;
		posts.push_back(make_pair(a,b));
		xl[a].push_back(i);
		yl[b].push_back(i);
	}
	vector<int> dist(n + 2, INF);
	dist[0]= 0;
	queue<pair<int,bool>> tp;
	tp.push({0,true});
	tp.push({0,false});
	while(!tp.empty()){
		//directions: true is horizontal, false is vertical
		int cn = (tp.front()).first; //index of the point
		bool cd = (tp.front()).second; //direction
		tp.pop();
		if(cd){
			for(int point : xl[posts[cn].first]){
				if(dist[point] == INF){
					tp.push({point, false});
					dist[point] = dist[cn] + 1;
				}
			}
		}
		else{
			for(int point : yl[posts[cn].second]){
				if(dist[point] == INF){
					tp.push({point, true});
					dist[point] = dist[cn] + 1;
				}
			}
		}
	}
	if(dist[1] == INF){
		out<<-1<<'\n';
	}
	else{
		out<<dist[1] - 1<<'\n';
	}
}
