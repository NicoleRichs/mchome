#include <bits/stdc++.h>
using namespace std;
//a greedy approach works. I had the right logic but a stupid implementation. Idea here is essentially go far right as possible, then as far left as possible, subtracting by one each time we iterate over an address. We can actually just simulate it.
int main(){
	int stops;
	cin >> stops;
	int arr[stops+1];
	vector<char> instructions;
	for(int i = 0; i < stops; i++){
		cin >> arr[i];
	}
	arr[stops] = 0;
	int itr = 0;
	while(!(itr==0 && arr[itr]==0)){
		while(arr[itr] > 0){
			arr[itr]--;
			itr++;
			instructions.push_back('R');
		}
		while(itr > 0 && (arr[itr-1] > 1 || arr[itr] == 0)){
			itr--;
			arr[itr]--;
			instructions.push_back('L');
		}
	}
	for(char c : instructions){
		cout<<c;
	}
	cout<<'\n';
}
