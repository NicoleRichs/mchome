#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1.5e5 + 15;
int64_t arr[MAXN] = {};
int ord[MAXN] = {};
int unord[MAXN] = {};
int64_t pref[MAXN] = {};
int n = 0;
int64_t origAns = 0;
int64_t findRep(int idx, int64_t val){
        idx = unord[idx];
        int64_t ans = origAns;
        int newidx = lower_bound(arr, arr + n, val) - arr - (bool) (val > arr[idx]);
        ans -= (idx + 1) * arr[idx];
        if (newidx >= idx) 
        {
            ans -= (pref[newidx + 1] - pref[idx + 1]);
        }
        else 
        {
            ans += (pref[idx] - pref[newidx]);
        }
        ans += (newidx + 1) * val;
        return ans;
}
int main(){
	ios_base::sync_with_stdio(false); cin.tie(0);
//	ifstream in("milksum.in");
//	ofstream out("milksum.out");
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}
	iota(ord, ord+n, 0);
	sort(ord, ord+n, [&](int i, int j){
		return arr[i] < arr[j];
	});
	for(int k = 0; k < n; k++){
		unord[ord[k]] = k;
	}
	int64_t rs = 0;
	sort(arr, arr+n);
	for (int i = 0; i < n; i++)
    {
        pref[i + 1] = pref[i] + arr[i];
        origAns += (i + 1) * arr[i];
    }
	int cases = 0;
	cin >> cases;
	for(int i = 0; i < cases; i++){
		int raw;
		int64_t rep;
		cin >> raw >> rep;
		raw--;
		cout<<findRep(raw, rep)<<'\n';
	}
}
