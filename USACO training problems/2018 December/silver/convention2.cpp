#include <bits/stdc++.h>
using namespace std;
//struct for cow, stores arrival, stay time, and priority (smaller # = greater)
struct cow{
	int s; 
	int e; 
	int p;
};
//for sorting the queue array by arrival then by priority
bool cmpcow(cow c1, cow c2){
	if(c1.s == c2.s){
		return c1.p < c2.p;
	}
	return c1.s < c2.s;
}
//for sorting our actual queue (q). by priority since all cows in q are already there.
bool cmpp(cow c1, cow c2){
	return c1.p < c2.p;
}
int main(){
	vector<cow> queue;
	ifstream in("convention2.in");
	ofstream out("convention2.out");
	int cows;
	in >> cows;
	
	for(int i = 0; i < cows; i++){
		cow temp;
		in >> temp.s >> temp.e;
		temp.p = i;
		queue.push_back(temp);
	}
	
	sort(queue.begin(),queue.end(),cmpcow); //sorted chronologically
	
	int cc = 0; //cows counted.
	int ans = 0; 
	int ct = queue[0].s; //current time.
	int ss = 1; //current index to add. 
	vector<cow> q; //our actual queue, bad naming
	q.push_back(queue[0]); //prime the queue with the first one
//	for(int i = 0; i < cows; i++){
//		cout<<queue[i].s<<" "<<queue[i].e<<" "<<queue[i].p<<endl;
//	}
	while(cc < cows){
//		cout<<"CURRENTLY PROCESSING"<<" "<<q[0].s<<" "<<q[0].e<<" "<<q[0].p<<" AT TIME "<<ct<<endl;
//		cout<<"CURRENT ANS IS "<<ans<<endl;
//		cout<<"QUEUE BEFORE "<<endl;
//		cout<<"SS: "<<ss<<endl;
//		for(int i = 0; i < q.size(); i++){
//			cout<<q[i].s<<" "<<q[i].e<<" "<<q[i].p<<endl;
//		}
		//measure the time between arrival and starting to eat	
		ans = max(ans, (ct - q[0].s));
		//setting time to the end of eating
		ct+=q[0].e;
		//erasing the cow from the queue
		q.erase(q.begin());
//		cout<<"ADDING COWS:"<<endl;
		//we look, starting from our index ss, for cows that have arrived when this cow has finished. queue is conveniently chronologically sorted, and ss won't go back to ones we've done before.
		while(true){
			if(queue[ss].s <= ct && ss<cows){
				q.push_back(queue[ss]);
//				cout<<queue[ss].s<<" "<<queue[ss].e<<" "<<queue[ss].p<<" ADDED"<<endl;
				ss++;
			}
			else{
				break;
			}
		}
		//sorts queue chronologically
		sort(q.begin(),q.end(),cmpp);
		//increment our cows counted (termination condition for this loop)
		cc++;
//		cout<<"QUEUE AFTER "<<endl;
		//check if the queue is empty meaning no cows arrived while eating and none were waiting. Skips time to the next cow, adds it to the queue, and increments ss.
		if(q.size()==0){
			q.push_back(queue[ss]);
			ct = queue[ss].s;
			ss++;
			
		}
//		for(cow& c : q){
//			cout<<c.s<<" "<<c.e<<" "<<c.p<<endl;
//		}
//		cout<<"PASSCMPLT"<<endl;
	}
	//you made it!
	out<<ans<<endl;
	
}
