#include <bits/stdc++.h>
using namespace std;
struct edge{
	int cow;
	int to;
	bool first;
	
	edge() {};
    edge(int cow, int to, bool first) : cow(cow), to(to), first(first) {};
};
int n, m;
vector<edge> adjl[100001];
bool vis_cycle[100001]; // array for cycle finding
bool vis[100001]; // visited array for finding which order of cows we should use
bool happy[100001]; 
 
int hungry = 0;
queue<int> order;
int ignoren = -1;
int first_node = -1; // the cereal we start the search from, if the CC is not a tree then this must be on a cycle

void find_cycle(int cur, int prev = -1) {
    vis_cycle[cur] = true; 
    for (edge next : adjl[cur]) {
        if (vis_cycle[next.to]) {
            if (first_node == -1 && next.to != prev) {
                if (next.first) {
                    first_node = next.to; 
                } else {
                    first_node = cur;
                }
                
                ignoren = next.cow; 
                order.push(next.cow);
                happy[next.cow] = true;
            }
        } else {
            find_cycle(next.to, cur);
        }
    }
}
 
void dfs(int cur) {
    vis[cur] = true;
    for (edge next : adjl[cur]) {
        if (!vis[next.to] && next.cow != ignoren) { 
            happy[next.cow] = true;
            order.push(next.cow);
            dfs(next.to);
        }
    }
}
 
int main() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        int a, b;
        cin >> a >> b;
        adjl[a].push_back({i+1, b, false});
        adjl[b].push_back(edge{i+1, a, true});
    }
 
    for (int i = 1; i <= m; ++i) {
        first_node = -1;
        ignoren = -1;
        if (!vis[i]) {
            find_cycle(i);
            if (first_node > 0) {
                dfs(first_node);
            } else {
                dfs(i);
            }
        }
    }
 
    for (int i = 1; i <= n; ++i) {
        if (!happy[i]) {
            ++hungry;
            order.push(i);
        } 
    }
 
    cout << hungry << endl;
    while (!order.empty()) {
        cout << order.front() << endl; 
        order.pop();
    }
 
    return 0;
}
