/*
ID: ethanhp1
TASK: gift1
LANG: C++14                 
*/
using namespace std;
#include <iostream>
#include <fstream>
#include <string>
int findpos(string peoplelist[], int people, string name){
  for(int j = 0; j < people; j++){
    if(peoplelist[j] == name){
      return j;
    }
  }
}

int main() {
  int people;
  ofstream fout("gift1.out");
  ifstream fin("gift1.in");
  fin >> people;

  string peoplelist[people];
  int moneylist[people];
  for(int a = 0; a < people; a++){
    moneylist[a] = 0;
  }
  for(int i = 0; i < people; i++){
    fin>>peoplelist[i];
  }
  for(int i = 0; i < people; i++){
    string curperson;
    int giftmoney;
    int split;
    fin>>curperson;
    fin>>giftmoney>>split;
    int givepos = findpos(peoplelist,people,curperson);
    int leftovers;
    int give;
    if(split == 0){
      leftovers = giftmoney;
      give = 0;
    }
    else{
      give = giftmoney/split;
      leftovers = giftmoney-(give*split);
    }
    
    moneylist[givepos]-=giftmoney;
    moneylist[givepos]+=leftovers;

    for(int l = 0; l < split; l++){
      string currec;
      fin>>currec;
      int recpos = findpos(peoplelist,people,currec);
      moneylist[recpos]+=give;
    }
  }
  for(int m = 0; m < people; m++){
    fout << peoplelist[m] << " " << moneylist[m] << endl;
  }
  return 0;
} 
