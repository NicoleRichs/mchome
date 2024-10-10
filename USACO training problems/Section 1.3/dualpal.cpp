/*
ID:ethanhp1
TASK:dualpal
LANG:C++14
*/
#include <iostream>
#include <string>
#include <fstream>
#include <math.h>
using namespace std;
long long convBase(int b10, int base){
	int max_pow = 1;
	while(true){
		if(pow(base,max_pow)>b10){
			max_pow--;
			break;
		}
		else{
			max_pow++;
		}
	}
	int places[max_pow+1];
	int toConv =  b10;
	for(int i = max_pow; i > -1; i--){
		int curPow = pow(base,i);
		int rem = toConv%curPow;
		int digit = (toConv-rem)/(pow(base,i));
		places[max_pow-i] = digit;
		toConv = rem;
	}
//	for(int i = 0; i < max_pow+1; i++){
//		cout<<places[i]<<" ";
//	}
	long long res=0;
	for(int i = 0; i < max_pow+1;i++){
		int curDig = places[i];
		res+=(curDig*pow(10,max_pow-i));
	}
	return res;
}
bool is_palindrome(string num){
	string strNum = num;
	int length = strNum.length();
	bool is_pal = true;
	for(int i = 0; i < length;i++){
		if(strNum[i] != strNum[(length-1)-i]){
			return false;
		}
	}
	return true;
}
int main(){
	ifstream in("dualpal.in");
	ofstream of("dualpal.out");
	int n,s = 0;
	in >> n >> s;
	int arr[n];
	int quota_filled = 0;
	int counter = s+1;
	while(quota_filled < n){
		int successes = 0;
		for(int i = 2; i < 11; i++){
			long long temp = convBase(counter,i);
			if(is_palindrome(to_string(temp))){
				successes++;
			}
			if(successes > 1){
				quota_filled+=1;
				arr[quota_filled-1] = counter;
				break;
			}
		}
		counter++;
	}
	for(int i = 0; i < n; i++){
		of<<arr[i]<<endl;
	}
	of.close();
	return 0;
}
