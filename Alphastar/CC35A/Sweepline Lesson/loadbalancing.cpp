#include <bits/stdc++.h>
using namespace std;
struct point{
	int x, y;
};
bool cmpx(point a, point b){
	return a.x < b.x;
}
bool cmpy(point a, point b){
	return a.y < b.y;
}
int main(){
	int n;
	cin >> n;
	vector<point> cx;
	vector<point> cy;
	cx.push_back({-1,-1});
	cy.push_back({-1,-1});
	for(int i = 0; i < n; i++){
		int a, b;
		cin >> a >>b;
		cx.push_back({a,b});
		cy.push_back({a,b});
	}
	cy.push_back({2000000000, 2000000000});
	cx.push_back({2000000000, 2000000000});
	sort(cx.begin(), cx.end(), cmpx);
	sort(cy.begin(), cy.end(), cmpy);
	int sv = 1001;
	int tr = n;
	int tl = 0;
	int br = 0;
	int bl = 0;
//	cout<<"PROCESSING BEGINS"<<'\n';
	for(int i = 0; i < n+2; i++){
//		cout<<"SWEEPLINE AT POS "<<cy[i].y<<"AT INDEX"<<i<<'\n';
		int ttr = tr;
		int ttl = tl;
		int tbr = br;
		int tbl = bl;
		for(int j = 0; j < n+2; j++){
			if(cx[j].y > cy[i].y && j!=0 && j!=n+1){
				ttl++;
				ttr--;
			}
			else if (j!= 0 && j != n+1){
				tbl++;
				tbr--;
			}
			if(j < n+1){
				while(cx[j+1].x == cx[j].x && j < n+1){
					j++;
					if(cx[j].y > cy[i].y && j!=n+1){
						ttl++;
						ttr--;
					}
					else if(j != n+1){
						tbl++;
						tbr --;
					}
					
				}
			}
//			cout<<ttr<<" "<<ttl<<" "<<tbl<<" "<<tbr<<'\n';
			sv = min(sv, max(max(ttr, ttl), max(tbl, tbr)));
		}
		tr--;
		br++;
		if(i < n-1){
			while(cy[i+2].y == cy[i+1].y){
				i++;
				tr--;
				br++;
			}
		}
	}
	cout<<sv<<'\n';
}
