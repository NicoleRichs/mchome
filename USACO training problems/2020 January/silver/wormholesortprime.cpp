#include <bits/stdc++.h>
using namespace std;
//the basic idea for this program is to binary search the width, and to see if every cow is in a connected component with its destination.
int main(){
	ifstream in("wormsort.in");
	ofstream out("wormsort.out");
	int cows, holes, maxw = 0;
	in >> cows >> holes;
	vector<int> cowpos(cows);
	for(int i = 0; i < cows; i++){
		int a;
		in >> a;
		a--;
		cowpos[i] = a;
	}
	vector<pair<int,int>> adjlist[cows];
	for(int j = 0; j < holes ;j++){
		int a, b, w;
		in >> a >> b >> w;
		adjlist[a-1].push_back({b-1,w});
		adjlist[b-1].push_back({a-1,w});
		maxw = max(maxw, w);
	}
	bool alreadySorted = true;
	for(int lol = 0; lol < cows; lol++){
		if(lol!=cowpos[lol]){
			alreadySorted = false;
			break;
		}
	}
	if(alreadySorted){
		out<<-1<<'\n';
		return 0;
	}
	int smol = 0;
	int big = maxw+1;
	int cv = -1;
	while(smol <= big){
		int mid = (smol + big)/2;
		vector<int> group(cows, -1);
		int cc = 0;
		for(int c = 0; c < cows; c++){
			if(group[c]!=-1){
				continue;
			}
			else{
				vector<int> tp{c};
				while(!tp.empty()){
					int curr = tp.back();
					tp.pop_back();
					group[curr] = cc;
					for(pair<int,int> &p : adjlist[curr]){
						if(group[p.first] == -1 && p.second >= mid){
							tp.push_back(p.first);
						}
					}
				}
				cc++;
			}
		}
		bool cs = true;
		for(int d = 0; d < cows; d++){
			if(group[d]!=group[cowpos[d]]){
				cs = false;
				break;
			}
		}
		if(cs){
			smol = mid+1;
			cv = mid;
		}
		else{
			big = mid-1;
		}
	}
	out<<cv<<'\n';
}
