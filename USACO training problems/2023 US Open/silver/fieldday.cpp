#include <bits/stdc++.h>
using namespace std;
int main(){
	int c = 0, n = 0;
	queue<int> tp;
	cin >> c >> n;
	int teams[n] = {};
	int distances[(1 << c)];
	for(int i = 0; i < (1 << c); i++){
		distances[i] = -1;
	}
	for(int j = 0; j < n; j++){
		string ct;
		cin >> ct;
		int an = 0;
		int cp = 0;
		for(int k = c-1; k >=0; k--){
			if(ct[k] == 'H'){
				an += (1 << cp); 
			}
			cp++;
		}
		teams[j] = an;
		distances[an] = 0;
		tp.push(an);
	}
//	cout<<distances[1]<<'\n';
	while(!tp.empty()){
		int cur = tp.front();
//		cout<<"Processing "<<cur<<'\n';
		tp.pop();
		for(int a = 0; a < c; a++){
			int nex = (cur ^ (1 << a));
//			cout<<"attempted "<<nex<<'\n';
			
			if(distances[nex] == -1){
				distances[nex] = distances[cur]+1;
				tp.push(nex);
//				cout<<nex<<'\n';
			}
//			else{
//				cout<<"Failed "<<nex<<" value at "<<distances[nex]<<'\n';
//			}
		}
	}
	for(int b = 0; b < n; b++){
		cout<<(c - distances[((1 << c) - 1) ^ teams[b]])<<'\n';
	}
}
