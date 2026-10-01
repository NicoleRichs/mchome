#include <bits/stdc++.h>
//bad if statements aah aah aah 
int n;
char image[20][20];
struct pcl{
	int x1,y1,x2,y2;
};
std::vector<pcl> locs;
bool visited[20][20];
void visit(int i, int j, int color, int x1, int y1, int x2, int y2){
	visited[i][j] = true;
//	std::cout<<"visited: "<<i<<" "<<j<<" with color "<<color<<'\n';
	//aah if statements aah
	if (i > x1 && image[i-1][j]-'A'==color && !visited[i-1][j]) 
    	visit(i-1,j,color,x1,y1,x2,y2);
  	if (i < x2 && image[i+1][j]-'A'==color && !visited[i+1][j]) 
    	visit(i+1,j,color,x1,y1,x2,y2);
 	if (j > y1 && image[i][j-1]-'A'==color && !visited[i][j-1]) 
    	visit(i,j-1,color,x1,y1,x2,y2);
  	if (j < y2 && image[i][j+1]-'A'==color && !visited[i][j+1]) 
    	visit(i,j+1,color,x1,y1,x2,y2);
}
bool is_pcl(int x1, int y1, int x2, int y2){
	int num_colors = 0;
	int color_count[26] = {0};
	for(int i = x1; i <= x2; i++){
		for(int j = y1; j <= y2; j++){
			visited[i][j] = false;
		}
	}
	for(int i = x1; i <= x2; i++){
		for(int j = y1; j <= y2; j++){
			if(!visited[i][j]){
				int color = image[i][j] - 65;
				if(color_count[color] == 0){
//					std::cout<<"added a color "<<color<<'\n';
					num_colors++;
				}
				color_count[color]++;//accidentally put this line in the if statement, leading to incorrect detection of new areas as new colors always.
				visit(i,j,color,x1,y1,x2,y2);
			}
		}
	}
	if(num_colors!=2){
//		std::cout<<"Not two colors at "<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<" "<<num_colors<<"\n";
		return false;
	}
	bool f1 = false,fm = false;
	for(int i = 0; i < 26; i++){
		if(color_count[i] == 1){
			f1 = true;
//			std::cout<<"f1 true"<<'\n';
		}
		if(color_count[i]>1){
			fm = true;
//			std::cout<<"fm true"<<'\n';
		}
	}
	//seeing if we have both only one region for one color and multiple for another to fufill the criteria
	return f1 && fm;
}
bool contains(int x, int y){ //checks if PCL x is fully inside PCL y.
	return locs[x].x1 >= locs[y].x1 
    && locs[x].x2 <= locs[y].x2
    && locs[x].y1 >= locs[y].y1
    && locs[x].y2 <= locs[y].y2;
}
bool PCLM(int x){ //checks if a PCL is fully enclosed by another.
	for(int i = 0; i < locs.size();i++){
		if(i!=x && contains(x,i)){
			return false;
		}
	}
	return true;
}
int main(){
	std::ifstream in("where.in");
	std::ofstream out("where.out");
	in >> n;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			in >> image[i][j];
		}
	}
	//generating ALL the rectangles
	for(int i1 = 0; i1 < n; i1++){
		for(int j1 = 0; j1 < n; j1++){
			for(int i2 = i1; i2 < n; i2++){
				for(int j2 = j1; j2 < n; j2++){
					if(is_pcl(i1,j1,i2,j2)){
						pcl p = {i1,j1,i2,j2};
						locs.push_back(p);
//						std::cout<<i1<<" "<<j1<<" "<<i2<<" "<<j2<<"\n";
					}
				}
			}
		}
	}
//	std::cout<<is_pcl(0,0,3,2);
	int ans = 0;
	for(int i = 0; i < locs.size();i++){
		if(PCLM(i)){
//			std::cout<<locs[i].x1<<" "<<locs[i].y1<<" "<<locs[i].x2<<" "<<locs[i].y2<<'\n';
			ans+=1;
		}
	}
	out<<ans<<std::endl;
}
