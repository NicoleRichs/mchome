#include <bits/stdc++.h>
using namespace std;
int main(){
	ifstream in("highcard.in");
	ofstream out("highcard.out");
	int n;
	in >> n;
	bool cards[(n*2)+1] = {false}; //a bool array to see which cards are in Elsie's deck
	vector<int> ec; //elsie's array
	set<int> bc;//the set of bessie cards left to play
	for(int i = 0; i < n; i++){
		int a;
		in >> a;
		ec.push_back(a);
		cards[a] = true;
	}
	sort(ec.begin(),ec.end());
	for(int j = 1; j <= n*2; j++){
		if(!cards[j]){ //bool array to build bessies set
			bc.insert(j);
		}
	}
	int ans = 0;
	for(int k = 0; k < n; k++){
		if(bc.upper_bound(ec[k]) == bc.end()){ //if we don't have any cards that can win
			bc.erase(*bc.upper_bound(0)); //sacrifice the least powerful card
		}
		else{
			bc.erase(bc.upper_bound(ec[k])); //we play the least powerful winning card
			ans++;
		}
	}
	out<<ans<<'\n';
}
