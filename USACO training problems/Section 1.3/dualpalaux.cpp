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
	for(int i = 0; i < max_pow+1; i++){
		cout<<places[i]<<" ";
	}
	long long res=0;
	for(int i = 0; i < max_pow+1;i++){
		int curDig = places[i];
		res+=(curDig*pow(10,max_pow-i));
//		cout<<curDig<<" "<<pow(10,max_pow-i)<<" "<<curDig*pow(10,max_pow-i)<<endl;
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
	long long test_var = convBase(11253,7);
	cout<<test_var<<endl;
	cout<<is_palindrome(to_string(test_var));	
}
