#include <bits/stdc++.h>
using namespace std;
int pos, cows;
vector<int> locs;
bool splashAll(int rad){
	int launched = 0;
	int p = 0;
	int sp = 0;
	while(p < pos){
		if(sp == p){
			launched++;
			p++;
		}
		else if(locs[p] - locs[sp] > (rad*2)){
			sp = p;
		}
		else{
			p++;
		}
	}
	if(launched > cows){
		return false;
	}
	return true;
}
int main(){
	ifstream in("angry.in");
	ofstream out("angry.out");
	in >> pos >> cows;
	for(int i = 0; i < pos; i++){
		int a;
		in >> a;
		locs.push_back(a);
	}
	sort(locs.begin(),locs.end());
	int lo = 1;
	int max = 1e9/2;
	int ans = (1e9)/2;
	while(lo <= max){
		int mid = lo+max;
		mid/=2;
		if(splashAll(mid)){
			ans = min(ans, mid);
			max = mid-1;
			
		}
		else{
			lo = mid+1;
		}
	}
	out<<ans<<'\n';
}
