#include <bits/stdc++.h>
using namespace std;
int main(){
    int sp[500][500];
    int t, f, b;
    cin >> t >> f >> b;
    vector<int> ns;
    for(int i = 0; i < f; i++){
        int a;
        cin >> a;
        a--;
        ns.push_back(a);
    }
    for(int j = 0; j < 500; j++){
        for(int k = 0; k < 500; k++){
            if(j == k){
                sp[j][k] = 0;
            }
            else{
                sp[j][k] = 900;
            }
        }
    }
    for(int r = 0; r < b; r++){
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        sp[a][b] = c;
        sp[b][a] = c;
    }
    //floyd-warshall find all shortest paths
    for(int p = 0; p < t; p++){
        for(int x = 0; x < t; x++){
            for(int y = x; y < t; y++){
                sp[x][y] = min(sp[x][y], sp[x][p] + sp[p][y]);
                sp[y][x] = sp[x][y];
            }
        }
    }
    //go through all trees, see sum of distance to all nap spots
    long long least_dist = 1844674407370955161;
    int ans;
    for(int z = 0; z < t; z++){
        long long ca = 0;
        for(int n : ns){
            ca += sp[z][n];
        }
        if(ca < least_dist){
            least_dist = ca;
            ans = z;
        }
    }
    cout<<ans+1<<'\n';
}
