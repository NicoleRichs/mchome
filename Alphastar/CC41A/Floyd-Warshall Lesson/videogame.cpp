#include <bits/stdc++.h>
using namespace std;
int main(){
    vector<int> seq;
    int sp[100][100] = {};
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a;
        cin >> a;
        a--;
        seq.push_back(a);
    }
    for(int j = 0; j < n; j++){
        for(int k = 0; k < n; k++){
            int a;
            cin >> a;
            sp[j][k] = a;
        }
    }
    for(int x = 0; x < n; x++){
        for(int y = 0; y < n; y++){
            for(int z = 0; z < n; z++){
                sp[y][z] = min(sp[y][z], sp[y][x] + sp[x][z]);
            }
        }
    }
    long long ans = 0;
    for(int r = 1; r < m; r++){
        ans+=sp[seq[r-1]][seq[r]];
        
    }
    cout<<ans<<'\n';
}
