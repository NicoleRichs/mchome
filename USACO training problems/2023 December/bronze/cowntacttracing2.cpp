#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int main(){
	int n;
	cin >> n;
	string s;
	cin >> s;
	vector<pair<int,int>> dis;
	int cs = 0;
	bool going = false;
	int minS = 3e5;
	for(int i = 0; i < n; i++){
		if(going){if(s[i] == '0'){
			going = false; 
			dis.push_back({cs, i-1});
			if(cs == 0){
				minS = min(minS, (i-1));
			}
			else{
				minS = min(minS, (i - cs )/2);
			}
		}
		}
		if(!going){if(s[i]=='1'){going = true; cs = i;}}
	}
	if(going){dis.push_back({cs, n-1});}
	minS = min(minS, (n-1 - cs));
	int lo = -1;
	int hi = minS+1;
//	cout<<lo<<" "<<hi<<'\n';
	int ans = 2e5;
	while(lo < hi){
		int mid = lo + (hi - lo + 1)/2;
//		cout<<"mid is "<<mid<<'\n';
		bool fail = false;
		int c = 0;
		for(pair<int,int> a : dis){
			if(a.second - a.first + 1 < (mid*2)+1){
				if(a.first != 0 && a.second != n-1){
					fail = true;
					break;
				}
				else{
					if(a.second - a.first < mid){
						fail = true;
						break;
					}
					else{
						c++;
					}
				}

			}
			else{
				double span = (2 * mid) + 1;
//				cout<<a.second - a.first + 1<<" "<<span<<'\n';
				c+=(ceil((a.second - a.first + 1)/span));
			}

		}
		if(!fail){
			ans = min(ans, c);
			lo = mid;	
		}
		else{
			hi = mid-1;
		}
	}
	cout<<ans<<'\n';
}
//BRUTE FORCE BRUTE FORCE TRUST THE PROCESS BRUTE FORCE OH GOD PLEASE GOD I NEED TO SHAVE MY HEAD
