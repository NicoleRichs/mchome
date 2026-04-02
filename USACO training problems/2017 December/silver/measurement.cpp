//time to acquire some MOTIVATION.
#include <bits/stdc++.h>
struct entry{
	int cn; 
	int change;
	int day;
};
bool entrycmp(entry e1, entry e2){
	return e1.day < e2.day;
}
using namespace std;
int main(){
	//the main idea: have a map ordered by the value, then make changes to the values using the keys as reference for the cow number.
	ifstream in("measurement.in");
	ofstream out("measurement.out");
	int lines = 0;
	int start = 0;
	in >> lines >> start;
	vector<entry> entries(lines);
	map<int, int> cl;
	for(entry& e : entries){
		in >> e.day >> e.cn >> e.change;
		cl[e.cn] = start;
	}
	sort(entries.begin(),entries.end(),entrycmp);
	map <int, int> milkproduction{{start,lines}};
	int changes = 0;
	for(entry e : entries){
		cout<<e.day<<" "<<e.cn<<" "<<e.change<<endl;
		int curramt = cl[e.cn];
		bool wascool = curramt == milkproduction.rbegin()->first;
		int prevcool = milkproduction[curramt];
		milkproduction[curramt]--;
		if(milkproduction[curramt] == 0){
			milkproduction.erase(curramt);
		}
		curramt += e.change;
		cl[e.cn] = curramt;
		milkproduction[curramt]+=1;
		
		bool iscool = curramt == milkproduction.rbegin()->first;
		int curcool = milkproduction[curramt];
		
		if(wascool){
			if(iscool && curcool == prevcool){
				continue;
			}
		changes++;
		}
		else if(iscool){
			changes++;
		}
	}
	out<<changes<<endl;
	
}
