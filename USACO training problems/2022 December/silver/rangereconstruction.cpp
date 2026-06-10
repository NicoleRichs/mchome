//we like the pain (pain) - average cyberpunk music
//me rn: yes i can feel and touch it (the pain)
#include <bits/stdc++.h>
using namespace std;
int main(){
	
	int n;
	cin >> n;
	vector<vector<int>> lists;
	//takes input. Do note that the subarray sizes are shrinking from N to 1.
	for(int i = n; i > 0; i--){
		
		vector<int> list;
		for(int j = 0; j < i; j++){
		
			int temp;
			cin >> temp;
			list.push_back(temp);
		
		}
		
		lists.push_back(list);
	}
	
//	for(int i = n; i > 0; i--){
//		
//		for(int j = 0; j < i; j++){
//		
//			cout<<lists[n-i][j];
//		
//		}
//		cout<<endl;
//	
//	}
	
	vector<int> deltas;
	//initial stuff. We set the start as 0, deltas stores the offset from start.
	deltas.push_back(0);
	//the second value can be either + or - the delta, it's arbitrary
	deltas.push_back(lists[0][1]);
	
	for(int c = 2; c < n; c++){
		
//		cout<<"PASS"<<endl;
		//2 arrays with each of the possible new offsets added to it.
		int p1 = deltas[c-1] + lists[c-1][1];
		int p2 = deltas[c-1] - lists[c-1][1];
		vector<int> withP1 = deltas;
		withP1.push_back(p1);
		vector<int> withP2 = deltas;
		withP2.push_back(p2);
//		cout<<p1<<" "<<p2<<endl;
		
		//if the offset is 0
		if(p1 == p2){
//			cout<<"BOTH EQUAL"<<endl;
			deltas.push_back(p1);
		}
		
		else{
			
			bool isP1 = false;
			for(int b = c-1; b >=0; b--){
//				cout<<"B LOOP"<<endl;
				//ALL THE ITERATORS!
				auto s1 = withP1.begin() + b;
				auto s2 = withP2.begin() + b;
				auto e1 = withP1.begin() + c+1;
				auto e2 = withP2.begin() + c+1;
				//checks to see if the ranges of the subarrays match. Until it either reaches the start of the array or finds one that doesn't, start checking the total range of the array for the bth element of deltas. (conveniently stored as the last value there.)
//				cout<<*max_element(s1,e1) - *min_element(s1,e1)<<" "<<*max_element(s2,e2) - *min_element(s2,e2)<<" "<<lists[b][c-b]<<endl;
				//edit as of 12/24/2022 12:32AM: small but important change. Instead of comparing to n-b-1 (the last element of the subarray) I changed it to c-b, which means that we're actually looking at the range from the start to the added number. Original code passes first 5 test cases because it just so happened that the two were equivilant for the first 5 cases. Also made minor changeg to the output because the extra space was causing errors originally. silly dilet
				if(*max_element(s1,e1) - *min_element(s1,e1)  == lists[b][c-b] && *max_element(s2,e2) - *min_element(s2,e2)  == lists[b][c-b]){
				
					continue;
				
				}
				else if(*max_element(s1,e1) - *min_element(s1,e1)  == lists[b][c-b] && *max_element(s2,e2) -*min_element(s2,e2) != lists[b][c-b]){
				
//					cout<<"P1 TRUE"<<endl;
					isP1 = true;
					break;
				}
				
				else if(*max_element(s1,e1) - *min_element(s1,e1)  != lists[b][c-b] && *max_element(s2,e2) -*min_element(s2,e2) == lists[b][c-b]){
				
//					cout<<"P2 TRUE"<<endl;
					break;
				
				}
			}
			//:)
			if(isP1){
//				cout<<"PUSHED P1"<<endl;
				deltas.push_back(p1);
			
			}
			
			else if(!isP1){
//				cout<<"PUSHED P2"<<endl;
				deltas.push_back(p2);
				
			}
			
		}
	}
	
	for(int p = 0; p < n; p++){
		
		cout<<deltas[p];
		if(p < n-1){
			cout<<" ";
		}
		
	}
	cout<<'\n';
}
