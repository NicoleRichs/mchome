#include <iostream>
using namespace std;

int main(){
	string item;
	string shop[5] = {"Cheburek","Blin","Stroganoff","Doctorskolya_kielbasa","Kvass"};
	int count[5] = {7,8,1,10,25};
	do{	
		cout<<"In stock: \n";
		for(int i = 0; i < 5; i++){
			cout<<shop[i]<<": "<<count[i]<<", ";
		}
		cout<<"\nWhat item would you like? use underscores davai? ";
		cin >> item;
		if(item == "null"){
			cout<<"NOT AN OPTION DEBIL \n";
			continue;
		}
		bool isIn = false;
		int indexno;
		for(int k = 0; k < 5; k++){
			if(shop[k]==item){
				isIn = true;
				indexno = k;
			}
		}
		if(isIn){
			cout<<"Ok here is "<<item<<" enjoy komrade \n";
			count[indexno]--;
			if(count[indexno] == 0){
				shop[indexno] = "null";
				count[indexno] = 0;
			}
			
		}
		else{
			cout<<"NAHUI OFF WE DO NOT SELL THAT HERE \n"; 
		}
		cout<<"NEXT GOPNIK PLEASE \n";
	} while (item!="no");
	return 0;
}
