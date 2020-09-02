#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int roll()
{
  int n = rand() % 6 + 1;
  return n;
}

void printHistogram(int counts[]) 
{
  for (int i=0; i<21; i++) {
    cout << i+4 << ":";
      for (int j = 0; j < counts[i]; j++) {
       cout << "X";
      }
    cout << endl;
  }
  
}

int main ()
{
  srand(time(0));
  //cout << roll() << endl;
  
  
  int counts[21];
  
  //sets every element to zero
  for (int i = 0; i <=21; i++)
  {
    counts[i]=0;
  }
  
  //500 dice rolls
  for (int j = 0; j<500; j++) {
    int rollSum = 0;     
    rollSum = roll() + roll() + roll() + roll();
    
    /*
     * for (int h = 0; h<4; h++) { //four dice per dice roll
     d = roll();
      rollSum+=d;
    }
    */
    
    //could just have rollSum = roll() + roll() + roll() + roll();
    
    //adds to the corresponding array element
    for (int n = 4; n <= 24; n++)
    {
      if (rollSum == n)
      {
        ++counts[n-4];
      }
    }
  }
  
  printHistogram(counts);
  
  
  return 0;
}


