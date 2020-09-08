#include <iostream>
using namespace std;

main () {
  //prompts user aand receives user int
  int userInt;
  cout << "Enter an integer between 0 and 999: ";
  cin >> userInt;
  
  //seperates each digit
  int dig1 = ((userInt % 100) % 10);
  int dig10 = (userInt % 100) / 10;
  int dig100 = userInt / 100;
  
  //print statements
  cout << endl;
  cout << "1's digit is " << dig1 << endl;
  cout << "10's digit is " << dig10 << endl;
  cout << "100's digit is: " << dig100 << endl;  
  
  
  return 0;
}
