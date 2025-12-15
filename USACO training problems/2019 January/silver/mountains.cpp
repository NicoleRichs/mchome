#include <bits/stdc++.h>
#define MAX 100000
using namespace std;
//note: if the sum of a mountain's x and y are smaller than another's and the difference of the x and y is greater, than it is hidden. If the difference is the same but the sum is smaller the mountain with the smaller sum is hidden. If the sum is the same but the difference is smaller the smaller difference is hidden.
//these are out here so compare works
int sum[MAX];
int diff[MAX];
//implementation of the conditions described above
bool compare(int a, int b){
	if(diff[a] == diff[b]){
		return sum[a] > sum[b];
	}
	return diff[a] < diff[b];
}
int main(){
	ifstream in("mountains.in");
	ofstream out("mountains.out");
	int n = 0;
	in >> n;
	int order[n];
	for(int i = 0; i < n; i++){
		int x,y;
		in >> x >> y;
		sum[i] = x+y;
		diff[i] = x-y;
		order[i] = i;
	}
	//sorting each mountain using the compare function, which takes the mountains' number and then compares the sum and differences of the mountains.
	sort(order,order+n,compare);
	int maxsum = -1;
	int ans = 0;
	for(int k = 0; k < n; k++){
		if(sum[order[k]] > maxsum){
			ans++;
			maxsum = sum[order[k]];
		}
	}
	out << ans << endl;
}
