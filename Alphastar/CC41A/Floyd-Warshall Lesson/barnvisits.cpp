#include <bits/stdc++.h>
using namespace std;
const int MAXN = 500;
int BIGNUM = 10000;
int main(){
    int sp[MAXN][MAXN] = {};
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(i == j){
                sp[i][j] = 0;
            }
            else{
                sp[i][j] = BIGNUM;
            }
        }
    }
    for(int k = 0; k < m; k++){
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        // cout<<"SETTING PATHS "<<a<<" "<<b<<" TO "<<c<<'\n';
        sp[a][b] = c;
        sp[b][a] = c;
    }
    for(int x = 0; x < n; x++){
        for(int y = 0; y < n; y++){
            for(int z = y; z < n; z++){
                sp[y][z] = min(sp[y][z], sp[y][x] + sp[x][z]);
                sp[z][y] = sp[y][z];
            }
        }
    }
    for(int d = 0; d < n; d++){
        for(int e = 0; e < n; e++){
            cout<<sp[d][e]<<" ";
        }
        cout<<'\n';
    }
}
