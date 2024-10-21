/*
ID:ethanhp1
TASK:namenum
LANG:C++14
*/
#include <iostream>
#include <string>
#include <fstream>
#include <string>
using namespace std;
int main(){
	ifstream dictr("dict.txt");
	ifstream is("namenum.in");
	ofstream of("namenum.out");
	string dict[4617];
	string name;
	for(int i = 0; i < 4617; i++){
		dictr >> name;
		dict[i] = name;
	}
	cout<<dict[4616];
	string serial;
	is >> serial;
}
