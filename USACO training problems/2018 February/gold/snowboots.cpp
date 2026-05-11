#include <bits/stdc++.h>
using namespace std;
struct boot{
	int width, depth, index;
};
bool bootsByDepth(const boot& a, const boot& b){
	return a.depth > b.depth;
}
int main(){
	ifstream in("snowboots.in");
	ofstream out("snowboots.out");
	int tiles, boots;
	in >> tiles >> boots;
	vector<int> t(tiles);
	vector<boot> b(boots);
	set<int> valid;
	vector<int> tilesByDepth;
	for(int& n : t){
		in >> n;
	}
	for(int k = 0; k < boots; k++){
		in >> b[k].depth >> b[k].width;
		b[k].index = k;
		
	}
	sort(
		b.begin(), b.end(),
		[&](const boot& a, const boot& b) { return a.depth > b.depth; }
	);
	for(int i = 1; i < tiles-1; i++){
		tilesByDepth.push_back(i);
	}
	sort(
		tilesByDepth.begin(), tilesByDepth.end(),
		[&](int a, int b) { return t[a] > t[b]; }
	);
	for(int i = 0; i < tiles; i++){
		valid.insert(i);
	}
	int ct = 0;
	int minStep = 1;
	vector<bool> sols(boots);
	for(const boot& c : b){
		while (ct < tilesByDepth.size()
				 && t[tilesByDepth[ct]] > c.depth) {
			auto removed = valid.find(tilesByDepth[ct]);
			minStep = max(minStep, *next(removed) - *prev(removed));
			valid.erase(removed);
			ct++;
		}
		sols[c.index] = c.width >= minStep;
	}
	for(bool a: sols){
		out<<a<<endl;
	}
	
}
