#include <bits/stdc++.h>
using namespace std;
int rep[100000] = {};
int sizes[100000] = {};
int getHead(int a){
	while(rep[a]!=a){
		a = rep[a];
	}
	return a;
}
bool inCC(int a, int b){
	return getHead(a) == getHead(b);
}
int merge(int a, int b){
	if(inCC(a, b)){
		return -1;
	}
	if(sizes[getHead(a)] < sizes[getHead(b)]){
		swap(a, b);
	}
	rep[b] = getHead(a);
	sizes[getHead(a)]+=sizes[b];
	return a;
}
void initDSU(int n){
	for(int i = 0; i < n; i++){
		rep[i] = i;
		sizes[i] = 1;
	}
}
int main(){
	int n, m;
	cin >> n>> m;
	initDSU(n);
	for(int i = 0; i < m; i++){
		int a, b;
		cin >> a >> b;
		a--, b--;
		int res = merge(a, b);
		if(res == -1){
			cout<<"YES"<<'\n';
			return 0;
		}
	}
	cout<<"NO"<<'\n';
}
