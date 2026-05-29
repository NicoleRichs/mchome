#include <bits/stdc++.h>
using namespace std;
int main(){
	int n, m, k;
	cin >> n >> m >> k;
	vector<int> sizes(n);
	vector<int> apartments(m);
	for(int& t : sizes){
		cin >> t;
	}
	for(int& a : apartments){
		cin >> a;
	}
	sort(sizes.begin(),sizes.end());
	sort(apartments.begin(),apartments.end());
	int ca = 0;
	int ct = 0;
	int ans = 0;
	for(ca; ca < m; ca++){
		if(ct < n){
			int tempsearch = ct;
			while(tempsearch < n){
				if(abs(sizes[tempsearch] - apartments[ca]) <= k){
					ct = tempsearch+1;		
					ans++;
	//				cout<<sizes[tempsearch]<<" "<<apartments[ca]<<endl;
					break;
				}
				else if (sizes[tempsearch] > apartments[ca]){
					ct = tempsearch;
					break;
				}
				else{
					tempsearch++;
				}
			}	
		}	
	}
	cout<<ans<<endl;
};

