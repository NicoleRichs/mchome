#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;
bool inval = false;
vector<int> adjlist[MAXN];
vector<bool> colorlist;
vector<int> visited;
void dfs(int node, bool color = 0){
	colorlist[node] = color;
	visited[node] = 1;
	for(int &a : adjlist[node]){
		if(visited[a]){ //no worries about false flagging the parent since the color is different
			if(colorlist[a] == color){
				inval = true;
			}
		}
		else{
				dfs(a,!color); //pretty cool trick, this one
			}
	}
}
int main(){
	int students = 0, friendships = 0;
	cin >> students >> friendships;
	colorlist.resize(students+1);
	visited.resize(students+1);
	fill(colorlist.begin(),colorlist.end(),0);
	fill(visited.begin(),visited.end(),0);
	for(int i = 0; i < friendships; i++){
		int a, b;
		cin >> a >> b;
		a; b; //was originally going to make this 0-indexed but eh that's cringe
		adjlist[a].push_back(b);
		adjlist[b].push_back(a);
	}
	for(int i = 1; i < students+1; i++){
		if(!visited[i]){
			dfs(i);
		}
	}
	if(!inval){
		for(int i = 1; i <= students; i++){
			cout<<colorlist[i]+1<<" ";
		}
		cout<<'\n';
	}
	else{
		cout<<"IMPOSSIBLE"<<'\n'; //just like you
	}
}
