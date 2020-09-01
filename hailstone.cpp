#include <iostream>
using namespace std;

int main() {
  int num;
  int length = 0;
  
  cout << "Enter a number: ";
  cin >> num;
  
  cout << endl;
  
  while (num != 1) {
    //even
    if ((num % 2) == 0) {
      num = num / 2;
      cout << num << " "; //prints num
      length++;
    }
    else {
      //odd
      num = (3*num)+1;
      cout << num << " "; //prints num
      length++;
    }
  }
  
  cout << endl; //creates a new line
  cout << "Length: " << length << endl;
  
  return 0;
}

