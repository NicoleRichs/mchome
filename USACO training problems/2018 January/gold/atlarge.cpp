#include <bits/stdc++.h>
using namespace std;
vector<int> adj[100000];
const int INF = 2000000000;
int main(){
	//the idea is to BFS from the root of the tree to find min-dist from the root to every node. Then we have a multi-source BFS from all leaf nodes to find min-dist between all leaves to each node. Then we BFS from the start and find
	//the earliest point in each subtree where the distance from bessie's node is greater or equal to the minimum distance from a leaf node. We can then position each farmer optimally to intercept Bessie at one of these points, thus giving
	//the answer.
	ifstream in("atlarge.in");
	ofstream out("atlarge.out");
	int n, k;
	in >> n >> k;
	k--;
	for(int i = 0; i < n-1; i++){
		int a, b;
		in >> a >> b;
		a--;b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	vector<int> distB(n, INF);
	vector<int> distF(n, INF);
	distB[k] = 0;
	queue<int> q;
	q.push(k);
	//bfsing bessie distances
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (int u : adj[cur]) {
//			cout<<distB[u]<<" "<<distB[cur]<<'\n';
			if (distB[cur] + 1 < distB[u]) {
				distB[u] = distB[cur] + 1;
				q.push(u);
			}
		}
	}
//	for(int i = 0; i < n; i++){
//		cout<<distB[i]<<'\n';
//	}
	//finding all the leaf nodes and adding them to queue
	for(int i = 0; i < n; i++){
		if(adj[i].size() == 1){
			q.push(i);
			distF[i] = 0;
		}
	}
	//copy-and-paste from above.
	while(!q.empty()){
		int cn = q.front();
		q.pop();
		for(int a : adj[cn]){
			if(distF[a] > distF[cn] + 1){
				distF[a] = distF[cn] + 1;
				q.push(a);
			}
		}
	}
	//rounding up our answers
	int res = 0;
	q.push(k);
	vector<bool> vis(n);
	while(!q.empty()){
		int cur = q.front();
		q.pop();
		if(distB[cur] >= distF[cur]){
			res++;
			continue; //so we don't add the neighbors of the node, since that would result in an overcount
		}
		if(vis[cur]){
			continue; //prevent us from double counting nodes
		}
		vis[cur] = true; //adding the neighbors to the queue
		for(int a : adj[cur]){
			q.push(a);
		}
	}
	out<<res<<'\n';
}
