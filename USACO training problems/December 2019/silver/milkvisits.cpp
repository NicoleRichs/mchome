#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5+10;
vector<int> adjlist[MAXN];
vector<int> group(MAXN, -1);
vector<char> breed;
vector<char> ccbreed; 
int main(){
	ifstream in("milkvisits.in");
	ofstream out("milkvisits.out");
	int n, m;
	in >> n >> m;
	for(int i = 0; i < n; i++){
		char c;
		in >> c;
		breed.push_back(c);
	}
	for(int j = 0; j < n-1; j++){
		int a, b;
		in >> a >> b;
		a--; b--;
		adjlist[a].push_back(b);
		adjlist[b].push_back(a);
	}
	int curcomponent = 0;
	for(int f = 0; f < n; f++){
		if(group[f]!=-1){
			continue;
		}
		else{
			vector<int> tp = {f};
			char type = breed[f];
			while(!tp.empty()){
				int curr = tp.back();
				tp.pop_back();
				group[curr] = curcomponent;
				for(int n : adjlist[curr]){
					if(breed[n] == type && group[n] == -1){
						tp.push_back(n);
					}
				}
			}
			curcomponent++;
		}
	}
	for(int c = 0; c < m; c++){
		int a, b;
		char milk;
		in >> a >> b >> milk;
		a--; b--;
		if(group[a] == group[b] && breed[a] == milk){
			out<<1;
		}
		else if(group[a]!=group[b]){
			out<<1;
		}
		else{
			out<<0;
		}
	}
	out<<'\n';
}
