#include <bits/stdc++.h>
//BERRIED DELIIIIGHT DEEP WITHIN (my stomach)
//CAST ASIDE, THERE'S NO COOOOOMIIIIIIIING HOOOOOOOOOOOOOOOOOOME
//WE'RE BURNING CHAOOS IN THE WIIIIIIND
//DRIFTING IN THE OCEAAN AAAAAAAALL AALOOOOOONEEEE
using namespace std;
ifstream in("berries.in");
ofstream out("berries.out");
int MOD;
bool cmp(int &a, int &b){
	return (a % MOD) > (b % MOD);
}
void solve(){
	int trees, baskets;
	in >> trees >> baskets;
	vector<int> berrylist;
	int maxBerries = 1;
	for(int i = 0; i < trees; i++){
		int a;
		in >> a;
		berrylist.push_back(a);
		maxBerries = max(maxBerries, a);
	}
	int mb2 = 0;
	for(int b = 1; b <= maxBerries; b++){
		int numBaskets = 0;
		for(int c = 0; c < trees; c++){
			numBaskets+=(berrylist[c] / b);
		}
		if(numBaskets < (baskets/2)){
			continue;
		}
		else if(numBaskets >= baskets){
			mb2 = max(mb2, (baskets/2) * b);
			continue;
		}
		else{
			MOD = b;
			sort(berrylist.begin(),berrylist.end(), cmp);
			int cb = (numBaskets - baskets/2) * b;
			for(int m = 0; m < trees && m + numBaskets < baskets; m++){
				cb+= (berrylist[m] % b);
			}
			mb2 = max(mb2, cb);	
		}	
	}
	out<<mb2<<'\n';
}
int main(){
	solve();
}
