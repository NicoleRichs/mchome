#include <iostream>
#include <fstream>
#include<bits/stdc++.h>
using namespace std;

int main(){
	ifstream in("cowqueue.in");
	ofstream out("cowqueue.out");
	int lines = 0;
	in >> lines;
	vector< pair <int, int> > data;
	for(int i = 0; i < lines; i++){
		int arrival, timetaken;
		in >> arrival >> timetaken;
		data.push_back(make_pair(arrival,timetaken));
	}
	sort(data.begin(),data.end());
	int time = 0;
	for(int c = 0; c < lines; c++){
		if(c == 0){
			time = (data[0].first)+(data[0].second);
		}
		else{
			if(time > data[c].first){
				time+=data[c].second;
			}
			else{
				time = data[c].first+data[c].second;
			}
		}
	}
	out<<time<<endl;
}
