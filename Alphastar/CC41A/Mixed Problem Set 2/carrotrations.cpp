/***
honestly an absolute nightmare to implement
most of my issues boiled down to just not resetting states properly after each binary search
both the degree array and the adjacency list weren't being reset originally which was stupid, so I ended up with super wonky answers
other than that honestly not too bad, just a bit of thot required (not like i have any in my head or bed lol)
Either way, good to be back. Been living pretty degenerate these few weeks, feels like I just can't get a grip. Hopefully this is good news.
-Dilet, 08/22/2023 1600PST
***/
#include <bits/stdc++.h>
using namespace std;
int main(){
	int n, m;
	cin >> n >> m;
	vector<vector<int>> reqs(m);
	for(int i = 0; i < m; i++){
		int a;
		cin >> a;
		vector<int> temp;
		for(int k = 0; k < a; k++){
			int f;
			cin >> f;
			temp.push_back(f);
		}
		reqs[i] = temp;
//		cout<<"input successful"<<'\n';
	}
	
	int l = 1;
	int r = m;
	vector<int> ordering(n);	
	while(l <= r){
		vector<int> degs(100001, 0);
		vector<vector<int>> adj(n+1);	
		vector<int> tempord(n);
		int mid = (l+r)/2;
		cout<<mid<<'\n';
		//construct graph
		for(int i = 0; i < mid; i++){
			vector<int> cl = reqs[i];
			for(int k = 0; k+1 < cl.size(); k++){
				degs[cl[k+1]]++;
				adj[cl[k]].push_back(cl[k+1]);
			}
		}
		//attempt to resolve
		priority_queue<int, vector<int>, greater<int>> tp;
		//dw we only need to do this once
		for(int i = 1; i <= n; i++){
			if(degs[i] == 0){
				tp.push(i);
			}
		}
//		for(int i = 1; i <= n; i++){
//			cout<<degs[i]<<'\n';
//			cout<<i<<" "<<'\n';
//			for(int a : adj[i]){
//				cout<<a<<" ";
//			}
//			cout<<'\n';
//		}		
		int processed = 0;
		while(!tp.empty()){
			processed+=1;
			int cur = tp.top();
			tp.pop();
			if((adj[cur]).size() != 0){
				for(int a : adj[cur]){
					degs[a]--;
					if(degs[a] == 0){
						tp.push(a);
					}
				}
			}
			tempord[processed - 1] = cur;
		}
//		for(int a : tempord){
//			cout<<a<<" ";
//		}
//		cout<<'\n';
		if(processed == n){
			ordering = tempord;
			l = mid+1;
		}
		else{
			r = mid-1;
		}
	}
	for(int i = 0; i < n; i++){
		cout<<ordering[i]<<' ';
	}
	cout<<'\n';
}
