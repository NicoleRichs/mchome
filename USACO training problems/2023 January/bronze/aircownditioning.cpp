#include <bits/stdc++.h>
using namespace std;
struct ac{
	int a, b, c, d;
};
int main(){
	int cows, cond;
	cin >> cows >> cond;
	int stalls[100]  = {};
	vector<ac> cnd = {};
	for(int i = 0; i < cows; i++){
		int a, b, c;
		cin >> a >> b >> c;
		for(int d = a-1; d <= b-1; d++){
			stalls[d] = -c;
		}
	}
	for(int r = 0; r < cond; r++){
		int a, b, c , d;
		cin >> a >> b >> c >> d;
		a--;b--;
		cnd.push_back({a,b,c,d});
	}
	int an = INT32_MAX;
	for(int bitmask = 0; bitmask < (1 << cond); bitmask++){
		int ca = 0;
		int cs[100] = {};
		for(int a = 0; a < cond; a++){
			if((1<<a)&bitmask){
				ca+=cnd[a].d;
				for(int s = cnd[a].a; s <= cnd[a].b; s++){
					cs[s]+=cnd[a].c;
				}
			}
		}
		bool all_nn = true;
		for(int i = 0; i < 100; i++){
			if(cs[i]+stalls[i] < 0){
				all_nn = false;
			}
		}
		if(all_nn){
			an = min(an, ca);
		}
	}
	cout<<an<<'\n';
}
