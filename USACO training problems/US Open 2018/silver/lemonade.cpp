#include <bits/stdc++.h>
using namespace std;
int main(){
	ifstream in("lemonade.in");
	ofstream out("lemonade.out");
	//really simple greedy problem, we just sort the cows from most to least amount of line tolerated.
	vector<int> times;
	int cows;
	in >> cows;
	for(int i = 0; i < cows; i++){
		int a;
		in >> a;
		times.push_back(a);
	}
	sort(times.begin(),times.end(), greater<int>());
	int l = 0;
	for(int j = 0; j < cows; j++){
		if(l <= times[j]){
			l++;
		}
	}
	out<<l<<'\n';
}
