//#3amcoding.exe.cpp.asm.hdl
//the pain is real
//also screw las vegas horrible city nothing to do just seggs and gambling everywhere
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MAX = 5e6+6;
bool prime[MAX]; //stores if a # is prime or not
int max_prime1[MAX]; //stores the largest prime <= that number which is 1 modulo 4
int max_prime3[MAX]; //same as above but 3 modulo 4
void gen_primes(){
	for(int i = 0; i < MAX; i++){
		prime[i] = true;
	}
	//the sieve of eratosthenese
	for(int i = 2; i < MAX; i++){
		if(prime[i]){
			for(int j = 2*i; j < MAX; j+=i){
				prime[j] = false;
			}
		}
	}
}
void run_case(){
	ofstream out;
	//this is for text comparing massive test cases
	out.open("test.out",ios_base::app);
	int rooms;
	cin >> rooms;
	ll FJ_win = MAX;
	ll FJ_win_index = MAX;
	ll FJ_lose = MAX;
	ll FJ_lose_index = MAX;
	for(int t = 0; t < rooms; t++){
		int curNum;
		cin >> curNum;
		//this section was pains
		if(prime[curNum]){
			FJ_win = 1;
			FJ_win_index = t;
		}
		if(curNum%4 == 0){
			if(FJ_lose > (curNum/4)+1){
				FJ_lose_index = t;
				FJ_lose = (curNum/4)+1;
			}			
		}
		else if(curNum%2 == 0){
			if(FJ_win > (curNum+2)/4){
				FJ_win_index = t;	
				FJ_win = (curNum+2)/4;
			}
		}
		else{
			if(curNum % 4 == 1){
				if(FJ_win > ((curNum-max_prime1[curNum])/4) + 1){
//					cout<<"HEY!"<<endl;
					FJ_win = ((curNum-max_prime1[curNum])/4) + 1;
					FJ_win_index = t;
				}
			}
			if(curNum % 4 == 3){
				if(FJ_win > ((curNum-max_prime3[curNum])/4) + 1){
//					cout<<"HEY!"<<endl;
					FJ_win = ((curNum-max_prime3[curNum])/4) + 1;
					FJ_win_index = t;
				}
			}
		}
//		cout<<FJ_win<<" "<<FJ_lose<<" "<<FJ_win_index<<" "<<FJ_lose_index<<endl;
		//the pain ends
	}
	if(FJ_win < FJ_lose){
		cout<<"Farmer John"<<endl;
	}
	else if(FJ_win > FJ_lose){
		cout<<"Farmer Nhoj"<<endl;
	}
	else if(FJ_win == FJ_lose){
		if(FJ_win_index < FJ_lose_index){
			cout<<"Farmer John"<<endl;
		}
		else{
			cout<<"Farmer Nhoj"<<endl;
		}
	}
	return;
}
int main(){
	gen_primes();
	//calculate the max prime per number
	for(int i = 1; i < MAX; i++){
		if(prime[i]){
			if(i % 4 == 1){
				max_prime1[i] = i;
			}
			else{
				max_prime1[i] = max_prime1[i-1];
			}
			if(i % 4 == 3){
				max_prime3[i] = i;
			}
			else{
				max_prime3[i] = max_prime3[i-1];
			}
		}
		else{
			max_prime1[i] = max_prime1[i-1];
			max_prime3[i] = max_prime3[i-1];
		}
	}
	int cases;
	cin >> cases;
	for(int j = 0; j < cases; j++){
		run_case();
	}
}
	

