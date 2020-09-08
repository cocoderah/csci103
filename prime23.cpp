#include <iostream>
using namespace std;

int main() {
  //declare variables
  int userInt;
  int countTwo = 0;
  int countThree = 0;
  
  //prompt user and collect input
  cout << "Enter a positive integer:" << endl;
  cin >> userInt;
  
  //checks divisibility by 2 and repeated until cannot anymore
  while (userInt % 2 == 0) {
    userInt = userInt / 2; //declares new userInt that id divided by 2
    countTwo++; //adds to the count
  }
  
  //same as above but with '3'
  while (userInt % 3 == 0) {
    userInt = userInt / 3;
    countThree++;
  }
  
  //print statement
  if ((countThree >= 1) || (countTwo >= 1)) { //checks if it went through the loops above and added to the count
    cout << "Yes" << endl;
    cout << "Twos=" << countTwo << " " << "Threes=" << countThree << endl;
  }
  
  else {
    cout << "No" << endl;
  }
  
  return 0;
}
