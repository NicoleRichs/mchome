//thought about this one all day, finally got to write it about 20 mins ago. Looks very similar to the usaco.guide solution except that one works on the 4th test case and mine doesn't. I still can't tell why.
//jk i commented out the print and it worked
#include <bits/stdc++.h>
using namespace std;

//the basic idea is to find the largest delta between where an element is and where it should be. Since every pass of Bessie's algorithm shifts every element in the wrong place one more to their correct place, the highest delta + 1 will be the answer.
//to do this, we're essentially going to use coordinate compression, using a struct containing the original index of the entry and its value.
// then, we'll sort using a custom comparator, and then loop through the sorted list to find the highest delta + 1 and return it.

struct entry{
	int index;
	int value;	
};

bool ssort(entry a, entry b){
	if(a.value == b.value){
		return a.index < b.index;
	}
	return a.value < b.value;
}

int main(){
	ifstream in("sort.in");
	ofstream out("sort.out");
	
	int n;
	in >> n;
	
	vector<entry> array(n);
	
	for(int i = 0; i < n; i++){
		in >> array[i].value;
		array[i].index = i;
	}
	
	sort(array.begin(),array.end(),ssort);
	
//	for(int t = 0; t < n; t++){
//		
//		cout<<array[t].index<<" "<<array[t].value<<endl;
//	
//	}
	
	int moos = 0;
	
	for(int j = 0; j < n; j++){
		
		int delta = array[j].index - j+1;
		
		if(delta > moos){
			
			moos = delta;
			
		}
	}
	
	out << moos << endl;
	
}
