#include <bits/stdc++.h>
using namespace std;
int cows, buses, capacity;
vector<int> arrivals;
bool isPossible(int dt){
	int cc = 0;
	int fc = 0;
	int bp = 0;
	while(cc < cows){
		if(fc == cc){
			bp++;
		}
		if(arrivals[cc] - arrivals[fc] > dt){
			fc = cc;
		}
		else if(cc - fc + 1==capacity){
			fc = ++cc;
		}
		else{
			cc++;
		}
	}
	return bp <= buses; //idk why but it was dt originally :skull: :skull:
}
int main(){
	ifstream in("convention.in");
	ofstream out("convention.out");
	in >> cows >> buses >> capacity;
	for(int i= 0; i < cows; i++){
		int a;
		in >> a;
		arrivals.push_back(a);
	}
	sort(arrivals.begin(),arrivals.end());
	int min = 0;
	int max = arrivals[arrivals.size()-1] - arrivals[0];
	while(min < max){
		int mid = min + (max - min) / 2;
		if(isPossible(mid)){
			max = mid;
		}
		if(!isPossible(mid)){
			min = mid+1;
		}
	}
	out<<min<<'\n';
}
