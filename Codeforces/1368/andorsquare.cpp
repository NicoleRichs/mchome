#include <bits/stdc++.h>
using namespace std;
int main(){
	int powers[21] = {};
	//we compile the amount of "powers" of two present in total, then create numbers based on passing through the array and taking at most one of each power if present.
	//this is because of the nature of AND and OR - we can think of the OR result as one number resulting one bit in every place, and the ANDed number as recieving the 
	//bits that are common. In this way no bits are lost, and since it is always optimal to create a larger number, we simply accumulate all the bits and greedily
	//keep creating the largest numbers we can.
	int n;
	cin >> n;
	int lp = 0;
	for(int i = 0; i < n; i++){
		int a;
		cin >> a;
		int cp = 0;
		while(a >= (1 << cp) && cp < 21){
			if(a & (1 << cp)){
				powers[cp]++;
				if(cp > lp){
					lp = cp;
				}
			}
			cp++;
		}
	}
	bool np = true;
	long long fa = 0;
	do{
		np = true;
		long long cn = 0;
		for(int j = lp; j >= 0; j--){
			if(powers[j] > 0){
				powers[j]--;
				cn += (1 << j);
				np = false;
			}
			if(j == lp && powers[j] == 0){
				lp--;
			}
		}
		cn = cn * cn;
		fa += cn;
	}while(!np);
	cout<<fa<<'\n';
}
