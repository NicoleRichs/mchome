#include <bits/stdc++.h>
using namespace std;
int main(){
	vector<int> myArr;
	int n; cin >> n;
	for(int i = 0; i < n; i++){int a; cin >> a; myArr.push_back(a);};
	vector<int> tail;
	for(int i = 0; i < n; i++){
//		cout<<i<<'\n';
		int cur = myArr[i];
		if(tail.size() == 0){
			tail.push_back(cur);
		}
		else if(tail[tail.size() - 1] < cur){
			tail.push_back(cur);
		}
		else{
			for(int j = 0; j < tail.size(); j++){
				if(myArr[i] < tail[j]){
					tail[j] = myArr[i];
					break;
				}
				else if(myArr[i] == tail[j]){ //had to account for this, it's an increasing subsequence after all
					break;
				}
			}
		}
	}
	cout<<tail.size()<<'\n';
}
