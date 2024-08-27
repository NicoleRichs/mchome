/*
ID: ethanhp1
TASK: friday
LANG: C++14
*/
#include <iostream>
#include <string>
#include <fstream>

using namespace std;
bool is_leap(int year){
  if(year%4==0){
    if(year%100==0){
      if(year%400==0){
        return true;
      }
      else{
        return false;
      }
    }
    else{
      return true;
    }
  }
  else{
    return false;
  }
}
int main() {
  ofstream of ("friday.out");
  ifstream is ("friday.in");
  int years;
  is >> years;
  int total_days = 0;
  int fts[7];
  for(int a = 0; a < 7; a++){
    fts[a] = 0;
  }
  for(int i = 1900; i < 1900+years;i++){
    bool feb = false;
    if (is_leap(i)){
      feb = true;
    }
    for(int m = 1; m < 13; m++){
      int days;
      if(m == 1 || m == 3 || m  == 5 || m == 7 || m == 8 || m == 10 || m == 12){
        days = 31;
      }
      else if(m==4 || m == 6 || m==9 || m==11){
        days = 30;
      }
      else if(m==2){
        if(feb){
          days = 29;
        }
        else{
          days = 28;
        }
      }
      for(int d = 1; d < days+1;d++){
        total_days++;
        if(d == 13){
          fts[(total_days%7)]++;
        }
      }
    }
  }
  of<<fts[6]<<" "<<fts[0]<<" "<<fts[1]<<" "<<fts[2]<<" "<<fts[3]<<" "<<fts[4]<<" "<<fts[5]<<endl;
} 