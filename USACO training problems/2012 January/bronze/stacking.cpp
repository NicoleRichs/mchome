//note: i honestly have no idea what is going on anymore, the official solution doesn't work, i give up. tried vector, tried longs, etc. nothing. :|
#include <bits/stdc++.h>
using namespace std;
int main(){
	int stacks = 0, ins = 0;
	cin >> stacks;
	cin >> ins;
	vector<int>diff(stacks);
	for(int i = 0; i < stacks; i++){
		diff[i] = 0l;
	}
	for(int j = 0; j < ins; j++){
		int start, end;
		cin >> start >> end;
		if(start>1){
			diff[start-1]+=1;
		}
		if(end<stacks-1){
			diff[end]-=1;
		}
		
	}
	long medarr[1000000];
	long long curvalue = 0l;
	for(int k = 0; k < stacks; k++){
		curvalue+=diff[k];
		medarr[k] = curvalue;
	}
	sort(medarr,medarr+stacks);
	cout<<medarr[stacks/2]<<endl;
}
