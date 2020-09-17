/*******************************************************************************
 * CS 103 Twenty-One (Blackjack) PA
 * Name: Adelina Hudson
 * USC email: aahudson@usc.edu
 * Comments (you want us to know):
 *
 *
 ******************************************************************************/

// Add other #includes if you need
#include <iostream>
#include <cstdlib>
#include <cstring>

using namespace std;

/* Prototypes */
void shuffle(int cards[]);
void printCard(int id);
int cardValue(int id);
void printHand(int hand[], int numCards);
int getBestScore(int hand[], int numCards);

const int NUM_CARDS = 52;

/**
 * Global arrays to be used as look-up tables, if desired.
 * It is up to you if and how you want to use these 
 */
const char suit[4] = {'H','S','D','C'};
const char* type[13] = 
  {"2","3","4","5","6","7",
   "8","9","10","J","Q","K","A"};
const int value[13] = {2,3,4,5,6,7,8,9,10,10,10,10,11};

/**
 * Should permute the deck of cards, effectively shuffling it.
 * You must use the Fisher-Yates / Durstenfeld shuffle algorithm
 *  described in the assignment writeup.
 */
void shuffle(int cards[])
{
  /******** You complete ****************/
  for (int i = NUM_CARDS-1; i >= 1; i--) 
  {
    int x; //temporary holder 
    int j = rand()%(i+1); //gets random card
    x = cards[i]; //temporary holder for card j
    cards[i] = cards[j];
    cards[j] = x;
    
  }
}

/**
 * Prints the card in a "pretty" format:   "type-suit"
 *  Examples:  K-C  (King of clubs), 2-H (2 of hearts)
 *  Valid Types are: 2,3,4,5,6,7,8,9,10,J,Q,K,A
 *  Valid Suits are: H, D, C, S
 */
void printCard(int id)
{
  /******** You complete ****************/
  if ((id % 13) < 9) { 
    cout << (id % 13) + 2 << "-";
  }
  if ((id % 13) == 9) {
    cout << "J-";
  }
  if ((id % 13) == 10) {
    cout << "Q-";
  }
 
  if ((id % 13) == 11) {
    cout << "K-";
  }
  
  if ((id % 13) == 12) {
    cout << "A-";
  }
  
 
  
  switch(id / 13) {
    case 0:
      cout << "H"; // << endl;
      break;
    case 1:
      cout << "S"; // << endl;
      break;
    case 2:
      cout << "D"; // << endl;
      break;
    case 3:
      cout << "C"; // << endl;
      break;
    default:
      break;
  }
  //cout << " ";
}

/**
 * Returns the numeric value of the card.
 *  Should return 11 for an ACE and can then
 *  be adjusted externally based on the sum of the score.
 */
int cardValue(int id)
{
  /******** You complete ****************/
  
  int valueCard = id % 13; //mod 13 gets the accurate position to pull from global array
  return value[valueCard]; //returns the global array in the correct position of the card using right now

}

/**
 * Should print out each card in the hand separated by a space and
 * then print a newline at the end.  
 * Should use printCard() to print out each card.
 */
void printHand(int hand[], int numCards)
{
  /******** You complete ****************/
  for (int i=0; i < numCards; i++){ //looping through the hand
    printCard(hand[i]); //printing the card in the seperate hand
    cout << " ";
    //cout << " (" << hand[i] << ") "; //for debugging purposes
  }
  
  cout << endl;

}

/**
 * Should return the total score of the provided hand.  
 * ACES should be treated as 11s to make the highest possible hand
 *  and only being reduced to 1s as needed to avoid busting.
 */
int getBestScore(int hand[], int numCards)
{
  /******** You complete ****************/
  
  int sum = 0; //sum of hand
  int amountOfAce = 0; //amount of ace as counter
 
  for(int i = 0; i < numCards; i++) { 
    sum += cardValue(hand[i]); //adds sum
    if (cardValue(hand[i]) == 11) {
      amountOfAce++; //adds a count of aces
    }
  }
  if ((sum > 21) && (amountOfAce > 0)) {
    while ((amountOfAce > 0) && (sum > 21)) {
      sum = sum - 10; //makes ace worth 1 instead of 11
      amountOfAce--;
    }
  }

  return sum;
}

/**
 * Main program logic for the game of 21
 */
int main(int argc, char* argv[])
{
  //---------------------------------------
  // Do not change this code -- Begin
  //---------------------------------------
  if(argc < 2){
    cout << "Error - Please provide the seed value." << endl;
    return 1;
  }
  int seed = atoi(argv[1]);
  srand(seed);
  //srand(37);

  int cards[52];
  int dhand[9];
  int phand[9];
  //---------------------------------------
  // Do not change this code -- End
  //---------------------------------------

  /******** You complete ****************/
  bool keepPlaying = true;
  while(keepPlaying) {
    
    char userChoice;
    int pSize = 2; //starter size
    int dSize = 2; // everyone gets dealt two cards
    
    
    
    for (int i= 0; i < NUM_CARDS; i++) {
      cards[i]=i; //assigns a coresponding card number to each card in the array
    }
    
    //shuffle deck
    shuffle(cards);
    
   //printHand(cards, 52); //check
    
    //gives dealer and player two starting cards
    for (int c = 0; c < 2; c++) {
      phand[c] = cards[2*c]; //goes back and fourth, multiplying by two lets it not repeat a card
      dhand[c] = cards[2*c+1];
    }
    
    cout << "Dealer: ? "; // does not show dealers first card
    printCard(dhand[1]); // prints dealers second card
    cout <<" " << endl; 
    cout << "Player:";
    printHand(phand, pSize); //itterates through each card printing it
    
    while(getBestScore(phand,pSize)<21){ //looking at player- they go first
      
      cout << "Type 'h' to hit and 's' to stay:";
      cin >> userChoice; //take in input
      cout << endl;
      
      if(userChoice == 'h'){ //hit
        phand[pSize] = cards[2+pSize]; //grabs next card
        pSize++; //ads count to hand
        cout << "Player:";
        printHand(phand,pSize); //prints card
      }
      else {
        break;
      }
      //while loop above only runs when under 21
      
      
    }
    
    if(getBestScore(phand, pSize)>21) { //player busts
      cout << "Player busts" << endl;
      cout << "Lose ";
      cout << getBestScore(phand,pSize) << " "; //prints ending score of player
      cout << getBestScore(dhand,dSize) << endl; //prints ending score of dealer
      
    }
    
    //if player still in game
    else if(getBestScore(phand,pSize<=21)){
      //if not busted the dealer has to play up to 17
      
      while(getBestScore(dhand, dSize)<17){
        dhand[dSize] = cards[dSize+pSize]; //gets next card in pile
        dSize++; //adds the count of the hand
      }
     
       //prints dealers hand
       cout << "Dealer:";
       printHand(dhand, dSize);
       cout << endl;
 
      
      //dealter busts
      if(getBestScore(dhand, dSize)>21){
        cout << "Dealer busts" << endl;
        cout << "Win " << getBestScore(phand,pSize);
        cout << " " << getBestScore(dhand, dSize);
   
      }
      
      //if dealer does not bust and scores need to be determined
      else {
        
        //win
        if (getBestScore(phand, pSize) > getBestScore(dhand, dSize)) {
          cout << "Win " << getBestScore(phand,pSize);
          cout << " " << getBestScore(dhand, dSize) << endl;
        }
        
        //lose
        else if(getBestScore(phand, pSize)< getBestScore(dhand, dSize)) {
          cout << "Lose " << getBestScore(phand,pSize);
          cout << " " << getBestScore(dhand, dSize) << endl;
        }
        
        //tie
        else{
          cout << "Tie " << getBestScore(phand,pSize);
          cout << " " << getBestScore(dhand, dSize) << endl; 
        }
      }
    }
    
    cout << endl; //adds extra line
    
    cout << "Play again? [y/n]";
    cin >> userChoice;
    
    //repeats to beginning of while loop, reshuffle etc.
    if(userChoice == 'y') {
      cout << endl;
      keepPlaying = true;
      
    }
    //quit game
    else{
      keepPlaying = false;
      break;
    }
    
  }
  return 0;
}

