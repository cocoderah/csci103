/********************************************************
 * CS 103 PA 1: Commas
 * Name: Adelina Hudson
 * USC email: aahudson@usc.edu
 * Comments (you want us to know): please ignore my scratch comments, just me saving code for reference that is disregarding my program
 *
 * Description:
 *  Displays a 64-bit integer (long long) with
 *   commas for thousands, millions, billions, etc.
 *
 * ** ABSOLUTELY NO ARRAYS, NO `string`, NO `vector` **
 *  usage is allowed.
 *
 * Instead, you may only declare:
 *
 *    bool,
 *    int, or
 *    int64_t (long long)
 *
 *  The only library function allowed is pow(base, exp)
 *    defined in the <cmath> library.
 *
 *
 ********************************************************/

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
  long long n;
  cout << "Enter an integer:" << endl;

  cin >> n;
 
   //if negative
   if (n<0) { 
     cout << "-";
     n=-n;
   }
  
  
  long long temp = n; //temp n
  int digits = 0; //starting point
  
  //count the number of digits in n
  while (temp !=0) {
    temp = temp / 10;
    digits++;
    
  }
  
  //if input is 0 it prints and ends program
  if (digits == 0) {
    cout << n;
    return 0;
  }
  
  //temp2 variable
  long long c; 
  
  //while loop will run taking out the first digit and then "deleting" it, until no digits left
  while (digits!=0)  {
    c = n / (long long)pow(10, digits-1);
    cout << c;
    n = n % (long long)pow(10, digits-1);
    
    
    digits--; //subtract one digit, the number of digits left
    
    if ((digits >=3) && ((digits % 3) == 0)) { //checks every three digits after it has ran once, and makes sure it doesnt put it at the end
      cout << ","; //add comma
    }
  }
 
 
   /* SCRATCH:
    *int count = 1;
    *temp = temp % (int)pow(10, count);
    *count++;
    *
    *for (int i)
    *int64_t divisor = pow(10, n-1);
    *cout << (n*divisor) << endl;
   */

  /* End of your code */
  return 0;

}
