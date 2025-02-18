#include <iostream>
#include <fstream>
#include <set>
#include <string>
using namespace std;
int N;
string S;
bool isIn(int cl){
	set <string> X;
	for(int i = 0; i <=N-cl; i++){
		if(X.count(S.substr(i,cl))>0){
			return true;
		}
		X.insert(S.substr(i,cl));
	}
	return false;
}
int main(){
	ifstream in("whereami.in");
	ofstream out("whereami.out");
	in >> N >> S;
	int a = 1;
	while(isIn(a)){
		a++;
	}
	out << a <<endl;
	return 0;
}
