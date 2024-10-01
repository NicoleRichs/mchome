/*
TASK: palsquare
ID: ethanhp1
LANG: C++11
*/
#include <iostream>
#include <cmath>
#include <vector>
#include <fstream>
#include <string>
using namespace std;
string convBase(int b10, int base){
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
	string res;
	for(int i = 0; i < max_pow+1;i++){
		int curDig = places[i];
		char toApp;
		if(curDig == 0){
			toApp = '0';
		}
		else if(curDig == 1){
			toApp = '1';
		}
		else if(curDig == 2){
			toApp = '2';
		}
		else if(curDig == 3){
			toApp = '3';
		}
		else if(curDig == 4){
			toApp = '4';
		}
		else if(curDig == 5){
			toApp = '5';
		}
		else if(curDig == 6){
			toApp = '6';
		}
		else if(curDig == 7){
			toApp = '7';
		}
		else if(curDig == 8){
			toApp = '8';
		}
		else if(curDig == 9){
			toApp = '9';
		}
		else if(curDig == 10){
			toApp = 'A';
		}
		else if(curDig == 11){
			toApp = 'B';
		}
		else if(curDig == 12){
			toApp = 'C';
		}
		else if(curDig == 13){
			toApp = 'D';
		}
		else if(curDig == 14){
			toApp = 'E';
		}
		else if(curDig == 15){
			toApp = 'F';
		}
		else if(curDig == 16){
			toApp = 'G';
		}
		else if(curDig == 17){
			toApp = 'H';
		}
		else if(curDig == 18){
			toApp = 'I';
		}
		else if(curDig == 19){
			toApp = 'J';
		}
		else if(curDig == 20){
			toApp = 'K';
		}
		res.push_back(toApp);
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
	ifstream is("palsquare.in");
	ofstream of("palsquare.out");
	int base;
	is>>base;
	for(int i = 1; i < 301;i++){
		string curPal = (string) convBase(pow(i,2),base);
		if(is_palindrome(curPal)){
			of<<convBase(i,base)<<" "<<curPal<<endl;
		}
	}
	of.close();
	return 0;
}
