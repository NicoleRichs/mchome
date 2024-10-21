/*
TASK: milk2
LANG: C++14
ID: ethanhp1
*/
//shelved for the time being jk lmao is done 1/24/2022 to 1/27/2022
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;
/*
Initial Algorithm:
iterate thru each interval, check a list of stored intervals for overlaps. If there is an overlap, update the length of that stored interval based on the five types of overlaps. If there are no overlaps with any existing interval, create a new one. Then, look at the list of intervals and look for overlaps in there. Replace the second value with -1, -1. Find the largest interval after the loop using a linear search.
Lessons learned: Never underestimate the usefulness of a sorted array.
Final Algorithm: Literally the same as above, but the list is sorted first. Due to the list being sorted, the time complexity could be reduced by only looking around the element for periods to merge with. 

*/
int determine_type(double first[2], double second[2]){
  if(first[0]>=second[0] && first[0] <= second[1]){
    if(first[1] > second[1]){
      return 1; // second[1] = first[1]
    }
    return 3; // no changes to second
  }
  else if(first[1]>=second[0] && first[1]<=second[1]){
    if(first[0]<second[0]){
      return 2; //second [0] = first[0]
    }
    return 3;
  }
  else if(first[1]>second[1] && first[0]<second[0]){
    return 4; //second[0] = first[0], second[1] = first[1]
  }
  else{
    return 5; //no overlap
  }
}
int main() {
  //input/output objects
  ifstream is("milk2.in");
  ofstream of("milk2.out");
  //amount of lines for to reading
  int intervals;
  is >> intervals;
  //storing the inputs and initializing values
  double time [intervals][2];
  double stored [intervals][2];
  for(int i = 0; i < intervals; i++){
    int time1, time2;
    is >> time1;
    is>> time2;
    time [i][0] = time1;
    time [i][1] = time2;
    stored [i][0] = 0;
    stored [i][1] = 0;

  }
  for(int n = 0; n < intervals; n++){
    for(int o = n+1; o < intervals; o++){
      if(time[n][0] > time[o][0]){
        double temp1 = time[o][0];
        double temp2 = time[o][1];
        time[o][0] = time[n][0];
        time[o][1] = time[n][1];
        time[n][0] = temp1;
        time[n][1] = temp2;        
      }
    }
  }
  //now we find overlaps or not xaxa
  int num_inside = 0;
  for(int i = 0; i < intervals; i++){
    bool is_in = false;
    for(int j = 0; j < num_inside; j++){
      int ol_type = determine_type(time[i],stored[j]);
      if(ol_type == 1){
        stored[j][1] = time[i][1];
        is_in = true;
      }
      else if(ol_type == 2){
        stored[j][0] = time[i][0];
        is_in = true;
      }
      else if(ol_type == 3){
        is_in = true;
        continue;
      }
      else if(ol_type == 4){
        stored[j][0] = time[i][0];
        stored[j][1] = time[i][1];
        is_in = true;
      }
    }
    if(!is_in){
      stored[num_inside][0] = time[i][0];
      stored[num_inside][1] = time[i][1];
      num_inside++;
    }
  }
  
  //now we rectify any overlapping overlaps  
  for(int k = 0; k < num_inside; k++){
    for(int l = 0; l < num_inside && l!=k; l++){
      int ol_cond = determine_type(stored[k],stored[l]);
      if(ol_cond == 1){
        stored[k][1] = stored[l][1];
        stored[l][0] = -1;
        stored[l][1] = -1;
      }
      else if(ol_cond == 2){
        stored[k][0] = stored[l][0];
        stored[l][0] = -1;
        stored[l][1] = -1;
      }
      else if(ol_cond == 3){
        stored[l][0] = -1;
        stored[l][1] = -1;
      }
      else if(ol_cond == 4){
        stored[k][0] = time[l][0];
        stored[k][1] = time[l][1];
        stored[l][0] = -1;
        stored[l][1] = -1;
      }
    } 
  }
  //now we actually find the answers
  int largest_period = 0;
  for(int m = 0; m < num_inside; m++){
    if(stored[m][1]-stored[m][0] > largest_period){
      largest_period = stored[m][1]-stored[m][0];
    }
  }
  cout<<largest_period<<endl;
  for(int a = 0; a < num_inside; a++){
    cout<<stored[a][0]<<" "<<stored[a][1]<<endl;
  }
  int max_dist = 0;
  for(int b = 1; b < num_inside; b++){
    if(stored[b][0]-stored[b-1][1]>max_dist && stored[b][0] !=-1 && stored[b-1][0]!=-1){
      max_dist = stored[b][0]-stored[b-1][1];
    }
  }
  cout<<max_dist<<endl;
  of<<largest_period<<" "<<max_dist<<endl;
}
