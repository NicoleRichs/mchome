#include <bits/stdc++.h>
using namespace std;
vector<pair<int,int>> coords; //this list is zero-indexed
vector<int> affiliation; //this list is one-indexed. aaaaaaaaaa. stores what group a cow belongs to.
vector<vector<int>> adjlist;
//we dfs over all the children of a node and assign them the group number of the node
void dfs(int node, int group){
	for(int child : adjlist[node]){
		if(affiliation[child] == 0){
			affiliation[child] = group;
			dfs(child, group);
		}
	}
}
int main(){
	ifstream in("fenceplan.in");
	ofstream out("fenceplan.out");
	int cows, edges;
	in >> cows >> edges;
	coords.resize(cows);
	adjlist.resize(cows+1);
	affiliation.resize(cows+1);
	for(int a = 0; a < cows+1; a++){
		affiliation[a] = 0;
	}
	for(int i = 0; i < cows; i++){
		in >> coords[i].first >> coords[i].second;
	}
	for(int k = 0; k < edges; k++){
		int a, b;
		in >> a >> b;
		adjlist[a].push_back(b);
		adjlist[b].push_back(a);
	}
	int groupno = 1;
	for(int c = 1; c < cows+1; c++){
		//go through every cow and if it isn't a part of group, make a new group and dfs through its children and assign them the group.
		if(affiliation[c] == 0){
			affiliation[c] = groupno;
			dfs(c, groupno);
			groupno++;
		}
	}
	//we find the max and min x/y coords of each group
	int minx[groupno+1];
	int miny[groupno+1];
	int maxx[groupno+1] = { 0 };
	int maxy[groupno+1] = { 0 };
	for(int i = 0; i < groupno+2; i++){
		minx[i] = 1e8;
		miny[i] = 1e8;
	}
	for(int t = 0; t < cows; t++){
		if(coords[t].first > maxx[affiliation[t+1]]){
			maxx[affiliation[t+1]] = coords[t].first;
		}
		if(coords[t].second > maxy[affiliation[t+1]]){
			maxy[affiliation[t+1]] = coords[t].second;
		}
		if(coords[t].first < minx[affiliation[t+1]]){
			minx[affiliation[t+1]] = coords[t].first;
		}
		if(coords[t].second < miny[affiliation[t+1]]){
			miny[affiliation[t+1]] = coords[t].second;
		}
	}
	//then we calculate the perimeter of each group and see which one is smollest
	int perim = 4 * 1e8;
	for(int i = 1; i < groupno; i++){
		perim = min(perim, 2*((maxx[i] - minx[i]) + (maxy[i] - miny[i])));
	}
	//then we do the crab rave
	out<<perim<<endl;
	//:b: :fish: 
}
