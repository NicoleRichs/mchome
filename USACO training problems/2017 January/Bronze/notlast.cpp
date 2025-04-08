#include <iostream>
#include <map>
#include <string>
#include <fstream>
using namespace std;
int main(){
	ifstream in("notlast.in");
	ofstream out("notlast.out");
	int lines;
	in >> lines;
	map<string, int> cowarray;
	cowarray["Bessie"] = 0;
	cowarray["Elsie"] = 0;
	cowarray["Maggie"] = 0;
	cowarray["Daisy"] = 0;
	cowarray["Gertie"] = 0;
	cowarray["Annabelle"] = 0;
	cowarray["Maggie"] = 0;
	cowarray["Henrietta"] = 0;
	for(int i = 0; i < lines; i++){
		string name;
		int milk;
		in >> name >> milk;
		cowarray[name]+=milk;
	}
//	for (auto x : cowarray) {
//		cout << x.first << " " << x.second << endl;
//	}
	if(cowarray["Bessie"] == cowarray["Elsie"] == cowarray["Maggie"] == cowarray["Daisy"] == cowarray["Gertie"] == cowarray["Annabelle"] == cowarray["Maggie"] == cowarray["Henrietta"]){
		out << "Tie"<<endl;
		return 0;
	}
	int smallest = 2147483647;
	for(auto x : cowarray){
		if(x.second < smallest){
			smallest = x.second;
		}
	}
	int secondSmallest = 2147483647;
	string ssn = "";
	bool isTie = false;
	
	for(auto x : cowarray){
		if(x.second > smallest && x.second < secondSmallest){
			secondSmallest = x.second;
			ssn = x.first;
			isTie = false;
		}
		else if(x.second == secondSmallest){
			isTie = true;
		}
	}
	if(isTie){
		ssn = "Tie";
	}
	out << ssn << endl;
	return 0;
}
