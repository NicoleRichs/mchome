#include <bits/stdc++.h>
using namespace std;

int dist_squared(const pair<int,int>& p1, const pair<int,int>& p2){
	int dx = p1.first - p2.first;
	int dy = p1.second - p2.second;
	return dx * dx + dy * dy;
}

bool can_reach(int power, const vector<pair<int,int>>& cows){
	int start = 0;
	vector<int> frontier{start};
	vector<bool> reached(cows.size());
	reached[start] = true;
	while(!frontier.empty()){
		int curr = frontier.back();
		frontier.pop_back();
		for(int c = 0; c < cows.size(); c++){
			if(!reached[c] && dist_squared(cows[curr], cows[c]) <= power){
				frontier.push_back(c);
				reached[c] = true;
			}
		}
	}
	for(bool b : reached){
		if(!b){
			return false;
		}
	}
	return true;
}

int main(){
	int cows;
	ifstream in("moocast.in");
	in >> cows;
	vector <pair<int,int>> coords(cows);
	ofstream out("moocast.out");
	for(int i = 0; i < cows; i++){
		in >> coords[i].first >> coords[i].second;
	}
	
	int low = 0;
	int high = 1e9;
	int valid = -1;
	while(low <= high){
		int middle = (low+high) / 2;
		if(can_reach(middle,coords)){
			valid = middle;
			high = middle-1;
		}
		else{
			low = middle+1;
		}
		
	}
	out<<valid<<endl;

}
