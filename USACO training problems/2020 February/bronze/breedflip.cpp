#include <bits/stdc++.h>
using namespace std;
int main(){
	ifstream in("breedflip.in");
	ofstream out("breedflip.out");
	int cows = 0;
	in >> cows;
	char a[cows];
	char b[cows];
	
	for(int i = 0; i < cows; i++){
		char breed;
		in >> breed;
		a[i] = breed;
	}
	
	for(int k = 0; k < cows; k++){
		char breed;
		in >> breed;
		b[k] = breed;
	}
	bool isStreak = false;
	int numStreak = 0;
	for(int pos = 0; pos < cows; pos++){
		if(!isStreak && a[pos] != b[pos]){
			isStreak = true;
			numStreak++;
		}
		else if(isStreak && a[pos] != b[pos]){
			continue;
		}
		else if(isStreak && a[pos] == b[pos]){
			isStreak = false;
		}
	}
	out<<numStreak<<endl;
	return 0;
	
}
