//strangest implementation ever
//tl;dr enpoints (sorta sweepline?) + difference array
#include <bits/stdc++.h>
using namespace std;
int main(){
	int n, k;
	cin >> n >> k;
	map<int, int> pts;
	int cp = 0;
	pts[0] = 0;
	for(int i = 0; i < n; i++){
		int a;
		char b;
		cin >> a >> b;
		int np = cp;
		if(b == 'R'){
			np+=a;
		}
		if(b == 'L'){
			np-=a;
		}
		
		if(pts.count(np) == 0){
			pts[np] = 0;
		}
		if(np > cp){
			pts[np]--;
			pts[cp]++;
		}
		else{
			pts[np]++;
			pts[cp]--;
		}
		cp = np;
	}
	map<int,int>::iterator cm = pts.begin();
	int cl = 0;
	int prevX = 0;
	int ans = 0;
	for(cm = pts.begin(); cm != pts.end(); cm++){
		if(cl >= k){
			ans+=(abs(prevX - (cm->first)));
		}
		cl+=(cm->second);
		prevX = (cm->first);
	}
	cout<<ans<<'\n';
}
