#include <bits/stdc++.h>
#include <string>
#include <map>
#include <set>
using namespace std;
int relYear(bool prev, string year, int bias){
	int ans = 0;
	if(year == "Ox"){
		ans = 12;
	}
	if(year == "Tiger"){
		ans = 1;
	}
	if(year == "Rabbit"){
		ans = 2;
	}
	if(year == "Dragon"){
		ans = 3;
	}
	if(year == "Snake"){
		ans = 4;
	}
	if(year == "Horse"){
		ans = 5;
	}
	if(year == "Goat"){
		ans = 6;
	}
	if(year == "Monkey"){
		ans = 7;
	}
	if(year == "Rooster"){
		ans = 8;
	}
	if(year == "Dog"){
		ans = 9;
	}
	if(year == "Pig"){
		ans = 10;
	}
	if(year == "Rat"){
		ans = 11;
	}
	ans-=bias;
	if(ans == 0 || ans == 12){
		if(prev){
			return -12;
		}
		return 12;
	}
	if(prev){
//		cout<<"ANS BEFORE: "<< ans;
		ans-=12;
		if(ans < bias){
			ans = ans % 12;	
		}
		if(ans > 0){
			ans-=12;
		}
//		cout<<" !We got here! ans is now:"<<ans<<" ";
	}
	else if(prev == false && ans < 0){
		ans+=12;
		ans = ans % 12;
	}
	else if(prev == false && ans > 12){
		ans-=12;
	}
//	cout<<"ans = "<<ans;
	return ans;
}
int main(){
	int lines;
	cin >> lines;
	unordered_map<string, int> cows;// stores names and everyone's birth years relative to Bessie, whose year is 0 (so if Mildred is born in the next rat year, she will be 11, if Elsie is born in the previous dragon year, she will be -9)
	for(int i = 0; i < lines; i++){
		string newc, ref, year,trash1,trash2,trash3, trash4, prevr;
		bool prev;
		int bias;
		cin >> newc >> trash1 >> trash2 >> prevr >> year >> trash3 >> trash4 >> ref; 
		if(prevr == "previous"){
			prev = true;
		}
		if(prevr == "next"){
			prev = false;
		}
		if(ref == "Bessie"){
			bias = 0;
		}
		else{
			bias = cows[ref];
			bias = bias%12;
		}
		int temp = relYear(prev, year, bias);
		cows[newc] = temp+cows[ref];
//		cout<<newc<<" is "<<temp+cows[ref]<<" from Bessie"<<endl;
	}
	if(cows["Elsie"] < 0){
		cout<<cows["Elsie"]*-1;
		return 0;
	}
	cout<<cows["Elsie"];
	return 0;
}
