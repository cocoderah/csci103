#include <iostream>
using namespace std;
#include <cmath>

int main () {
  int degreeTheta; //declares a variable to assign user input to
  cout << "Enter the angle theta in degrees:" << endl; //prompt question
  cin >> degreeTheta; //takes input
  
  //double radian = M_PI / 180; //part of the conversion for radian
  //int bottomDegree = 180 - 90 - degreeTheta; //other angle besides theta incase I need it
  double degreeRadians = degreeTheta * (M_PI / 180); //turns degrees into radians
  //int xAxisSize = floor(31*tan(degreeRadians)); //this was my equation but then I added it into my nested loop
  //double size = tan(degreeRadians);
  
  for (int i = 0; i <= 30; i++) { //keeps the height at the specific number 31
    int xAxisSize = floor(i*tan(degreeRadians)); //calculates the amount of ASCII per each line taken from the overall equation above
    for (int j = 0; j <= xAxisSize; j++) { //size going across
      if ((xAxisSize >= 20) && (xAxisSize <= 30)) { //creates the cliff between 20 and 30
        xAxisSize = 20; //sets number to 20
      }
      cout << "*"; //prints ASCII
    }
    cout << endl; //creates a new row after running through the nested for loop
  }
  
  return 0;
}

