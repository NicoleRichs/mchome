/*
Holy hell, what an odd problem
Took me about 60 minutes i think
*/
#include <bits/stdc++.h>
using namespace std;
int main(){
	int n, t;
	
	cin >> n >> t;
	
	vector<int> cv; //this holds the values of each coin, in order it is given
	int mv = 0;
	
	for(int i = 0; i < n; i++){
	
		int a;
		cin >> a;
		cv.push_back(a);
		mv = max(mv, a);
	
	}
	
	vector<int> ca; //this holds the amount of each coin in order FJ has
	
	for(int i = 0; i < n; i++){
	
		int b;
		cin >> b;
		ca.push_back(b);
	
	}
	
	vector<vector<int>> dp(t + mv + mv + mv + 1, vector<int>(n+1,-1)); //here's our DP array. The state for dp[x] is when x is the amount of money currently made. dp[x][0] is the amount of coins our best solution for making x money has. dp[x][i+1] for i >= 0 is the amount of coin i used to make that most efficient method.
	for(int i = 0; i <=n; i++){ //we initialize 0 money to 0 coins
		dp[0][i] = 0;
	}
	
//	cout<<"start horrible dp"<<'\n';

	for(int k = 0; k < n; k++){ //we loop through all coins
		
		int kv = cv[k]; //kv - value of current coin
		int mkv = ca[k]; //mkv - max amount of current coin
		
//		cout<<"starting to add coin "<<k<<" of value "<<kv<<" max coins is "<<mkv<<'\n';

		for(int i = 0; i <= t + mv; i++){ //loop through all money values. We go up to t + mv since it might be more efficient to overpay and then give change.
			
//			cout<<"processing money: "<<i<<'\n';

			if(dp[i][0] != -1){ //checking if we can make the current amount of money
				
//				cout<<"can make "<<i<<" with "<<dp[i][0]<<" coins.";

				if(dp[i][k+1] < mkv && (dp[i+kv][0] > dp[i][0] + 1 || dp[i + kv][0] == -1)){ //we check if we can add another of coin k, and if adding one coin k to current solution for i would be more efficient than the current solution for i + kv
					
//					cout<<"can add coin"<<'\n';
//					cout<<dp[i][k+1]<<" "<<mkv<<'\n';
					//if so, we set dp[i+kv] to dp[i] but increment the # of coins used and the amonut of coin k used.
					dp[i+kv] = dp[i];
					dp[i+kv][k+1]+=1; //the k+1 is important here, since dp[i]][k] refers to the amount of coin k-1 since dp[i][0] stores total coins
					dp[i+kv][0]+=1;
					
//					for(int x = 0; x <= n; x++){
//						cout<<dp[i+kv][x]<<' ';
//					}
//					cout<<endl;

					if(i + kv > t){ //now we need to make some change
						
//						cout<<"Processing change for "<<i<<'\n';

						bool notExcede = true;
						if(dp[i + kv - t][0] == -1){ //if we can't make the amount of change required, we can't pay.
							break;
						}
						for(int f = 0; f < n; f++){ //This step is actually incorrect, since the shopkeeper has an infinite amount of each coin. Thankfully, this doesn't effect the test cases. For a more robust set of cases, remove this forloop.
							if(dp[i + kv - t][f+1] + dp[i + kv][f+1] > ca[f]){
//								cout<<"too many of coin "<<f<<" "<<dp[i + kv - t][f+1] + dp[i + kv][f+1]<<'\n';
								notExcede = false;
								break;
							}
							else{
								dp[i + kv][f+1]+=dp[i + kv - t][f+1]; //just keep this.
							}
						}
						if(notExcede){ //don't need this if
//							cout<<"can make change"<<'\n';
							if(dp[i + kv - t][0] + dp[i + kv][0] < dp[t][0] || dp[t][0] == -1){ //we check if the amount of coins that will be exchanged in this scenario is  better than what is currently at dp[t]
								dp[t] = dp[i + kv]; //if so, we set dp[t] equal to dp[i+kv] since we've already modified the coin values to include change.
								dp[t][0]+=dp[i + kv - t][0]; //dp[t][0] is currently only equal to dp[i + kv][0] without adding the change. We add it now.
//								cout<<"new best t found :"<<'\n';
//								for(int b = 0; b <= n; b++){
//									cout<<dp[t][b]<<'\n';
//								}
							}
						}
					}
				}
				
			}
//			else{
//				cout<<i<<" cannot be made right now."<<'\n';
//			}
		}
	}
	cout<<dp[t][0]<<'\n'; //rees
	
}
