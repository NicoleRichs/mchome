//oof i almost got this one in comp
#include <bits/stdc++.h>
#define ll long long
using namespace std;
struct dest{
	ll x, y, time;
	bool operator<(const dest &y) const { return time < y.time; } //custom comparator go brr
};
ll dist(ll ax, ll ay, ll bx, ll by){
	return ((ax-bx)*(ax-bx) + (ay-by)*(ay-by));
}
int main(){
	ifstream in("cowlibi.in");
	ofstream out("cowlibi.out");
	int gardens, culprits;
	cin >> gardens >> culprits;
	set<dest> occurances;	
	for(int i = 0; i < gardens; i++){
		ll x, y, time;
		cin >> x >> y >> time;
		dest t = {x,y,time};
		occurances.insert(t);
	}
	int ans = 0;
	for(int j = 0; j < culprits; j++){
		ll cx, cy, ct;
		cin >> cx >> cy >> ct;
		dest c = {cx, cy, ct};
		auto b = occurances.lower_bound(c); //these didn't quite mean what i thought they did
		auto a = occurances.upper_bound(c);
		if((*b).time == ct){ //so if the time that is at least the ct is equal to the ct (if our alibi is at a incident time)
			if((*b).x != cx || (*b).y != cy){ //check if the cow was there
				ans++;
			}
		}
	else{
		if(a == occurances.end()){ //if our cow's alibi is after he incidents
			a--; //since set.end doesn't point to the last item, but the memory address after it (this threw me off in comp)
			if(dist(cx, cy, (*a).x, (*a).y) > (ct-(*a).time)*(ct-(*a).time)){
				ans++;
			}
		}
		else if(b == occurances.begin()){ //if our alibi is before everything happens. set.begin actually does point to the first element of the set
			if(dist(cx,cy, (*b).x, (*b).y) > (ct-(*b).time)*(ct-(*b).time)){
				ans++;
			}
		}
		else if(a!=occurances.end() && b!=occurances.begin()){
			//this is if it's between two incidents
			b--; //since this one will be the one right after the greatest value smaller. THis also threw me off.
			if((dist(cx,cy, (*b).x, (*b).y) > (ct-(*b).time)*(ct-(*b).time)) || (dist(cx,cy, (*a).x, (*a).y) > (ct-(*a).time)*(ct-(*a).time))){ //idk why but this was originally an "and" statement and not "or"
				ans++;
			}
		}
	}
	}
	//ihatesetsihatesetsihatesets
	cout<<ans<<'\n';
}
