#include <bits/stdc++.h>
using namespace std;
int main(){
	multiset<int> ms;
	ms.insert(1);
	ms.insert(1);
	ms.insert(2);
	cout<<ms.size()<<" "<<ms.count(1)<<'\n';
}
