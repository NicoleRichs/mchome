#include <bits/stdc++.h>
using namespace std;
int main(){
	int children, max;
	cin >> children >> max;
	vector<int> weights(children);
	for(int& n : weights){
		cin >> n;
	}
	sort(weights.begin(),weights.end());
	int curChild = 0;
	int s = children-1;
	set<int> done;
	int ans = 0;
	for(curChild; curChild < children; curChild++){
		bool fitTwo = false;
		if(done.find(curChild) == done.end()){
			while(s >= curChild){
				if(done.find(s) == done.end()){
					if(weights[curChild] + weights[s] > max){
					s--;
					ans++;
					done.insert(s+1);
					}
					else{
						done.insert(curChild);
						done.insert(s);
						ans++;
						s--;
						break;
					} 
				}
				else{
					s--;
				}
			}		
		}		
	}
	cout<<ans;

}
