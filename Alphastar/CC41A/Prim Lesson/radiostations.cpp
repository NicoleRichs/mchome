#include <bits/stdc++.h>
using namespace std;
long long getdist(long long a, long long b){
	if(a > b){
		swap(a, b);
	}
	return ((2019201913ll * (a+1)) + (2019201949ll * (b+1)))%2019201997ll;
}
int main(){
	//basic idea: take advantage of low N limit to calculate distance from all nodes to another, creating a graph
	//create an MST
	//eliminate the k-1 highest edges, effectively creating k groups
	//the new highest edge is the answer
	int n, k;
	cin >> n >> k;
	long long dists[7500] = {};
	bool vis[7500] = {};
	for(int i = 0; i < n; i++){
		dists[i] = 2147483647;
		vis[i] = false;
	}
	dists[0] = 0;
	long long cn = 0;
	vector<int> edgeval;
	stack<long long> h;
	for(int i = 0; i < n-1; i++){
//		cout<<"CUR NODE IS "<<cn<<'\n';
		vis[cn] = true;
		h.push(cn);
		int cm = 2147483647;
		int nn = -1;
		for(int j = 0; j < n; j++){
			long long cd = getdist(cn, j);
//			cout<<cn+1<<" "<<j+1<<" "<<getdist(cn, j)<<'\n';
			if(cd < dists[j]){
				if(!vis[j]){
//					cout<<'a'<<'\n';
					dists[j] = cd;
//					cout<<dists[j]<<'\n';
				}
			}
			if(!vis[j]){
//				cout<<dists[j]<<'\n';
				if(dists[j] < cm){
					cm = dists[j];
					nn = j;
				}
			}		
		}
		edgeval.push_back(cm);
		cn = nn;
	}
	sort(edgeval.begin(),edgeval.end());
	cout<<edgeval[n - k]<<'\n';
}
