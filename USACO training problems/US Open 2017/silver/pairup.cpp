#include <bits/stdc++.h>
using namespace std;
//The basic idea here is to store the data in a struct, containing the amount of milk and the number of cows that produce that much milk, then to create a vector of those structs, sort from low to high of the most amount of milk, then use the "two pointers" method to pair up two cows from each milk amount, and log the max sum.
struct amt{
	int milk;
	int cows;
};
bool cmp(const amt& a1, const amt& a2){
	//it's confirmed that the values won't be equal
	return a1.milk < a2.milk;
}
int main(){
	ifstream in("pairup.in");
	ofstream out("pairup.out");
	int n;
	in >> n;
	vector<amt> cow(n);
	for(int i = 0; i < n; i++){
		amt temp;
		int i1, i2;
		in >> i1 >> i2;
		temp.cows = i1;
		temp.milk = i2;
		cow[i] = temp;
	}
	sort(begin(cow),end(cow),cmp);
	int maxsum = 0;
	int lp = 0;
	int rp = n-1;
//	cout<<"LOOP START"<<endl;
	while(rp >= lp){
		int pairs;
		int tsum;
		//check the smaller amount of cows to subtract. I could have done this with a max() but ah well too late, and it works anyways
		if(cow[lp].cows > cow[rp].cows){
//			cout<<"ELSEIF1"<<endl;
			pairs = cow[rp].cows;
		}
		else if(cow[lp].cows < cow[rp].cows){
//			cout<<"ELSEIF2"<<endl;
			pairs = cow[lp].cows;
		}
		else{
//			cout<<"ELSE"<<endl;
			pairs = cow[rp].cows;
		}
//		cout<<pairs<<endl;
		cow[lp].cows -= pairs;
		//if statement solved an issue where the amount of cows became negative, forcing the loop into an infinite loop
		if(lp != rp){
			cow[rp].cows -= pairs;			
		}

		tsum = cow[lp].milk+cow[rp].milk;
		//move pointers if the amount of cows is 0, in this way we can have the smallest milk cows w/ biggest milk cows, and more middling ones with other more middling ones, so the highest value is lower
		if(cow[lp].cows == 0){
			lp++;
//			cout<<"LP MOVED TO "<<lp<<endl;
		}
		if(cow[rp].cows == 0){
			rp--;
//			cout<<"RP MOVED TO"<<rp<<endl;
		}
		if(tsum > maxsum){
			maxsum = tsum;
		}
	}
	out<<maxsum<<endl;
}
