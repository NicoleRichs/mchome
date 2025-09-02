#include <bits/stdc++.h>
#define int long long
using namespace std;
void revArray(int arr[], int s, int e)
{
    while (s < e)
    {
        int temp = arr[s];
        arr[s] = arr[e];
        arr[e] = temp;
        s++;
        e--;
    }
}  
signed main(){
	int cases;
	cin >> cases;
	int ansList[cases];
	for(int i = 0; i < cases; i++){
		int cows = 0;
		cin >> cows;
		int cowArr[cows];
		int ans = 0;
		for(int a = 0; a < cows; a++){
			int temp;
			cin >> temp;
			cowArr[a] = temp;
		}
		for(int t = 0; t < 2; t++){
			for(int l = 1; l < cows-1; l++ ){
				if(cowArr[l] > cowArr[l-1]){
					int diff = cowArr[l] - cowArr[l-1];
					ans+= 2*diff;
					cowArr[l] = cowArr[l] - diff;
					cowArr[l+1] = cowArr[l+1] - diff;
				}
			}
			revArray(cowArr, 0, cows-1);		
		}
		bool error = false;
		for(int r = 0; r < cows; r++){
			if(cowArr[r] < 0){
				error = true;
			}
		}
		if(error){
			ans = -1;
		}
		int set = 0;
		for(int c = 0; c < cows; c++){
			if(c == 0){
				set = cowArr[0];
			}
			else if(c > 0){
				if(cowArr[c]!=set){
					ans = -1;
				}
			}
		}
		ansList[i] = ans;
	}
	for(int l = 0; l < cases; l++){
		cout<<ansList[l]<<endl;
	}
}
