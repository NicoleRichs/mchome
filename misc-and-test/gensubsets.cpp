//program to test out generating all possible subsets. Each element is unique.
#include <bits/stdc++.h>
using namespace std;
int n;
string elements;
string substr;
vector<string> subsets;
void gen(int k, string a){
	if(k == n-1){
		substr = a;
		subsets.push_back(substr);
//		cout<<substr<<'\n';
		substr= substr + elements[k];
		subsets.push_back(substr);
//		cout<<substr<<'\n';
		substr = "";
		return;
	}
	else{
		gen(k+1, a);
		gen(k+1, a + elements[k]);
	}
}
int main(){
	ifstream in("gensubsets.in");
	ofstream out("gensubsets.out");
	in >> n;
	for(int i = 0; i < n; i++){
		string a;
		in >> a;
		elements += a;
	}
	gen(0,substr);
	for(string s : subsets){
		out << s << '\n';
	}
}
