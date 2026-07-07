//literally whipping this together in an apartment rented for ski trip in Utah while my friends and sister are playing sorry right next to me, gotta stay on that grindset
//average dfs enjoyer vs average bfs enjoyer
#include <bits/stdc++.h>
using namespace std;
const int MAX = 3000;
vector<vector<int>> adjlist(MAX);
vector<int> visited(MAX);
vector<int> closed(MAX);
int nodes = 0;

void dfs(int node){
	//DFS DFS DFS DFS DFS DFDS DFSDFDSFDSF DFDSDS FDSF SD DSF DSF DS fDS FDS FSDF
	//Basic DFS but we stop it both when the node is visited and when it is closed
	if(visited[node] || closed[node]){
		return;	
	}
	nodes++;
	visited[node] = true;
	for(int child : adjlist[node]){
		if(!visited[child]){
			dfs(child);
		}
	}
}
int main(){
	
	ifstream in("closing.in");
	ofstream out("closing.out");
	int roads, barns;
	in >> barns >> roads;
	
	for(int i = 0; i < roads; i++){
		int a, b;
		in >> a >> b;
		adjlist[a].push_back(b);
		adjlist[b].push_back(a);
	}
	
	vector<int> closeOrd(MAX);
	for(int l = 0; l < barns; l++){
		int temp;
		in >> temp; 
		//unsure as to why but push_back(temp) doesn't work
		closeOrd[l] = (temp);
	}
	dfs(1);
	//check initial condition
	if(nodes == barns){
		out<<"YES"<<endl;
	}
	else{
		out<<"NO";
	}
//	for(int t = 0; t < barns; t++){
//		cout<<closeOrd[t]<<endl;
//	}
	for(int k = 0; k < barns-1; k++){
		//resets the nodes visited, closes the current to close, then resets the visited vector.
		nodes = 0;
		closed[closeOrd[k]] = true;
		fill(visited.begin(), visited.end(), false);
		//dfs from the last barn to close.
		dfs(closeOrd[barns-1]);
		//checking if the amount of nodes visited = the amount of barns still open
		if(nodes == barns-k-1){
			out<<"YES"<<endl;
		}
		else{
			out<<"NO"<<endl;
		}
	}
	
}
