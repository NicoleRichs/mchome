#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <math.h>
using namespace std;
int main() {
  int farms;
  cin >> farms;
  long long paths[farms];
  for(long long a = 0; a < farms; a++){
    paths[a] = 0;
  }
  for(long long  f = 0; f < farms-1; f++){
    long long  num1, num2;
    cin >> num1 >> num2;
    ++paths[num1-1];
    ++paths[num2-1];
  }
  long long  turns = farms-1;
  for(long long  c = 0; c < farms;c++){ 
    int children = paths[c];
    if(c!=0) {
      children--;
    }
    if(children>0 || c == 0){
      int doublings=0;
      int infected_at_node = 1;
      while(children+1>infected_at_node){
        doublings++;
        infected_at_node*=2;
      }
      turns+=doublings;
    }
  }
  cout<<turns;
}
