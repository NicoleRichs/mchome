#include <bits/stdc++.h>
//this problem sucked.
bool field[3000][3000] = {false}; //bigga field so we can store the "out-of-bound" coordinates which are legal for added cows.
int main(){
	int cows = 0;
	std::queue<std::pair<int,int>> cq;
	int dx[4] = {1,0,-1,0}; //for ease of checking adjacencies
	int dy[4] = {0,1,0,-1};
	int total_cows = 0;
	std::cin >> cows;
	for(int i = 1; i <= cows; i++){
		int a, b;
		std::cin >> a >> b;
		cq.push(std::make_pair(a+1000,b+1000));\//offset to allow for lots of out-of-bound added cows
		int cows_added = 0;
		auto reval = [&](int x, int y){ //no clue you could define stuff like this, very cool #lambdagaming
			if(!field[x][y]){
				return;
			}
			//basically if you have 3 neighbors, we add the one that isn't populated to the queue
			int numcows= 0;
			for(int i  = 0; i < 4; i++){
				if(field[x+dx[i]][y+dy[i]]){
					numcows++;
				}
			}
			if(numcows == 3){
				for(int m = 0; m < 4; m++){
					std::pair<int,int> t{x+dx[m], y+dy[m]};
					if(!field[t.first][t.second]){
						cq.push(t);
					}
				}
			}
		};
		while(!cq.empty()){
			//processing each queue item. 
			std::pair<int,int> l = cq.front();
			cq.pop();
			if(field[l.first][l.second]) continue; //if already visit
			++total_cows; field[l.first][l.second] = true; //now we visit
			reval(l.first,l.second); //see if is 3 neighbor
			for(int k = 0; k < 4; k++){
				reval(l.first+dx[k],l.second+dy[k]);
				//also re-evaluating the neighbors in case of change
			}
		}
		std::cout<<total_cows-i<<"\n"; //ree
	}
	
}
