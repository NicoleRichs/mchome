#include <bits/stdc++.h>
using namespace std;
vector<int> startPos;
vector<int> newpos;
vector<long long> sh;
vector<long long> gr;
vector<long long> dp;
bool cmps(int a, int b){
	return (sh[a] > sh[b]);
}
bool cmpn(long long a, long long b){
	return a > b;
}
void run(){
		//check for fail states - cannot go down, or cannot go up. Takes O(NlgN)
	//if not fail, binary search the day. For each day, calculate the new position, then check if all the lines are at or past where they need to go. 
	//1. calculate new pos. Simply go thru 0 to n-1 and add their projected positions at day mid.
	//2. Find out where they need to go. For each dataset, precalculate how much change a plant must make, by subtracting the position where it needs to be from its position in the starting order.
	//3. If the plant needs to do negative change, see if the new position of the plant is less than or equal to the pos it has to be.
	//4. If the plant needs positive, see if new position is more than or equal to the pos it has to be.
	//5. Plants who need to be in the same position can be skipped.
	//5. If any fail, increase the # days. If success, decrease.
	//HOW TO MAKE THE STARTPOS LIST
	//1. Create a vector of numbers from 1 - n.
	//2. Sort the vector using a custom comparator that sorts 2 integers by the value of the indices that correspond to them in the starting position vector.
	//3. This gives you a vector where the index is the order of it, and the content of the index is the original index of the plant in given order.
	//HOW TO MAKE THE NEWPOS LIST
	//1. Go through all plants in given order and calculate their projected heights, adding them to a vector.
	//2. Duplicate the vector.
	//3. sort the projected height vector by the greatest.
	//4. Loop through all the indices in the duplicate array. FOr each height, binary search on the sorted vector to find its position.
	//5. The loop variable of #4 is the original index. The returned position is its new position.
	//6. Compare the original and new positions. TO get the original position, binary search on the startpos list.
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		long long a;
		cin >> a;
		sh.push_back(a);
	}
	for(int j = 0; j < n; j++){
		long long a;
		cin >> a;
		gr.push_back(a);
	}
	for(int j = 0; j < n; j++){
		long long a;
		cin >> a;
		dp.push_back(a);
	}
	for(int i = 0; i < n; i++){
		startPos.push_back(i);
	}
	cout<<"AAA"<<dp[3]<<'\n';
	sort(startPos.begin(), startPos.end(), cmps);
	//finding out our startposes
	vector<int> startRank; //startRank: i corresponds to the original index of the plant (i.e plant 4). startRank[i] is how many plants are taller than plant i, or its index in the startPos list. So startRank[i] = plant i's starting rank for height.
	for(int i = 0; i < n; i++){
		int lo = 0;
		int hi = n;
		while(lo < hi){
			int mid = lo + (hi - lo)/2;
			if(sh[startPos[mid]] > sh[i]){
				lo = mid+1;
			}
			else{
				hi = mid;
			}
		}
		startRank.push_back(lo);
	}
//	for(int i = 0; i < n; i++){
//		cout<<startRank[i]<<'\n';
//	}
//	
	int lo = 0;
	int hi = 2e9;
	while(lo < hi){
		int mid = lo + (hi - lo)/2;
//		int mid = 2;
		cout<<"MID: "<<mid<<'\n';
		vector<long long> nh;
		for(int i = 0; i < n; i++){
			nh.push_back(sh[i] + (mid*gr[i]));
		}
		vector<long long> dl = nh;
		vector<int> np;
		sort(nh.begin(), nh.end(), cmpn);
//		for(int i = 0; i < n; i++){
//			cout<<nh[i]<<' ';
//		}
//		cout<<'\n';
		for(int i = 0; i < n; i++){
			int nlo = 0;
			int nhi = n;
//			cout<<"FINDING "<<dl[i]<<'\n';
			while(nlo < nhi){
				int nmid = nlo + (nhi - nlo)/2;
//				cout<<nmid<<'\n';
//				cout<<nh[nmid]<<" versus "<<dl[i]<<'\n';
				if(nh[nmid] > dl[i]){
					nlo = nmid+1;
				}
				else{
					nhi = nmid;
				}
			}
			np.push_back(nlo);
		}
		bool sfail = false;
		bool lfail = false;
		cout<<startRank[3]<<" "<<dp[3]<<" "<<np[3]<<'\n';
		for(int i = 0; i < n; i++){
			if(startRank[i] < dp[i]){
				if(np[i] < dp[i]){
					sfail = true;
				}
				else if(np[i] > dp[i]){
					lfail = true;
				}
			}
			else if(startRank[i] > dp[i]){
				if(np[i] > dp[i]){
					sfail = true;
				}
				else if(np[i] < dp[i]){
					lfail= true;
				}
			}
			if(startRank[i] == dp[i]){
				if(np[i] != dp[i]){
					lfail = true;
				}
			}
		}
		if(sfail){
			lo = mid+1;
		}
		else{
			hi = mid;
		}
		
	}
	if(lo == 2e9){
		lo = -1;
	}
	bool works  = false;
	cout<<lo<<'\n';
	startPos.clear();
	newpos.clear();
	sh.clear();
	gr.clear();
	dp.clear();
}
int main(){
	int t;
	cin >> t;
	for(int i = 0; i < t; i++){
		run();
	}
}
