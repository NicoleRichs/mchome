/*
TASK:namenum
ID:ethanhp1
LANG:C++14
*/
#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;
string get_id(string name){
	char decoder[24] = {'2','2','2','3','3','3','4','4','4','5','5','5','6','6','6','7','7','7','8','8','8','9','9','9',};
	string id;
	for(int i = 0; i < name.length(); i++){
		int index = name[i]-'A';
		if(name[i] > 'P'){
			index--;
		}
		id.push_back(decoder[index]);
	}
	return id;
}
int main(){
	ifstream dict("dict.txt");
	ifstream is("namenum.in");
	ofstream of("namenum.out");
	
	string num;
	is >> num;
	string curname;
	bool hasName = false;
	while(dict >> curname){
		curname.erase(remove(curname.begin(), curname.end(), '\n'), curname.end());
		if(get_id(curname) == num){
			hasName = true;
			of << curname<<endl;
		}
	}
	if(!hasName){
		of << "NONE"<<endl;
	}
	of.close();
	return 0;
}
