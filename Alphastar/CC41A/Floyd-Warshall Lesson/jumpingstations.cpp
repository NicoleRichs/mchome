#include <bits/stdc++.h>
using namespace std;
const int BIGNUM = 2000000000;
int main(){
    int sp[300][300] = {};
    for(int i = 0; i < 300; i++){
    	for(int j = 0; j < 300; j++){
    		if(i == j){
    			sp[i][j] = 0;
			}
			else{
				sp[i][j] = BIGNUM;
			}
		}
	}
    int n, m, t;
    cin >> n >> m >> t;
    for(int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
    	sp[a][b] = c;
    }
    for(int x = 0; x < n; x++){
        for(int y = 0; y < n; y++){
            for(int z = 0; z < n; z++){
                sp[y][z] = min(sp[y][z], max(sp[y][x], sp[x][z]));	
            }
        }
    }
    for(int r = 0; r < t; r++){
    	int from, to;
    	cin >> from >> to;
    	if(sp[from-1][to-1] == BIGNUM){
    		cout<<-1<<'\n';
		}
		else{
			cout<<sp[from-1][to-1]<<'\n';
		}
    	
	}
}
