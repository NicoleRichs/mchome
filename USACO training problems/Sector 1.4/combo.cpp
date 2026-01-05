/*
ID: ethanhp1
LANG: C++14
TASK: combo
*/
#include <bits/stdc++.h>
using namespace std;
//given the small constraints on this problem, we can just brute force it. Then just use a set to store the values, then find the length of the set (if any values are duplicated nothing will happen). Finished 12:37 PST on 10/21/2022.
int main(){
	set<vector<int>> sols;
	int n, f1, m1, f2, m2, f3, m3;
	ifstream in("combo.in");
	ofstream out("combo.out");
	in >> n;
	in >> f1 >> f2 >> f3;
	in >> m1 >> m2 >> m3;
	
	//loops thru all possible values of the first, second and third number. Corrected negative values to be that value + 50 to accurately portray a circle, then modulo n to take care of any overly large values (such as 51 to 1).
	for(int l1 = f1 - 2; l1 < f1 + 3; l1++){
		for(int l2 = f2 - 2; l2 < f2 + 3; l2++){
			for(int l3 = f3 - 2; l3 < f3 + 3; l3++){
				int c1 = l1;
				int c2 = l2;
				int c3 = l3;
//				cout<<c1<<" "<<c2<<" "<<c3<<endl;
				if(c1 <= 0){
					c1 = n+c1;
				}
				if(c2 <= 0){
					c2 = n+c2;
				}
				if(c3 <= 0){
					c3 = n+c3;
				}
				c1%=n;
				c2%=n;
				c3%=n;
	//				cout<<c1<<" "<<c2<<" "<<c3<<endl;
				vector<int> temp;
				temp.push_back(c1);
				temp.push_back(c2);
				temp.push_back(c3);
				sols.insert(temp); //if there's already that combo then it won't add another
			}
		}
	}
	
	//same thing but using the master combo
	for(int l1 = m1 - 2; l1 < m1 + 3; l1++){
		for(int l2 = m2 - 2; l2 < m2 + 3; l2++){
			for(int l3 = m3 - 2; l3 < m3 + 3; l3++){
				int c1 = l1, c2 = l2, c3 = l3;
				if(c1 <= 0){
					c1 = n+c1;
				}
				if(c2 <= 0){
					c2 = n+c2;
				}
				if(c3 <= 0){
					c3 = n+c3;
				}
				c1%=n;
				c2%=n;
				c3%=n;
//				cout<<c1<<" "<<c2<<" "<<c3<<endl;
				vector<int> temp;
				temp.push_back(c1);
				temp.push_back(c2);
				temp.push_back(c3);
				sols.insert(temp);
			}
		}
	}
	//:)
	out<<sols.size()<<endl;
}
