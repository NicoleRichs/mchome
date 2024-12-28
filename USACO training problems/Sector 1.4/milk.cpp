/*
ID: ethanhp1
TASK: milk
LANG: C++14
*/
#include <iostream>
#include <fstream>
#include <math.h>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
	ifstream is("milk.in");
	ofstream of("milk.out");
	int suppliers;
	int req;
	is >> req >> suppliers;
	int milk_data[suppliers][2];
	for(int i = 0; i < suppliers; i++){
		int supp_num;
		int supp_price;
		is >> supp_price >> supp_num;
		milk_data[i][0] = supp_price;
		milk_data[i][1] = supp_num;
	}
	for(int i = 0; i < suppliers; i++){
		for(int j = 0; j < suppliers; j++){
			if(i < j && milk_data[i][0] > milk_data[j][0]){
				int temp1 = milk_data[i][0];
				int temp2 = milk_data[i][1];
				milk_data[i][0] = milk_data[j][0];
				milk_data[i][1] = milk_data[j][1];
				milk_data[j][0] = temp1;
				milk_data[j][1] = temp2;
			}
		}
	}
	int matches = 0;
	int moneys = 0;
	while(req > 0){
		if(req >= milk_data[matches][1]){
			moneys+=(milk_data[matches][0]*milk_data[matches][1]);
			req-=milk_data[matches][1];
			matches++;
		}
		else{
			moneys+=(milk_data[matches][0]*req);
			req = 0;
		}
	}
	of << moneys << endl;
	of.close();
}
