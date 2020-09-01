/********************************************************
 * CS 103 PA 1: Abundant numbers
 * Name: Adelina Hudson
 * USC email: aahudson@usc.edu
 * Comments (you want us to know):
 *
 * Description:
 *   Displays the top 3 most "abundant" (see writeup)
 *   numbers in the input sequence.  The input sequence
 *   is assumed to be valid natural numbers separated
 *   by spaces and ending with 0.
 *
 *   ABSOLUTELY NO ARRAY or `string`/`vector`/etc. usage
 *   is allowed!

 *   You may only declare: bool, int, or unsigned int
 *   No library functions (beyond cin/cout) are allowed.
 *
 *   You may NOT modify any of the given template code.
 *   This ensures our automated checkers can parse your
 *   output.  Failure to follow this direction will lead
 *   to a score of 0 on this part of the assignment.
 ********************************************************/

#include <iostream>
using namespace std;

int main()
{
  // n1 is the number with the highest abundance, a1
  // n2 is the number with the 2nd-highest abundance, a2
  // n3 is the number with the 3rd-highest abundance, a3
  unsigned int n1 = 0, n2 = 0, n3 = 0;
  int a1 = 0, a2 = 0, a3 = 0;

  // num_abundant counts how many numbers in the input
  // sequence are abundant
  int num_abundant = 0;

  cout << "Enter a sequence of natural numbers, separated by spaces, ";
  cout << "and ending with 0."<< endl;

  int userNum;
  
  cin >> userNum;
  
  while (userNum != 0) {
    int sum = 0;
    for (int i = 1; i <= userNum; i++) {
      if ((userNum % i) == 0) {
        sum +=i;
      }
    }
    
    //abundance after subtracted original number
    int abun = 0;
    abun = sum - userNum;
    
    if (abun > userNum) {
      num_abundant++; //adds to the count
      if (abun > a1) { //replaces each rating
        a3 = a2;
        n3 = n2;
        a2 = a1;
        n2 = n1;
        a1 = abun;
        n1 = userNum;
      }
      else if (abun > a2) {  //replaces the remaining ratings
        a3 = a2;
        n3 = n2;
        a2 = abun;
        n2 = userNum;
      }
      else if (abun > a3) { //replaces a3 and disregards the last spot holder
        a3 = abun;
        n3 = userNum;
      }
    }
    
    cin >> userNum; //receives next number
  }

    
  /* End of your code */

  cout << "Abundant number count: " << num_abundant << endl;
  cout << "Top 3 most abundant numbers: " << endl;
  cout << n1 << " : " << a1 << endl;
  cout << n2 << " : " << a2 << endl;
  cout << n3 << " : " << a3 << endl;


  return 0;

}


    //first attempt
//     if (abun > userNum) {
//       num_abundant++;
//       if ((abun > a3) && (abun > a2) && (abun > a1)) {
//         a1 = newNum;
//         n1 = userNum;
//       }
//       if ((abun > a2) && (abun > a3) && (abun <= a1)) {
//         a2 = sum - userNum;
//         n2 = userNum;
//       }
//       if ((abun > a3) && (abun <= a2) && (abun <= a1)) {
//         a3 = sum - userNum;
//         n3 = userNum;
//       }
//      }
