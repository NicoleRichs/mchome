#include <bits/stdc++.h>
using namespace std; 
const int MAXN = 1500;
int main(){
	int n = 0;
	cin >> n;
	int da[n][n] = {};//right is 1, down is 2
	int costsr[n] = {}; //given the current row, return the cost for the vat at the end of that row
	int costsb[n] = {}; //given the current column, return the cost for the vat at the end of the column
	int prefsum[n][n] = {}; //given i and j, stores how many cows will touch <i,j>
	for(int i = 0; i < n + 1; i++){
		for(int j = 0; j < n+1; j++){
			if(i < n && j < n){
				char c;
				cin >> c;
				if(c == 'R'){
					da[i][j] = 1;
				}
				else{
					da[i][j] = 2;
				}
			}
			if(i == n ||  j == n){
				if(i == n && j == n){
					break;
				}
				else{
					int cost;
					cin >> cost;
					if(j == n && i != n){
						costsr[i] = cost;
					}
					else if(j != n && i == n){
						costsb[j] = cost;
					}	
				}
				
			}
		}
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			prefsum[i][j] = 1;
		}
	}
	//calculate the initial costs. just following directions and filling out the prefix sum
	int ic = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(da[i][j] == 1){
				if(j < n-1){
					prefsum[i][j+1]+=prefsum[i][j];	
				}
				else{
					ic+=(prefsum[i][j] * costsr[i]);
				}
			}
			else if(da[i][j] == 2){
				if(i < n-1){
					prefsum[i+1][j] +=prefsum[i][j];
				}
				else{
					ic+=(prefsum[i][j] * costsb[j]);
				}
			}
		}
	}
	cout<<ic<<'\n';
	//process every day
	int days = 0;
	cin >> days;
	for(int i = 0; i < days; i++){
		int c1, c2;
		cin >> c1 >> c2;
		c1--;
		c2--;
		int cx = c1;
		int cy = c2;
		bool p1 = false;
		bool p2 = false;
		if(da[c1][c2] == 1){
//			cout<<"hello";
			da[c1][c2] = 2;
			if(cy < n-1){
				cy++;	
			}
			else{ //this is for an edge case where the sign we flip originally pointed to a vat
				ic -= (prefsum[cx][cy] * costsr[cx]);
				p1 = true;
			}	
		}
		else if(da[c1][c2] == 2){
			da[c1][c2] = 1;
			if(cx < n-1){
				cx++;	
			}
			else{ //ditto above
				ic -= (prefsum[cx][cy] * costsb[cy]);
				p1 = true;
			}
			
		}
		while(!p1){ //we retrace the path that is no longer taken due to the sign being flipped, it takes O(n) time. When we reach an edge, we subtract the amount of cows at the flipped sign multipied by the cost of the vat.
//			cout<<"current coords : "<<cx <<" "<<cy<<'\n';
			prefsum[cx][cy]-=prefsum[c1][c2];	
//			cout<<da[cx][cy]<<'\n';
			if(da[cx][cy] == 1){
				if(cy < n-1){
					cy++;
				}
				else{
					ic-=(costsr[cx] * prefsum[c1][c2]);
					p1 = true;
				}
			}
			else if(da[cx][cy] == 2){
				
				if(cx < n-1){
					cx++;
				}
				else{
					ic-=(costsb[cy] * prefsum[c1][c2]);
					p1 = true;
				}	
			}
			//this happened because i flipped coordinates
//			else{
//				cout<<"we're not supposed to be here"<<'\n';
//				cout<<da[cx][cy]<<'\n';
//			}
		}
//		cout<<"temporary : "<<ic<<'\n';
		cx = c1;
		cy = c2;
		//accounting for yet more edge cases, in the situation where the sign we flipped now points directly to a vat
		if(cx == n-1 && da[cx][cy] == 2){
			ic+=(costsb[cy] * prefsum[cx][cy]);
			p2 = true;
		}
		else if(cy == n-1 && da[cx][cy] == 1){
			ic+=(costsr[cx] * prefsum[cx][cy]);
			p2 = true;
		}
		else if(da[cx][cy] == 2 && cx < n-1){
			cx++;
		}
		else if(da[cx][cy] == 1 && cy < n-1){
			cy++;
		}
		while(!p2){ //same as above but the - becomes a +
//			cout<<"current coords : "<<cx <<" "<<cy<<'\n';
			prefsum[cx][cy]+=prefsum[c1][c2];	
//			cout<<da[cx][cy]<<'\n';
			if(da[cx][cy] == 1){
				if(cy < n-1){
					cy++;
				}
				else{
					ic+=(costsr[cx] * prefsum[c1][c2]);
					p2 = true;
				}
			}
			else if(da[cx][cy] == 2){
				
				if(cx < n-1){
					cx++;
				}
				else{
					ic+=(costsb[cy] * prefsum[c1][c2]);
					p2 = true;
				}	
			}
		}
		//made it!
		cout<<ic<<'\n';
	}
}
