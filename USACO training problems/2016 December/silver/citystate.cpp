#include <bits/stdc++.h>
using namespace std;
int main(){
	ifstream in("citystate.in");
	ofstream out("citystate.out");
	int lines;
	in >> lines;
	int ans = 0;
	map<string, long> list;
	for(int i = 0; i < lines;i++){
		string city,state;
		in >> city >> state;
		string code = city.substr(0,2)+state.substr(0,2);
		if(city.substr(0,2)!=state.substr(0,2)){
			if(list.count(code) == 0){
				list[code] = 0;
			}
			list[code]+=1;	
		}			
	}
	long total = 0;
	for(map<string,long>::iterator it = list.begin(); it != list.end(); ++it) {
		string key = it->first;
		string complement = key.substr(2,2) + key.substr(0,2);
		if(list.count(complement) == 1){
			total+=list[key] * list[complement];
		}
	}
	total = total/2;
	out<<total<<endl;
}
