#include <bits/stdc++.h>
using namespace std;
//this is VERY similar to the USACO Silver problem No Time to Paint from January 2021. SUS.
int main(){
	int n, w;
	cin >> n >> w;
	stack<int> heights;
	int buildings = 0;
	heights.push(0);
	for(int i = 0; i < n; i++){
		int a, b;
		cin >> a >> b;
		while(heights.top() > b){
//			cout<<"REMOVED "<<heights.top()<<'\n';
			heights.pop();
		}
		if(heights.top() < b){
//			cout<<"ADDED NEW BUILDING"<<a<<" "<<b<<'\n';
			heights.push(b);
			buildings++;

		}
	}
	cout<<buildings<<'\n';
}
