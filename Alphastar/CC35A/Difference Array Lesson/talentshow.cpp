#include <bits/stdc++.h>
using namespace std;
int main(){
	int n, m;
	cin >> n >> m;
	vector<int> nf(m+1, 0);
	vector<int> nb(m+1, 0);
	for(int i = 0; i < n; i++){
		int a, b;
		cin >> a >> b;
		nf[a]++;
		nb[b]++;
	}
	vector<long long> fsa(2 * m + 1, 0);
	vector<long long> fsb(2 * m + 1, 0);
	for(int i = 0; i <= m; i++){
		for(int j = 0; j <= m; j++){
			fsa[i+j]+=(nf[i]*nf[j]);
		}
	}
	for(int i = 0; i <= m; i++){
		for(int j = 0; j <= m; j++){
			fsb[i+j]+=(nb[i]*nb[j]);
		}
	}
	long long fv = fsa[0];
	long long bv = n * n;
	cout<<fv<<'\n';
	for(int i = 1; i <= 2 * m; i++){
		fv+=fsa[i];
		bv-=fsb[i - 1];
		cout<<fv + bv - (n * n)<<'\n';
	}
}
