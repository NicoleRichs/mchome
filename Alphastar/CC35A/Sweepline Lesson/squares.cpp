#include <bits/stdc++.h>
using namespace std;
struct point{
	int x, y;
};
bool cmpx(point a, point b){
	return a.x < b.x;
}
bool cmpy(point a, point b){
	return a.y < b.y;
}
//wait this wasn't supposed to work
int main(){
	int n, k;
	cin >> n >> k;
	vector<point> cx;
	for(int i = 0; i < n; i++){
		int a, b;
		cin >> a >>b;
		cx.push_back({a,b});
	}
	sort(cx.begin(), cx.end(), cmpx);
	//strange "two pointers" x sweepline sol
	//see which squares ahead of the current x-coordinate are in range of overlap (center's x is greater than cur x, small enough so they can overlap assuming y works
	//at the beginning of each iteration, update these values keeping in mind they only go up since list is sorted
	//then go through all valid squares and see if one works
	//if one works and the answer isn't overwritten overwrite it
	//otherwise print -1 and die
	int begin = 0;
	int end = 1;
	int ans = -3;
	for(int i = 0; i < n; i++){
		if(cx[begin].x <= cx[i].x){
			while(cx[begin].x <= cx[i].x && begin < n){
				begin++;
			}
		}
		while(end < n && cx[end].x - (k/2) < (cx[i]).x + (k/2)){
			end++;
		}
		for(int j = begin; j < end; j++){
//			cout<<i<<" "<<j<<'\n';
			if(abs(cx[j].y - cx[i].y) < k && i!=k){
				if(ans != -3){
					cout<<-1<<'\n';
					return 0;
				}
				else{
					ans = ((k - abs(cx[j].x - cx[i].x)) * (k - abs(cx[j].y - cx[i].y)));
				}
			}
		}
	}
	if(ans == -3){
		ans = 0;
	}
	cout<<ans<<'\n';
}
