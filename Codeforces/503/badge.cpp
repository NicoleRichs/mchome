#include <bits/stdc++.h> 
using namespace std;
//idea:
//My code for the CSES problem planet cycle, but instead of counting the number of nodes in the cycle + the number of nodes removed, it's just the member of the cycle closest to the node.
const int MAXN = 2 * 1e5;
vector<int> revAdj[MAXN];
vector<int> adj[MAXN];
int group[MAXN] = {};
vector<int> dirG;
int answers[MAXN] = {};
vector<vector<int>> cyclical = {};
vector<int> groupStarts;
vector<int> cycleSums;

void findGroup(int node, int g){ //using dfs to find CCs.
	group[node] = g;
	for(int a : adj[node]){
		if(group[a]==0){
			findGroup(a,g);
		}
	}
}

void Floyd(int node){ //standard Floyd algo with some modifications
	int p1 = node;
	int p2 = node;
	do{
		p1 = dirG[p1];
		p2 = dirG[dirG[p2]];
	}while(p1!=p2);
	p1 = node;
	while(p1 != p2){
		p1 = dirG[p1];
		p2 = dirG[p2];
	}
	int ta = 1;
	vector<int> tempc;
	tempc.push_back(p2); //this stores all the nodes that are in this cc's cycle
	p2 = dirG[p2];
	while(p1!=p2){
		ta++;
		tempc.push_back(p2);
		p2 = dirG[p2];
	}
	for(int a : tempc){ //setting all the answers of the nodes in the cycle to themselves
		answers[a] = a+1;
	}
	cyclical.push_back(tempc); //2d vector of the vectors containing the cyclical nodes for each group
	cycleSums.push_back(ta); //vector of the number of nodes in a cycle for each group
}

void revDFS(int node, int cs){//DFS'ing through the reverse adjacency list of the node
	answers[node] = cs; //cs is the node closest in the cycle
//	cout<<"aa";
	for(int c : revAdj[node]){
		if(answers[c] == 0){ //this is why I had to assign the answers for each cyclical node in each group back in the floyd function, it was repeatedly DFSing already visited nodes
			revDFS(c, cs);//since each unvisited child is one more step removed from the cyclem, the answer goes up by 1	
		}
		
	}
}

void fillAnswers(int group){
	for(int c : cyclical[group-1]){ //just going through each cyclical node in the given group and DFSing through its reverse adjacency list and filling out the answers
//		cout<<"RevDFS"<<'\n';
		revDFS(c, c+1);
	}
}

int main(){
	int planets;
	cin >> planets;
	for(int i = 0; i < planets; i++){
		int a;
		cin>> a;
		a--;
		dirG.push_back(a);
		adj[i].push_back(a);
		adj[a].push_back(i);
		revAdj[a].push_back(i);
	}
//	cout<<"BP1"<<'\n';
	int cg = 1;
	for(int j = 0; j < planets; j++){
		if(group[j] == 0){
			groupStarts.push_back(j);
			findGroup(j,cg);
			cg++;
		}
	}	
//	cout<<"BP2"<<'\n';
	cg = 1;
	for(int s : groupStarts){
		Floyd(s);
//		cout<<"BP3"<<'\n';
		fillAnswers(cg);
//		cout<<"BP4"<<'\n';
		cg++;
	}
//	cout<<"BP5"<<'\n';
	for(int a = 0; a < planets; a++){
		cout<<answers[a]<<" ";
	}
	cout<<'\n';
}
