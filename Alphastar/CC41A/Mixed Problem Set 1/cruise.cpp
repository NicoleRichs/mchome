#include <bits/stdc++.h>
using namespace std;

int main(){
	ifstream in("cruise.in");
	ofstream out("cruise.out");
	vector<bool> seq; //false is l, true is r
	int n, m, k;
//	in >> n >> m >> k;
	cin >> n >> m >> k;
	vector<pair<int,int>> adj(n);
	for(int i= 0; i< n; i++){
		int a, b;
		cin >> a >> b;
//		in >> a >> b;
		adj[i] = {a-1,b-1};
	}
	char c;
	for(int i = 0; i < m; i++){
//		in >> c;
		cin >> c;
		if(c == 'L'){
			seq.push_back(false);
		}
		else{
			seq.push_back(true);
		}
	}
	vector<int> leadsTo(n, -1);
	for(int i = 0; i < n; i++){
		int cn = i;
		for(int j = 0; j < m; j++){
			if(seq[j] == false){
				cn = adj[cn].first;
			}
			else{
				cn = adj[cn].second;
			}
		}
		leadsTo[i] = cn;
	}
//	out<<"MADE IT"<<'\n';
//	for(int i = 0; i < n; i++){
//		cout<<leadsTo[i]<<'\n';
//	}
	//cycle detection
	int p1 = 0, p2 = 0;
	do{
		p1 = leadsTo[p1];
		p2 = leadsTo[leadsTo[p2]];
	}while(p1 != p2);
	p1 = 0;
	int fromS = 0;
	do{
		fromS++;
		p1 = leadsTo[p1];
		p2 = leadsTo[p2];
	}while(p1 != p2);
	int cycleLen = 1;
	p2 = leadsTo[p2];
	while(p1 != p2){
		cycleLen++;
		p2 = leadsTo[p2];
	}
	int fromCS = k - fromS;
	fromCS%=cycleLen;
	for(int i= 0; i < fromCS; i++){
		p1 = leadsTo[p1];
	}
//	out<<p1+1<<'\n';
	cout<<p1+1<<'\n';
}
