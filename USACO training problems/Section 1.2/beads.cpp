/*
ID: ethanhp1
TASK: beads
LANG: C++14
*/
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

int main() {
  ofstream of ("beads.out");
  ifstream inf ("beads.in");
  int num;
  inf >> num;
  string beads;
  inf >> beads;
  string twice = beads;
  bool is_red = false;
  bool is_blue = false;
  int longest = 0;
  int curlen = 0;
  int prevlen = 0;
  int prevwlen = 0;
  int wlen = 0;
  bool is_same = true;
  char first;
  for(int b = 0; b < num; b++){
    if(b == 0){
      first = twice[b];
    }
    else{
      if(twice[b] != first){
        is_same = false;
      }
    }
  }
  if(is_same){
    longest = num;
  }
  else{  
    for(int i = 0; i < num; i++){
    if(!is_red && !is_blue){
      if(twice[i] == 'r'){
        is_red = true;
        curlen = 1+wlen;
        wlen = 0;
      }
      if(twice[i] == 'b'){
        is_blue = true;
        curlen = 1+wlen;
        wlen = 0;
      }
      if(twice[i] == 'w'){
        wlen++;
      }
    }
    else if(is_red){
      if(twice[i] == 'b'){
        if(curlen+prevlen-prevwlen > longest){
          longest = curlen+prevlen;
        }
        prevwlen = wlen;
        prevlen = curlen;
        curlen = wlen+1;
        wlen = 0;
        is_red = false;
        is_blue = true;
      }
      if(twice[i] == 'r'){
        curlen++;
        wlen = 0;
      }
      if(twice[i] == 'w'){
        curlen++;
        wlen++;
      }
    }
    else if(is_blue){
      if(twice[i] == 'r'){
        if(curlen+prevlen-prevwlen > longest){
          longest = curlen+prevlen;
        }
        prevwlen = wlen;
        prevlen = curlen;
        curlen = wlen+1;
        wlen = 0;
        is_red = true;
        is_blue = false;
      }
      if(twice[i] == 'b'){
        curlen++;
        wlen = 0;
      }
      if(twice[i] == 'w'){
        curlen++;
        wlen++;
      }
    }
  }
	int e=0;
	if(is_red){
		while(is_red){
	      if(twice[e] == 'b'){
	        if(curlen+prevlen-prevwlen > longest){
	          longest = curlen+prevlen-prevwlen;
	        }	          
			is_red = false;

	      }
	      else if(twice[e] == 'r' || twice[e] == 'w'){ 
	        curlen++;
	      }
	      e++;
	    }
	  }
	  
	  else if(is_blue){
	    while(is_blue){
	      	if(twice[e] == 'r'){
	        	if(curlen+prevlen-prevwlen > longest){
	          		longest = curlen+prevlen-prevwlen;
	        	}
	        	is_blue = false;
	      	}
	      	else{
	        	curlen++;
	      	}
	      	e++;
	    }
	  }
  }


  of << longest << endl;
} 
