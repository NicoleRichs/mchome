#include <bits/stdc++.h>
//is this even dfs?? eh sorta
using namespace std;

vector<vector<bool>> connected; //this one stores true/false if a cow can reach another cow
vector<bool> visited; //this one stores if we've visited a node. is reset every time we run the dfs

int cows;

struct cow{
	int x, y, p;
};

int reach(int cow){
	visited[cow] = true;
	//the original cow counts
	int reached = 1;
	for(int cc = 0; cc < connected.size(); cc++){ //i guess this replaces our adjacency list
		if(connected[cow][cc] && !visited[cc]){
			visited[cc] = true;
			reached+=reach(cc); //the other cows transmit to all in their range
		}
	}
	return reached;
}
int main(){
	ifstream in("moocast.in");
	ofstream out("moocast.out");
	in >> cows;
	vector<cow> coords(cows);
	for(int i = 0; i < cows; i++){
		in >> coords[i].x >> coords[i].y >> coords[i].p;
	}
	//tbh still not sure how this line works but it sure does
	connected = vector<vector<bool>>(cows, vector<bool>(cows));
	for(int a = 0; a < cows; a++){
		for(int b = 0; b < cows; b++){
			//we're manually looping thru all coords to see if they can connect. Thanks to the low N limit we can do this comfortably.
			int distSquared = ((coords[a].x - coords[b].x)*(coords[a].x - coords[b].x)) + ((coords[a].y - coords[b].y) * (coords[a].y - coords[b].y));
			connected[a][b] = (distSquared <= (coords[a].p * coords[a].p));
		}
	}
	int maxcows = 0;
	for(int i = 0; i < cows; i++){
		//we run the dfs for all nodes and see which one gets the largest
		visited.assign(cows, false);
		maxcows = max(maxcows, reach(i));
	}
	out<<maxcows<<endl; //das feesh bruh
}
