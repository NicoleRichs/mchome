/*
TASK: barn1
LANG: C++14
ID: ethanhp1
*/
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;
int main(){
	ifstream in("barn1.in");
	ofstream of("barn1.out");
	int maxboards, totalstalls, numcows;
	in >> maxboards >> totalstalls >> numcows;
	int ans = totalstalls;
	int used_boards = 1;
	vector<int> gaps;
	int curCount = 0;
	int cowArr[numcows];
	for(int i = 0; i < numcows; i++){
		int temp;
		in >> temp;
		cowArr[i] = temp;
	}
	for(int i = 0; i < numcows; i++){
		for(int k = 0; k < numcows; k++){
			if(i > k){
				if(cowArr[i] < cowArr[k]){
					int temp = cowArr[i];
					cowArr[i] = cowArr[k];
					cowArr[k] = temp; 
				}
			}
		}
	}
	for(int i = 0; i < numcows; i++){
		int temp = cowArr[i];
		if(i == 0){
			curCount = temp;
			ans-=curCount;
			ans++;
		}
		else if(temp > curCount+1){
			gaps.push_back(temp-curCount-1);
			curCount = temp;
			
		}
		else{
			curCount = temp;
		}
		if(i == numcows-1){
			ans-=(totalstalls-temp);
		}
	}
	sort(gaps.begin(),gaps.end());
	if(maxboards > numcows){
		maxboards = numcows;
	}
	while(used_boards < maxboards){
		int curLen = gaps.size();
		used_boards++;
		ans-=gaps.at(curLen-1);
		gaps.erase(gaps.begin()+curLen-1);
	}
	of<<ans<<endl;
}
