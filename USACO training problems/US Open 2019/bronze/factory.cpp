#include <bits/stdc++.h>
using namespace std;
int main(){
	ifstream in("factory.in");
	ofstream out("factory.out");
	int stations = 0;
	in >> stations;
	//we need to find if there exist exactly 1 station that is only ever a second pair.
	int fpair[stations-1];
	int spair[stations-1];
	for(int i = 0; i < stations; i++){
		int t1, t2;
		in >> t1 >> t2;
		fpair[i] = t1;
		spair[i] = t2;
	}
	int ans = 0;
	bool ansFound = false;
	bool isFirst = false;
	bool multAns = false;
	for(int i = 1; i < stations+1; i++){
		for(int j = 0; j < stations-1; j++){
			if(fpair[j] == i){
				isFirst = true;
				break;
			}
		}
		if(isFirst == false){
			cout<<i<<endl;
			for(int j = 0; j < stations-1; j++){
				if(spair[j] == i){
					if(ansFound && spair[j]!=ans){
						cout<<spair[j]<<" "<<ans<<endl;
						multAns = true;
						break;
					}
					else if(!ansFound){
						ansFound = true;
						ans = i;
					}
				}
			}
		}
		isFirst = false;
	}
	if(multAns){
		ans = -1;
	}
	out << ans << endl;
}
