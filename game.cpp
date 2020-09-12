// game.cpp
// Hangman game illustrates string library functions, 
// character arrays, arrays of pointers, etc.
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;

// Prototype. we'll define this below.
int processGuess(char* word, const char* targetWord, char guess);

// Define an array of strings (since a string is just a char array)
//  and since string are just char *'s, we really want an array of char *'s
const char* wordBank[] = {"computer", "president", "trojan", "program",
                          "coffee", "library", "football", "popcorn", 
                          "science", "engineer"};

const int numWords = 10;

int main()
{
  srand(time(0));
  char guess;
  bool wordGuessed = false;
  int c = 10; //remaining number of guesses
  int x = 0; //number of correct letters guessed
  // Pick a random word from the wordBank
  const char* targetWord = wordBank[rand() % numWords];

  // More initialization code as needed
  char word[80];  // a blank array to use to build up the answer
                  // It should be initialized with *'s and then
                  //  change them to the actual letters when the 
                  //  user guesses the letter
  int length = 0;
  for (int i = 0; i < strlen(targetWord); i++) {
    word[i] = '*'; //replaces whole word wIth *
    length++; //gives me the length of the hidden word
  }
  
  while (c != 0) { //while there are still guesses left
  cout << "Current word: " << word << endl; //prints out the word with letters and * either or both
  cout << c << " remain...Enter a letter to guess:" << endl;
  cin >> guess; //takes input
  x = processGuess(word, targetWord, guess); //declares x to the amount of correct letters guessed and placed into word
  if (x == 0) { //they did not get anything correct
    c--; //subtracts numbers of lives/guesses
  }
  if (x > 0) { //they got at least one letter correct
    length = length - x; //amount of hidden words left to guess
  }
  if (length == 0) { //no more hidden numbers left, they won
    wordGuessed = true; //change to true
    cout << "The word was: " << targetWord << ". You win!" << endl; //winning statement
    break; //ends program
  }
    
  }
  if (wordGuessed == false) //if they never finished the answer and ran out of number of lives
  { 
    cout << "Too many turns...You lose!" << endl; //LOOSER!!!!
  }

  
  // An individual game continues until a word
  //  is guessed correctly or 10 turns have elapsed




  // Print out end of game status


    
  return 0;
}

// Given the current version of the word, target/selected word, and
// the character that the user just guessed, change the word to 
// "turn on" any occurrences the guess character and return a count
// of how many occurrences of 'guess' were found
int processGuess(char* word, const char* targetWord, char guess)
{
  int amOfCorLet=0; //restarts every time it is called
  for (int i = 0; i < strlen(targetWord); i++) {
    if ((guess==targetWord[i]) && (word[i] == '*')) { //loops through if it is the same and has not been guessed before
      word[i] = guess; //replace * with letter
      amOfCorLet++; //adds to number of letters guessed correctly
      }
  }
  return amOfCorLet; //returns the amount guessed correctly
}
