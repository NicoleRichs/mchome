#include <bits/stdc++.h>
using namespace std;
const int MAXWIDTH =1000;
int barn[MAXWIDTH+1][MAXWIDTH+1];
int main(){
	ifstream in("paintbarn.in");
	ofstream out("paintbarn.out");
	int rectangles, coats;
	in >> rectangles >> coats;
	for(int i = 0; i < rectangles; i++){
		int sx, sy, ex, ey;
		in >> sx >> sy >> ex >> ey;
		barn[sx][sy]++;
		barn[sx][ey]--;
		barn[ex][sy]--;
		barn[ex][ey]++;
	}
	int ans = 0;
	for(int x = 0; x <=MAXWIDTH; x++){
		for(int y = 0; y <=MAXWIDTH; y++){
			if(x > 0){
				barn[x][y]+=barn[x-1][y];
			}
			if(y > 0){
				barn[x][y]+=barn[x][y-1];
			}
			if(x > 0 && y > 0){
				barn[x][y]-=barn[x-1][y-1];
			}
			if(barn[x][y] == coats){
				ans++;
			}
		}
	}
	out<<ans<<'\n';
	
	
}
