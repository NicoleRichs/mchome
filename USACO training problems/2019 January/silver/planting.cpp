#include <bits/stdc++.h>
#include <vector>
#include <utility>
using namespace std;
int main(){
	ifstream in("planting.in");
	ofstream out("planting.out");
	int nodes = 0;
	in >> nodes;
	int edgeList[nodes];
	for(int i = 0; i < nodes; i++){
		edgeList[i] = 0;
	}
	for(int i = 0; i < nodes-1; i++){
		int a,b;
		in >> a;
		in >> b;
		edgeList[a-1]+=1;
		edgeList[b-1]+=1;
//		cout<<"a-1: "<<a-1<<" b-1: "<<b-1<<endl;
	}
	int top = 0;
	for(int i = 0; i < nodes; i++){
//		cout<<"i: "<<i<<" edgelist[i]+1: "<<edgeList[i+1]<<" top: "<<top<<endl;
		if(edgeList[i]+1 > top){
			top = edgeList[i]+1;
		}
	}
	out << top;
}
