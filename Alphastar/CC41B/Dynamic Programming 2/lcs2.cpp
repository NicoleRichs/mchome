#include <bits/stdc++.h>
using namespace std;
int main(){
	string a; string b;
	cin >> a >> b;
	vector<vector<int>> ml(a.length(),vector<int16_t>(b.length(), 0));
	for(int i = 1; i < a.length(); i++){
		for(int j = 1; j < b.length(); j++){
			if(a[i-1] == b[j-1]){
				ml[i][j] = ml[i-1][j-1] + 1;
			}
			else{
				ml[i][j] = 0;
			}
		}
	}
	cout<<ml[a.length()-1][b.length()-1]<<'\n';
}
