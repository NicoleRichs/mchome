#include <bits/stdc++.h>
using namespace std;
//AHHH SO MANY METHODS READABILITY SO GUD AHHHHUIHDSIOUBOYIUHIUH
/*
I wrote this during a thanksgiving party
there are epic college students with me
they do cs/ee
nice
*/
pair<int,int> conv(char c){ //turns N,E,S,W into pairs indicating how much of each coordinate is modified
	if(c == 'N'){
		return make_pair(0,1);
	}
	else if(c == 'S'){
		return make_pair(0,-1);
	}
	else if(c == 'E'){
		return make_pair(1,0);
	}
	else if(c == 'W'){
		return make_pair(-1,0);
	}
	else{
		return make_pair(0,0);
	}
}
pair<int,int> addP(pair<int,int> a, pair<int,int> b){ //adding the components of two pairs
	return (make_pair(a.first + b.first, a.second + b.second));
}
int getDist(pair<int,int> a, pair<int,int> b){ //getting the squared distance between two pairs
	return ((a.first - b.first)*(a.first - b.first)) + ((a.second - b.second)*(a.second - b.second));
}
int main(){
	int n, m;
	cin >> n >> m;
	vector<pair<int,int>> fji; //list of steps for farmer john, in terms of how much he needs to move per step.
	vector<pair<int,int>> bi; //same as above but for bessie
	pair<int,int> fjp; //fj's start coords
	pair<int,int> bp; //bessie's start coords
	cin >> fjp.first >> fjp.second;
	cin >> bp.first >> bp.second;
	
	for(int i = 0; i < n; i++){
		char c;
		cin >> c;
		fji.push_back(conv(c));
	}
	
	for(int i = 0; i < m; i++){
		char c;
		cin >> c;
		bi.push_back(conv(c));
	}

	vector<pair<int,int>> fjs; //the actual coordinates of each of FJ's tseps
	fjs.push_back(fjp); //the first one is his start loc
	for(int i = 0; i <n; i++){ 
		fjs.push_back(addP(fjs[i], fji[i])); //add the amount he needs to move per step to the previous coords, and add to the list.
	}
	//same for bessie
	vector<pair<int,int>> bs;
	bs.push_back(bp);
	for(int i = 0; i < m; i++){
		bs.push_back(addP(bs[i], bi[i]));
	}
	
	vector<vector<int>> dp(n + 1, vector<int>(m + 1,2147483647)); //dp[i][j] is the minimum energy required to get FJ to his ith step and Bessie to her jth step
	
	dp[0][0] = 0; //base case, FJ and Bessie @ their start coords has 0 energy spent.
	
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			//it is never optimal to move neither
			
			//case 1: FJ only
			if(i < n){	
				dp[i+1][j] = min(dp[i][j] + getDist(fjs[i+1], bs[j]), dp[i+1][j]); //chck new dist vs old
			}
			
			//case 2: Bessie only
			if(j < m){	
				dp[i][j+1] = min(dp[i][j] + getDist(fjs[i], bs[j+1]), dp[i][j+1]); //ditto here
			}
			
			//case 3: both
			if(i < n && j < m){
				dp[i+1][j+1] = min(dp[i][j] + getDist(fjs[i+1], bs[j+1]), dp[i+1][j+1]); //and here
			}
		}
	}
	cout<<dp[n][m]<<'\n'; //bing chilling
}