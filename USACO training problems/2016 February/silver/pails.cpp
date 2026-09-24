#include <bits/stdc++.h>
//i hate math.
int m,x,y,k = 0;
const int MAXN = 101;
int sol;
bool vis[MAXN][MAXN][MAXN] = {false}; //third dimension for if visited that config at that move number
void ff(int cx, int cy, int ck){
	if((vis[cx][cy][ck]) || (ck > k)){
		return;
	}
	vis[cx][cy][ck] = true;
	sol = std::min(sol, abs(cx+cy-m));
	//move 1 - empty x
	ff(0,cy,ck+1);
	//move 2 - empty y
	ff(cx,0,ck+1);
	//move 3 - fill x
	ff(x,cy,ck+1);
	//move 4 - fill y
	ff(cx,y,ck+1);
	//i used to have a bunch of if statements to do the pour-one-into-another things, but it didn't work. Replaced that part with these lines from usaco.guide and it just fixes itself.
	//I HATE MATH
	int leftoverX = (cx + cy > y ? cx + cy - y : 0);
	int leftoverY = (cx + cy > x ? cy + cx - x : 0);
	ff(leftoverX, std::min(y, cy+cx), ck+1);
	ff(std::min(x,cy+cx), leftoverY, ck+1);
}
int main(){
	std::ifstream in("pails.in");
	std::ofstream out("pails.out");
	in >> x >> y >> k >> m;
	std::cout<<x<<" "<<y<<" "<<k<<" "<<m<<std::endl;
	sol = m; //i initialized this to 500 before but didn't account for the case where you only get 1 move and not doing anything is most optimal
	ff(0,0,0);
	//i kept forgetting to change this from cout to out when submitting rip f
	out<<sol<<std::endl;
	//:D
}
