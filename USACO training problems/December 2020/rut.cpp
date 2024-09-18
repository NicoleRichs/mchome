#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main(){
	//i know that east facing cows won't interfere with one another unless they share the same y-coord, and that east facing cows won't be bothered by north facing cows that have x-coordinates smaller than them, 
	//or north facing cows that start at a y-coordinate higher than them. Same applies for north facing cows, those that share the same X-coordinate will interfere with one another, and eastward facing cows that start at a higher
	//y-coordinate may interfere with the cow. Could store each cow's "kill count" in an array, and could store stopped cows' final coordinates in another array. Maybe could have a struct containing direction, start coords, end coords, and killer id.
	//if a cow has no more cows heading in the opposite direction that could harm it, and is not behind another cow heading the same direction, it is considered infinite.
}
