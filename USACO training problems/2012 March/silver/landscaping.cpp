#include <bits/stdc++.h>
using namespace std;
int main(){
	int n, x, y, z;
	cin >> n >> x >> y >> z;
	//the strange idea:
	/*
	We have the 2 standard SED operations - insertion & deletion. However, the transportation throws a pretty large screw into our plans.
	However, a **big brain** play:
	1. We have at most 100 flowerbeds. We can treat moving from each one to the current and vice versa as an operation.
	2. We can represent this situation with a string. For flowerbed 1 of 4 dirt, we represent as 1111. This is the string we're editing.
	3. We can treat our third operation (moving from 1 bed to another) as follows:
		a. insert one more of the number we're moving the dirt from inside the string, to simulate removal.
		b. delete one of the number we're moving the dirt to inside the string, simulating addition.
		(note, the "string" refers to the "reference" or "endgoal" string.)
	This is really a stupid idea.
	4. I guess we could also think of this as a replacement operation, and not worry about order. In this case we just replace one character with another (if move one from 4 to 1, replace a 4 with a 1 in the string)
	*/
	vector<int> a;
	vector<int> b;
	int xl = 0;
	int yl = 0;
	for(int i = 0; i < n; i++){
		int e, f;
		cin >> e >> f;
		xl+=e;
		yl+=f;
		for(int c = 0; c < e; c++){
			a.push_back(i+1);
		}
		for(int d = 0; d < f; d++){
			b.push_back(i+1);
		}
	}
//	for(int i = 0; i < xl; i++){
//		cout<<a[i]<<" ";
//	}
//	cout<<'\n';
//	for(int j = 0; j < yl; j++){
//		cout<<b[j]<<" ";
//	
//	}
//	cout<<'\n';
	vector<vector<int>> dp(xl+1, vector<int>(yl+1));
	for(int i = 0; i <=xl; i++){
		dp[i][0] = i * y; //I FORGOT TO MULTIPLY BY Y THIS FUCKED EVERYTHING UP
	}
	for(int j = 0; j <= yl; j++){
		dp[0][j] = j * x; //SAME HERE AHHHHH
	}
	for(int i = 1; i<=xl; i++){
		for(int j = 1; j <= yl; j++){
			if(a[i-1] == b[j-1]){
				dp[i][j] = dp[i-1][j-1];
			}
			else{
				dp[i][j] = dp[i-1][j-1] + ((abs(a[i-1] - b[j-1])) * z);
				dp[i][j] = min(dp[i][j], dp[i-1][j] + y);
				dp[i][j] = min(dp[i][j], dp[i][j-1] + x);
			}
		}
	}
//	for(int i = 0; i <= xl; i++){
//		for(int j = 0; j <= yl; j++){
//			cout<<dp[i][j]<<" ";
//		}
//		cout<<endl;
//	}
	cout<<dp[xl][yl]<<'\n';
	//i swear i tried for like fifteen minutes random shit and it just didn't work because I DIDN'T ADD THE MULTIPLY ON LINES 46 AND 49 WTFFF
	//18 whole days later and my drought is broken, praise the feesh
}
