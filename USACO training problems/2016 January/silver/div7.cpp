#include <bits/stdc++.h>
using namespace std;
int main(){
	//going to finally use comments for this one, can't promise I'll keep it up in the future though
	ifstream in("div7.in");
	ofstream out("div7.out");
	int lines = 0;
	in >> lines;
	//mstart[x] and mend[x] will hold the minimum line where the prefix sum modulo seven = x and the last line where the prefix sum mod 7 = x, respectively. 
	array<int,7> mstart;
	array<int,7> mend;
	//pre-seeding arrays with max value
	mstart.fill(INT_MAX);
	mend.fill(INT_MAX);
	//running sum of all ids, mod 7
	long pref = 0;
	for(int i = 1; i < lines+1; i++){
		int id;
		in >> id;
		pref+=id;
		pref = pref%7;
		//checking if there isn't a min value for the mod7 entry
		if(i < mstart[pref]){
			mstart[pref] = i;
		}
		mend[pref] = i;
	}
	//finding the max delta between start/end
	int max = 0;
	for(int i = 0; i < 7; i++){
		int lt = mend[i] - mstart[i];
		if(lt > max && mstart[i] != INT_MAX && mend[i] != INT_MAX){
			max = lt;
		}
	}
	out<<max<<endl;
} 
