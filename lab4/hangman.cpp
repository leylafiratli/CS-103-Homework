// hangman.cpp
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
  int numTurns = 10;

  // Pick a random word from the wordBank
  const char* targetWord = wordBank[rand() % numWords];

  // More initialization code as needed
  char word[80];  // a blank array to use to build up the answer
                  // It should be initialized with *'s and then
                  //  change them to the actual letters when the 
                  //  user guesses the letter
  char*pointer = word;
  for(int i = 0;i<sizeof(targetWord)-1;i++){
     word[i]  = '*';
  }




  
  // An individual game continues until a word
  //  is guessed correctly or 10 turns have elapsed
  while(numTurns > 0) {
    /* ---------- I/O Stuff ---- */
    cout << targetWord << endl;
    cout << "Here is your word: ";
    if(numTurns > 1){
      cout << "You have " << numTurns << " lives remaining." << endl;
    }else{
      cout << "You have " << numTurns << " life remaining." << endl;
    }
    cout << word << endl;
    cout << "Guess a letter! : ";
    cin >> guess;
    /* --------- Done -----------*/
    
    
    int processedValue = processGuess(word,targetWord,guess);
    if(processedValue == 0) {
      numTurns--;
    }
    if(strcmp(word,targetWord)==0){
      wordGuessed = true;
      break;
    }
  }
  

  // Print out end of game status
  if(wordGuessed){
    cout << "Congratulations, you got it!" << endl;
  }else {
    cout << "Sorry, you didn't guess the word this time. Better luck next time!" << endl;
  }

    
  return 0;
}

// Given the current version of the word, target/selected word, and
// the character that the user just guessed, change the word to 
// "turn on" any occurrences the guess character and return a count
// of how many occurrences of 'guess' were found
int processGuess(char* word, const char* targetWord, char guess)
{
  int numberOfHits = 0;
  for(int i = 0; i<sizeof(targetWord)-1;i++){
    if(guess == targetWord[i]) {
      word[i] = guess;
      numberOfHits++;
      }
  }
  return numberOfHits;


}

