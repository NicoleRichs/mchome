#include <bits/stdc++.h>
using namespace std;
vector<int> rep(100000);
vector<int> sizes(100000);
/**
Basic idea is to use a DSU to create and mantain connected components of relevence. We can start with the highest relevence queries, adding the highest relevence edges as that'll be the most restrictive. 
Then as we work our way down we keep adding edges, so we only need to add edges N-1 times at most.
**/
struct request{
	int kilo, vid, id; //kilo =k-value. vid = query for video. id =order it appears in so we output the correct answer for each line
};
struct edge{
	int a, b, w;
};
vector<edge> edges;
bool feeshSort(request a, request b){ //sorts requests by descending k-value
	return a.kilo > b.kilo;
}
bool kompotSort(edge a, edge b){ //sorts edges by decreasing relevence
	return a.w > b.w;
}
int getRep(int a){ //gets the root of the tree that our node is in
	while(rep[a]!=a){
		a = rep[a];
	}
	return a;
}
bool inCC(int a, int b){ //checkse if the two nodes are in the same tree
	return getRep(a) == getRep(b);
}
int getSize(int a){ //size of tree
	return sizes[getRep(a)];
}
int unite(int a, int b){ //unioning
	if(!inCC(a, b)){ //check if we can actually add the edge
		if(getSize(a) < getSize(b)){
			swap(a,b);
		}
		//we make the smaller tree a child of the beeg tree
		sizes[getRep(a)]+=getSize(b);
//		cout<<sizes[getRep(a)]<<'\n';
		rep[getRep(b)] = getRep(a);
		return getRep(a);
	}
	return -1;
}
int main(){
	int n, q;
	ifstream in("mootube.in");
	ofstream out("mootube.out");
//	cin >> n >> q;
	in >> n>> q;
	for(int i = 0; i < n; i++){
		rep[i] = i;
		sizes[i] = 1;
	}
	for(int i = 0; i < n-1; i++){
		int a, b, c;
//		cin >> a >> b >> c;
		in >> a >> b >> c;
		a--; b--;
		edges.push_back({a,b,c});
	}
	vector<int> answerarr(100000, -1); //ordered answers
	vector<request> requests; //sorted requests by descendin k
	for(int i = 0; i < q; i++){
		int a, b;
//		cin >> a >> b;
		in >> a >> b;
		b--;
		requests.push_back({a, b, i});
	}
	//sort everything by descending k
	sort(requests.begin(),requests.end(), feeshSort);
	sort(edges.begin(), edges.end(), kompotSort);
	int ci = 0; //current edge index, we will never need to backtrack
	for(int c = 0; c < q; c++){
		int v = requests[c].vid;
		int k= requests[c].kilo;
		int loc = requests[c].id;		
//		cout<<v<<" "<<k<<" "<<loc<<'\n';
		while(ci < n && edges[ci].w >= k){
			unite(edges[ci].a, edges[ci].b); //keep adding edges until we can't
			ci++;
		}
//		cout<<getSize(v) -1 <<" goes to "<<loc<<'\n';
		answerarr[loc] = getSize(v) - 1; //-1 to account for the node itself not counting
	}
	for(int i = 0; i < q; i++){
//		cout<<answerarr[i]<<'\n'; 
		out<<answerarr[i]<<'\n';
	}
}
