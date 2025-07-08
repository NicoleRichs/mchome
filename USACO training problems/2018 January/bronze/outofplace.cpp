#include <bits/stdc++.h>
using namespace std;
int main(){
	ifstream in("outofplace.in");
	ofstream out("outofplace.out");
	int numCows;
	in >> numCows;
	int cowArray[numCows];
	int cap[numCows];
	int ord[numCows];
	int curMax = 0;
	int numCap = 0;
	int bessiePos = 0;
	int bessieOrdPos = 0;
	int bessieHeight = 0;
	bool spike = false;
	bool bessieFound = false;
	for(int i = 0; i < numCows; i++){
		int temp;
		in >> temp;
		cowArray[i] = temp;
		cap[i] = 10000;
		ord[i] = 0;
	}
	for(int i = 0; i < numCows+1; i++){
//		cout<<cowArray[i]<<" ";
	}
	cout<<endl;
	for(int i = 0; i < numCows; i++){
		int temp;
//		cout<<"CURMAX"<<" "<<curMax<<"CURTEMP:"<<temp<<endl;
		temp = cowArray[i];
		if(temp == curMax){
			continue;
		}
		else if(temp > curMax){
			if(cowArray[i+1] < temp && cowArray[i+2] < temp && !bessieFound){
				spike = true;
				bessieFound = true;
				bessiePos = i;
				bessieOrdPos = numCap;
				bessieHeight = temp;
//				cout<<cowArray[i+1]<<" "<<cowArray[i-1]<<endl;
				if(cowArray[i+1] == cowArray[i-1]){
					bessieOrdPos-=1;
				}
			}
			else{
				cap[numCap] = i;
				ord[numCap] = temp;
				numCap++;
				curMax = temp;
			}

		}
		else if(temp < curMax && !bessieFound){
			bessiePos = i;
			bessieHeight = temp;
			bessieFound = true;
		}
		
	}
	int ans = 0;
	if(!spike){
		for(int k = 0; k < bessiePos; k++){
			if(cap[k] < bessiePos && ord[k] > bessieHeight){
				ans++;
			}
		}
	}
	if(spike){
		for(int l = numCap; l < numCows; l++){
			ord[l] = 10000000;
		}
	}
	if(spike){
		for(int k = bessieOrdPos; k < numCows; k++){
			if(ord[k] < bessieHeight){
				cout<<ord[k]<<endl;
				ans++;
			}
		}
	}
	out<<ans<<endl;
//	cout<<bessieHeight<<" "<<bessiePos<<" "<<bessieOrdPos<<" "<<numCap<<" "<<spike<<endl;
}
