#include <bits/stdc++.h>
using namespace std;
bool cmp2(pair<int,bool> a, pair<int,bool> b){
	return a.first < b.first;
}
int main(){
	vector<pair<int,bool>> ms;
	int n, a, b;
	cin >> n >> a >> b;
	for(int i = 0; i < n; i++){
		char c;
		cin >> c;
		if(c == 'N'){
			char chaff;
			cin >> chaff;
		}
		int w;
		cin >> w;
		ms.push_back({w, ((c == 'S')? true : false)}); //this is a "ternary conditional operator" and the syntax is (condition)? true val : false val
	}
	sort(ms.begin(), ms.end(), cmp2);
	int sc = 0;
	if(a < ms[0].first){
		if(ms[0].second){
			sc+=(ms[0].first - a);
		}
	}
	if(b >= ms[n-1].first){
		if(ms[n-1].second){
			sc+=(b - ms[n-1].first + 1);
		}
	}
	for(int i = 0; i < n - 1; i++){
		bool cur = ms[i].second;
		int x = ms[i].first;
		int y = ms[i+1].first;
		bool n = ms[i+1].second;
		if(x < a && y < a){
			continue;
		}
		else if(x > b && y > b){
			break;
		}
		else if(x < a && y >= a){
			if(cur && n){
				sc+=(y - a);
			}
			else if(cur && !n){
				sc+=max(((y - x + 1) - ((y - x + 1)/2)) - (a - x), 0);
			}
			else if(n && !cur){
				sc+=min(((y - x + 1) - ((y - x + 1)/2)), (y - a + 1));
				sc--;
			}
		}
		else if(x <= b && y > b){
			if(cur && n){
				sc+=(b - x + 1);
			}
			else if(cur && !n){
				sc+=max(b - x + 1, (y - x + 1) - ((y - x + 1)/2));
			}
			else if(n && !cur){
				sc+=max(((y - x + 1) - (y - x + 1)/2) - (y - b), 0);
			}
			break;
		}
		else{
			if(cur && n){
				sc+=(y - x);
			}
			else if(cur || n){
				sc+=((y - x + 1) - ((y - x + 1)/2));
				if(n){
					sc--;
				}
			}
			
		}
	}
	cout<<sc<<'\n';
}