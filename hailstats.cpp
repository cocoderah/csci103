#include <iostream>
using namespace std;

int main() {
  int min;
  int max;
  
  cout << "Enter the range that you want to search: ";
  cin >> min >> max;
  
  if (min > max) {
    cout << "Invalid range" << endl;
    return 0;
  }
  
  int num;
  int i = min;
  int lengthMax =0;
  int lengthMin =0;
  int minNum;
  int maxNum;
  
  //loop runs until max is hit
  while (i <= max) {
    num = i;
    int length = 0;
     while (num != 1) {
    //even
    if ((num % 2) == 0) {
      num = num / 2;
      length++;
    }
    else {
      //odd
      num = (3*num)+1;
      length++;
    }
  }
    //comparisons for max and min values
    if(i == min) { //sets first to start comparing
      lengthMin = length + 1;
    }
    if (length > lengthMax) {
      lengthMax = length;
      maxNum = i;
    }
    if (length < lengthMin) {
      lengthMin = length;
      minNum = i;
    }
  i++;
  }
  
  cout << "Minimum length: " << lengthMin << endl;
  cout << "Achieved by: " << minNum << endl;
  cout << "Maximum length: " << lengthMax << endl; 
  cout << "Achieved by: " << maxNum << endl;
 
  
  return 0;
}

