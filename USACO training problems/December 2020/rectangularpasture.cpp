#include <bits/stdc++.h>
const int MAXN = 1e9;
using namespace std;
bool byX(const pair<int,int> &a, const pair<int,int> &b){
	return a.first < b.first;
}
bool byY(const pair<int,int> &a, const pair<int,int> &b){
	return a.second < b.second;
}
int main(){
	int cows;
	cin >> cows;
	vector<pair<int,int>> coords;
	set<int> seenx, seeny;
	for(int i = 0 ; i < cows; i++){
		int x, y;
		cin >> x >> y;
		coords.push_back(make_pair(x,y));
		seenx.insert(x);
		seeny.insert(y);
	}
	//coordinate compression - have a map, the key is the actual value, the stored value for the key is the coordinate's compressed order
	sort(coords.begin(),coords.end(),byX);
	map<int,int> redX;
	for(int j = 0; j < cows; j++){
		redX[coords[j].first] = j;
	}
	map<int,int> redY;
	sort(coords.begin(),coords.end(),byY);
	for(int k =0 ; k < cows; k++){
		redY[coords[k].second] = k;
	}
	sort(coords.begin(),coords.end(),byX);
	//overwriting original coords with compressed ones
	for(int t =0 ; t < cows; t++){
		coords[t].first = redX[coords[t].first];
		coords[t].second =redY[coords[t].second];
	}
	//prefix sums to store the above/below cows per y coordinate
	vector<vector<int>> lt_y(cows, vector<int>(cows + 1));
	vector<vector<int>> gt_y(cows, vector<int>(cows + 1));
	for(int c = 0; c < cows; c++) {
		int curr_y = coords[c].second;
		for (int x = 1; x <= cows; x++) 
		{
			//filling out prefix sums
			lt_y[curr_y][x] = (lt_y[curr_y][x - 1] + (coords[x - 1].second < curr_y));
			gt_y[curr_y][x] = (gt_y[curr_y][x - 1] + (coords[x - 1].second > curr_y));
		}
	}
	long long ans =0ll;
	for (int c1 = 0; c1 < cows; c1++) {
		for (int c2 = c1 + 1; c2 < cows; c2++) {
			
			int bottom = min(coords[c1].second, coords[c2].second);
			int top = max(coords[c1].second, coords[c2].second);

			int bottom_total = 1 + lt_y[bottom][c2 + 1] - lt_y[bottom][c1];
			int top_total = 1 + gt_y[top][c2 + 1] - gt_y[top][c1];
			ans += (long long)bottom_total * top_total;
		}
	}
	ans+=cows+1;
	cout<<ans<<'\n';
}
