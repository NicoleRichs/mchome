#include <bits/stdc++.h>
using namespace std;
int d, p, c, s, f;
int cv = 0;
const int BIGNUM = 2147483647;
bool con[220][220] = {};
struct edge{
	int a, b;
	int w;
};
vector<edge> e;
int dist[220] = {};
int main(){
	//note that we either have a negative cycle or one non-looping path will be good enough
	//we can represent the problem in negatives: we have to find the greatest value of a path, or if there is a positive cycle. We have some edges that are positive (free travel) and some negative (cost to fly to route).
	//Instead, think of this as finding the smallest loss, which we can use bellman-ford for. We represent each path, the dollar amount gained is negative, and if the only path there is by plane, we add the cost of the plane flight. 
	//Example, city 2 can make 100 money and costs 50 dollars from 1 -> 2. We can represent this as -100 + 50 for a weight of -50. If there are any negative cycles, our earnings outpace our spendings so that is technically an infinite money loop.
	cin >> d >> p >> c >> f >> s;
	for(int i = 0; i < p; i++){
		int a, b;
		cin >> a >> b;
		edge t;
		t.a = a-1;
		t.b = b-1;
		t.w = -d;
		e.push_back(t);
		cv++;
		con[a-1][b-1] = true;
	}
	for(int j = 0; j < f; j++){
		int a, b ,c;
		cin >> a >> b >> c;
		edge t;
		t.a = a-1;
		t.b = b-1;
		t.w = c - d;
		if(!con[a-1][b-1]){
			e.push_back(t);
			cv++;
		}
	}
	for(int i = 0; i < c; i++){
		dist[i] = BIGNUM;
	}
	dist[s-1] = 0;
	for(int i = 0; i < c-1; i++){
		for(int j = 0; j < cv; j++){
			int from = e[j].a;
			int to = e[j].b;
			int weight = e[j].w;
			if(dist[from]!=BIGNUM){
				if(dist[to] > dist[from] + weight){
//					cout<<dist[to]<<" "<<dist[from]<<" "<<weight<<'\n';
//					cout<<to<<" "<<from<<'\n';
					dist[to] = dist[from] + weight;
					
				}
			}
		}
	}
	bool cycle = false;
	for(int i = 0; i < cv; i++){
		int from = e[i].a;
		int to = e[i].b;
		int weight = e[i].w;
		if(dist[to] > dist[from] + weight){
			cycle = true;
		}
	}
	if(cycle){
		cout<<-1<<'\n';
	}
	else{
		int min = BIGNUM;
		for(int i = 0; i < c; i++){
//			cout<<dist[i]<<'\n';
			if(dist[i] < min){
				min = dist[i];
			}
		}
		cout<<(-1 * min) + d<<'\n';
	}
}
