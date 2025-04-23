#include <bits/stdc++.h>
using namespace std;
int main(){
	//algorithm:
		//read the number of cows, a
		//take the a values, value c[i] at position [i]
		//find the value l, where for each value i greater than l, c[i] is greater than c[i-1]. basically find the i where the list only increases.
		//find how many values are in front, that's the answer
	
	ifstream in("sleepy.in");
	ofstream out("sleepy.out");
	
	int a = 0;
	in >> a;
	int c [a];
	for(int i = 0; i < a; i++){
		int temp;
		in >> temp;
		c[i] = temp;
	}
	int termAfter = 0;
	for(int i = 0; i < a; i++){
		int curHigh = 0;
		bool flag = false;
		for(int m = i; m < a; m++){
			if(c[i+(m-i)]>curHigh){
				curHigh = c[i+(m-i)];
			}
			else{
				flag = true;
			}
		}
		if(flag == false){
			termAfter = i;
			break;
		}
	}
	out << termAfter << endl;
	return 0;	
}
