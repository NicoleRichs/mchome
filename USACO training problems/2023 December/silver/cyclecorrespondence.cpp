#include <bits/stdc++.h>
using namespace std;
int main(){
	int n, k;
	cin >> n >> k;
	vector<int> a;
	vector<int> b;
	map<int,int> apos;
	map<int,int> bpos;
	map<int,int> tpos;
	set<int> un;
	multiset<int> fun;
	for(int i = 0; i < k; i++){
		int j;
		cin >> j;
		a.push_back(j);
		un.insert(j);
		fun.insert(j);
		apos[j] = i;
	}
	for(int i = 0; i < k; i++){
		int j;
		cin >> j;
		b.push_back(j);
		un.insert(j);
		fun.insert(j);
		bpos[j] = i;
	}
	int ans = n - (un.size());
	vector<int> ts;
	for(int i = 0; i < k; i++){
		if(fun.count(a[i]) == 2){
			ts.push_back(a[i]);
			tpos[a[i]] = i;
		}
	}
	vector<bool> vis(ts.size(), false);
	int it = 0;
	int nans = 0;
	for(int c : ts){
		if(!vis[it]){
			int as = apos[c];
			int bs = bpos[c];
			int gs = 0;
			int bgs = 0;
			for(int i = 0; i < k; i++){
				if(a[(as+i)%k] == b[(bs+i)%k]){
					gs++;
					vis[tpos[a[(as+i)%k]]] = true;
				}
				if(a[(as+i)%k] == b[(bs+k-i)%k]){
					bgs++;
					vis[tpos[a[(as+i)%k]]] = true;
				}
			}
			nans = max(nans, gs);
			nans = max(nans, bgs);
		}
		it++;
	}
	cout<<nans + ans<<'\n';
}
