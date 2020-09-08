/* Author: Adelina Hudson
 * Program: color_conv
 * Description: Converts RGB -> CMYK color representation
 */
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
  
  //prompt my user
  cout << "Enter 3 integers (red, green, and blue), in that order:";
  
  //main variables declared
  double red;
  double green;
  double blue;
  double white;
  double cyan;
  double magenta;
  double yellow; 
  double black;
  
  //receive input for red green and blue
  cin >> red >> green >> blue;
  cout << endl;
  
  //calculate white
  double m1 = red/255;
  double m2 = green/255;
  double m3 = blue/255;
  white = max((max(m1, m2)), m3);
  
  //calculate cyan 
  cyan = (white - m1) / white;
  
  //calculate magenta
  magenta = (white - m2) / white;
  
  //calculate yellow
  yellow = (white - m3) / white;
  
  //calculate black
  black = 1 - white; 
  
  //print statment with results
  cout << "cyan: " << cyan << endl;
  cout << "magenta: " << magenta << endl;
  cout << "yellow: " << yellow << endl;
  cout << "black: " << black << endl;
  
  return 0;
}
