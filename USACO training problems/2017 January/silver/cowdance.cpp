#include <bits/stdc++.h>
using namespace std;
int main(){
	ifstream in("cowdance.in");
	ofstream out("cowdance.out");
	int cows, tMax;
	in >> cows >> tMax;
	vector<int> times;
	for(int i = 0; i < cows; i++){
		int a;
		in >> a;
		times.push_back(a);
	}
	int start = 1;
	int end = cows;
	int ans = cows;
	while(start <= end){
		int mid = start+end;
		mid/=2;
		int ct = 0, cp = 0;
		priority_queue<int> q;
		int size = 0;
		while(size < mid){
			q.push(-times[cp]);
			cp++;
			size++;
		}
		while(q.size() > 0){
			ct+=max(0, -q.top() - ct);
			q.pop();
			if(cp < cows){
				q.push(-times[cp] - ct);
				cp++;
			}
		}
		if(ct > tMax){
			start = mid+1;
		}
		else{
			ans = min(ans, mid);
			end = mid-1;
		}
	}
	out<<ans<<'\n';
}
