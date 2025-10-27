#include <bits/stdc++.h>
#include <algorithm>
using namespace std;
int main(){
	
	ifstream in("hps.in");
	ofstream out("hps.out");
	int lines = 0;
	
	in >> lines;
	//prefix sum list
	int moves[lines+1][3];
	moves[0][0] = 0;
	moves[0][1] = 0;
	moves[0][2] = 0;
	
	for(int i = 1; i < lines+1; i++){
		moves[i][0] = moves[i-1][0];
		moves[i][1] = moves[i-1][1];
		moves[i][2] = moves[i-1][2];
		string temp;
		in >> temp;
		if(temp == "H"){
			moves[i][0]++;
		}
		
		else if(temp == "P"){
			moves[i][1]++;
		}
		
		else if(temp == "S"){
			moves[i][2]++;
		}
	}
	
	//we need to simulate a total of lines-1 * 6 cases, each interval & each combo of moves
	int max = 0;
	for(int c = 1; c < lines; c++){
		//c will be the length of the first part
		//calculate the prefix sum for each move of the first interval
		int h1, p1, s1, h2, p2, s2;
		h1 = moves[c][0];
		p1 = moves[c][1];
		s1 = moves[c][2];
		//calculate the prefix sums for each move of the second interval
		h2 = moves[lines][0] - moves[c][0];
		p2 = moves[lines][1] - moves[c][1];
		s2 = moves[lines][2] - moves[c][2];
		//find the largest prefix sum of each interval
		int m1 = 0;
		if(h1 > p1){
			m1 = h1;
		}
		else{
			m1 = p1;
		}
		if(m1 < s1){
			m1 = s1;
		}
		cout<<"MAX1: "<<m1<<" ";
		int m2 = 0;
		if(h2 > p2){
			m2 = h2;
		}
		else{
			m2 = p2;
		}
		if(m2 < s2){
			m2 = s2;
		}
		cout<<"MAX2: "<<m2<<" ";
		//see if the sum of the two largest prefix sums is larger than the current maximum
		if(m1+m2 > max){
			max = m1+m2;
		}
		cout<<"CURMAX: "<<max<<endl;
	}
	out<<max<<endl;
}
