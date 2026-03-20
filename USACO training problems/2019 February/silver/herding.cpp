#include <bits/stdc++.h>
using namespace std;
int main(){
	ifstream in("herding.in");
	ofstream out("herding.out");
	int cows;
	in >> cows;
	vector<int> pos;
	for(int i = 0; i < cows; i++){
		int tp;
		in >> tp;
		pos.push_back(tp);
	}
	sort(pos.begin(),pos.end());
	int lm = INT32_MAX;
	int mm = 0;
	if(pos[cows-2] - pos[0] == cows-2 && pos[cows-1] - pos[cows-2] > 2){
		lm = 2;
	}
	else if(pos[cows-1] - pos[1] == cows-2 && pos[1] - pos[0] > 2){
		lm = 2;
	}
	else{
		int e = 0;
		for(int s = 0; s < cows; s++){
			while(e + 1 < cows && pos[e + 1] - pos[s] < cows){
				e++;
			}
			lm = min(lm, cows - (e - s + 1)); 
		}
	}
		
	int blanks = 0;
	for(int g = 1; g < cows; g++){
		blanks += (pos[g] - pos[g-1] -1);
	}
	mm = max(blanks-(pos[1] - pos[0] -1), blanks - (pos[cows-1] - pos[cows-2] - 1));
	out << lm << '\n' << mm << endl;
}
