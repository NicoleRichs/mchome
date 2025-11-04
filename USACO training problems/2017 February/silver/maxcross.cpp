#include <bits/stdc++.h>
#define MAX 100000
using namespace std;
int main(){
	ifstream in("maxcross.in");
	ofstream out("maxcross.out");
	int n = 0, k= 0, b = 0;
	in >> n >> k >> b;
	//array with 1's and 0's to indicate broken/working
	int arr[n+1];
	//prefix sum of that array
	int pref[n+1];
	//initialize all values to 0
	for(int i = 0; i < n+1; i++){
		arr[i] = 0;
		pref[i] = 0;
	}
	//making the addresses specified by the inputs broken
	for(int j = 0; j < b; j++){
		int temp;
		in >> temp;
		arr[temp] = 1;
	}
	//calculating the prefix sum
	for(int k = 1; k < n+1; k++){
		pref[k] = pref[k-1]+arr[k];
	}
	//finding the sub-array of length K in the prefix sum with the smallest prefix sum (a.k.a least amount of broken lights)
	int ans = MAX;
	for(int l = 1; l < (n+1)-k+1; l++){
		if(pref[l+k-1] - pref[l-1] < ans){
			ans = pref[l+k-1] - pref[l];
		}
	}
	out<<ans<<endl;
}
