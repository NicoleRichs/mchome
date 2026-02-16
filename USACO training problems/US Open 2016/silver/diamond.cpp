#include <bits/stdc++.h>
using namespace std;
int main(){
	ifstream in("diamond.in");
	ofstream out("diamond.out");
	int diamonds, diff;
	in >> diamonds >> diff;
	int sizes[diamonds];
	for(int i = 0; i < diamonds; i++){
		int size;
		in >> size;
		sizes[i]=size;
	}
	sort(sizes,sizes+diamonds);
	int p1 = 0;
	int p2 = 0;
	int maxL[diamonds];
	//loop finds the length of the subset out of our ordered list of diamond sizes that satisfy the difference constraint and begin at pointer p1. 
	for(; p1 < diamonds; p1++){
		while(sizes[p2] - sizes[p1] <= diff && p2 < diamonds){
			p2++;
		}
		maxL[p1] = p2-p1;
	}
	int rMax[diamonds+1];
	rMax[diamonds] = 0;
	//this loop checks if the  subset starting immediately after the first subset ends, or if previous ones are larger. 
	for(int k = diamonds-1; k >= 0; k--){
		rMax[k] = max(rMax[k+1], maxL[k]);
	}
	int ans = 0;
	//then we just find the largest sum of the two subsets.
	for(int a = 0; a < diamonds; a++){
		ans = max(ans, maxL[a]+rMax[a+maxL[a]]);
	}
	out << ans << endl;
	return 0;
}
