#include <bits/stdc++.h>
using namespace std;
bool cmp2(pair<int,bool> a, pair<int,bool> b){
	return a.first < b.first;
}
int main(){
	int n, x, y, z;
	cin >> n >> x >> y >> z;
	vector<pair<int,bool>> ep;
	for(int i = 0; i < n; i++){
		int a, b;
		cin >> a >> b;
		ep.push_back({a, true});
		ep.push_back({b + 1, false});
	}
	long long n1 = n;
	long long n2 = 0;
	long long n3 = 0;
	sort(ep.begin(), ep.end(), cmp2);
	long long cm = n1 * x;
	for(int i = 0; i < n * 2; i++){
		int cn = ep[i].first;
		bool is = ep[i].second;
		if(is){
			n1--;
			n2++;
		}
		else{
			n2--;
			n3++;
		}
		while(i < n * 2 - 1 && ep[i+1].first == ep[i].first){
			i++;
			cn = ep[i].first;
			is = ep[i].second;
			if(is){
				n1--;
				n2++;
			}
			else{
				n2--;
				n3++;
			}
		}
		cm = max(cm, (n1 * x) + (n2 * y) + (n3 * z));
	}
	cout<<cm<<'\n';
}
