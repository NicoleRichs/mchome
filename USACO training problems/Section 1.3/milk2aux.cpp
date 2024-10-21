#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;
int main(){
//input/output objects
  ifstream is("milk2.in");
  ofstream of("milk2.out");
  //amount of lines for to reading
  int intervals;
  is >> intervals;
  int stored[intervals][2];
  //storing the inputs and initializing values
  int largest = 0;
	for(int i = 0; i < intervals; i++){
    	int time1, time2;
    	is >> time1;
    	is>> time2;
    	if(time2-time1 > largest){
    		largest = time2-time1;
		}
		stored[i][0] = time1;
		stored[i][1] = time2;
  	}
  	for(int n = 0; n < intervals; n++){
	    for(int o = n+1; o < intervals; o++){
	      if(stored[n][0] > stored[o][0]){
	        int temp1 = stored[o][0];
	        int temp2 = stored[o][1];
	        stored[o][0] = stored[n][0];
	        stored[o][1] = stored[n][1];
	        stored[n][0] = temp1;
	        stored[n][1] = temp2;        
	      }
	    }
	}
	for(int p = 0; p < intervals; p++){
    	cout<<stored[p][0]<<" "<<stored[p][1]<<endl;
	}
}
