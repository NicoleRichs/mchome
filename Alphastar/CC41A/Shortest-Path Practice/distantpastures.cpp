#include <bits/stdc++.h>
using namespace std;
struct coord{
	int x, y, t;
};
struct cmpc{
	bool operator()(coord const& c1, coord const& c2)
    {
        return c1.t < c2.t;
    }	
};

int main(){
	int n, a, b;
	cin >> n >> a >> b;
	vector<vector<bool>> pasture(n, vector<bool> (n));
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			char c;
			cin >> c;
			if(c == '('){
				pasture[i][j] = true;
			}
			else{
				pasture[i][j] = false;
			}
		}
	}
	int cl = 0;
	for(int i=  0; i < n; i++){
		for(int j = 0; j < n; j++){
			vector<vector<int>> dist(n, vector<int>(n, -1));
			dist[i][j] = 0;
			priority_queue<coord, vector<coord>, cmpc> tp;
			tp.push({i, j, pasture[i][j]});
			while(!tp.empty()){
				int cx = (tp.top()).x;
				int cy = (tp.top()).y;
				tp.pop();
				if(cx - 1 >= 0){
					int ta;
					if(pasture[cx-1][cy] == pasture[cx][cy]){
						ta = a;
					}
					else{
						ta = b;
					}
					if(dist[cx-1][cy] == -1 || dist[cx-1][cy] > dist[cx][cy] + ta){
						dist[cx-1][cy] = dist[cx][cy] + ta;
						tp.push({cx-1, cy, ta});
					}
				}
				if(cx + 1 < n){
					int ta;
					if(pasture[cx+1][cy] == pasture[cx][cy]){
						ta = a;
					}
					else{
						ta = b;
					}
					if(dist[cx+1][cy] == -1 || dist[cx+1][cy] > dist[cx][cy] + ta){
						dist[cx+1][cy] = dist[cx][cy] + ta;
						tp.push({cx+1, cy, ta});
					}
				}
				if(cy - 1 >= 0){
					int ta;
					if(pasture[cx][cy-1] == pasture[cx][cy]){
						ta = a;
					}
					else{
						ta = b;
					}
					if(dist[cx][cy-1] == -1 || dist[cx][cy-1] > dist[cx][cy] + ta){
						dist[cx][cy-1] = dist[cx][cy] + ta;
						tp.push({cx, cy-1, ta});
					}
				}
				if(cy + 1 < n){
					int ta;
					if(pasture[cx][cy+1] == pasture[cx][cy]){
						ta = a;
					}
					else{
						ta = b;
					}
					if(dist[cx][cy+1] == -1 || dist[cx][cy+1] > dist[cx][cy] + ta){
						dist[cx][cy+1] = dist[cx][cy] + ta;
						tp.push({cx, cy+1, ta});
					}
				}
			}
			for(int i =  0; i < n; i++){
				for(int j= 0 ; j < n; j++){
					cl = max(cl, dist[i][j]);
					if(dist[i][j] == -1){
						cout<<"oh no"<<'\n';
						for(int i = 0; i < n; i++){
							for(int j=  0; j < n;j++){
								cout<<dist[i][j]<<" ";
							}
							cout<<endl;
						}
						return 0;
					}
				}
			}
		}
	}
	cout<<cl<<'\n';
}
