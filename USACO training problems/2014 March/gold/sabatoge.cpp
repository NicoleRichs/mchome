#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> machines;
int rnd(double a){
	return (int)(1000.0 * a + 0.5);
}
bool process(double g){
	int total = 0;
	double ca, cb;
	for(int i = 0; i < n; i++){
		total+=machines[i];
	}
	cb = ca = machines[1] - g;
	for(int j =2; j < n-1; j++){
		if(ca < 0){
			ca = 0;
		}
		ca+=machines[j]-g;
		if(ca > cb){
			cb = ca;
		}
	}
	return cb >= total - (g * n);
}
int main(){
	ifstream in("sabotage.in"); //rip spelling x2
	ofstream out("sabotage.out");
	in >> n;
	for(int i = 0; i < n; i++){
		int a;
		in >> a;
		machines.push_back(a);
	}
	double s = 1.0; 
	double e = 100000.0 * 1e3;
	while(rnd(s) != rnd(e)){
		if(process((s+e)/2)){
			e = (s+e)/2;
		}
		else{
			s =(s+e)/2;
		}
	}
	out<<setprecision(3)<<fixed;
	out<<s<<'\n';
}
