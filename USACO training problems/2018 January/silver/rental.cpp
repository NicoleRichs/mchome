//back from a pretty horrible cold. plus AMC coming up in a month. Finished 20:30 PST on 10/10/2022. 
#include <bits/stdc++.h>
using namespace std;
int main(){
	
	ifstream in("rental.in");
	ofstream out("rental.out");
	int cows;
	int shops; 
	int farms;
	in >> cows >> shops >> farms;
	vector<int> cowList(cows);
	
	for(int i = 0; i < cows; i++){
		in >> cowList[i];
	}
	
	vector<pair<int,int>> shopList(shops);
	
	for(int j = 0; j < shops; j++){
		in >> shopList[j].second >> shopList[j].first; // first value in the input is the quantity, but i want to sort by price per gallon, hence the switch
	}
	
	vector<int> farmList(farms);
	
	for(int k = 0; k < farms; k++){
		in >> farmList[k];
	}
	
	//sorting cows from greatest to least output. Since renting a cow is the same price regardless of output, makes more sense to rent the least productive, and evaluate the milk profit starting from the most productive.
	sort(cowList.begin(),cowList.end(),greater<int>());	
	sort(shopList.begin(),shopList.end(),greater<pair<int,int>>());
	sort(farmList.begin(),farmList.end(),greater<int>());
	int cown = 0; // current cow
	int farmn = 0;//current farm for rent
	int shopn = 0;//current shop for sell
	long long money = 0;
	while(cown < cows){
		//curshop - temporary changes to shopn, to evaluate the milking profits.
		int curshop = shopn;
		int ls = 0;
		//if milk:
		int amt = cowList[cown]; 
		int milkmoney = 0;
		while(curshop < shops){
			//seeing if the cow has less milk left or the store has less need left
			int sold = min(amt, shopList[curshop].second);
			milkmoney+= shopList[curshop].first * sold;
			amt-=sold;
			
			//termination of loop if cow is out of cow juice
			if(amt == 0){
				ls = sold; //this stores how much milk was sold to the current store.
				break;
			}
			
			else{
				curshop++;
				//loop will terminate if curshop == shops
			}
			
		}
		
		//decide if rent or no
		if(milkmoney > farmList[farmn] || farmn >= farms){
			money+=milkmoney;
			shopn = curshop; // we move the official shop counter to the temporary number, since we have decided to sell
			shopList[shopn].second -= ls; //this is the amount of milk still left in the current store.
			cown++;
		}
		else{
			money+=farmList[farmn];
			farmn++; 
			cows--; //we've determined that at this point it isn't profitable to milk, but we might need to milk at some point. Instead of renting this cow (the most productive not processed yet) we'll just rent the least productive cow still unaccounted for (or just subtract 1 from the number of cows)
		}
		
	}
	out<<money<<endl;
}
