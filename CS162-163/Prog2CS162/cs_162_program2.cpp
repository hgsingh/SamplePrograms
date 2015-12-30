/*
 * @author Harsukh Singh
600 word algorithm 

This program includes four libraries iostream, cstring, string, cctype. iostream libraries were used for input and output from the user, the cstring library was used for the string compare functions (which are not very useful by the way), the string library was used for clearing the screen and the cctype libary wasused for handling upper case and lower case letters. A brief description of the functions used respectively is the get phrase function which takes a phrase and guess, with their respective sizes and sets the players choices by input. The check phrase function takes a two character ararys and compares the guess and word to the phrase to find if the word is in the phrase, however this is also used to check the players guess against the phrase (modular programming yo). Thelast function, check guess takes the guessed work , the phrase, count and the players scores to increment and decrement as described in the programming assignment and takes a success value to break the while loop and continue through main.

Algorithm for get_phrase(args): 
Arguments are comprised of the phrase character array, the size of the character array, the guess word character array that the player uses for identification and the size of the guess word array. 

    1. The user is prompted to fill these arrays using the proper iostream functions.
    2. The function then uses an iterator to loop through the array and check for spaces in the guess word array and uses a temporary dynamic array to get rid of the spaces. 

Algorithm for check_phrase(args):
Arguments for the function are guess word and phrase arrays which checks whether the word belongs to the array and then either returns an integer one or zero
    1. The function takes both arrays iterates through them and lower cases each letter to match the guess word to the array. 
    2. Next the function uses two local variable pointers that are pointing at the respective arrays.
    3. One variable pointer points to the first character of the guess word and the other one points to the nth index of the phrase.
    4. During iteration when the nth index and the first character of the guess word match, the temporary pointer and the iterate through both arrays until the string length of the guess word array is iterated and then returns a match. 
    5. If the word is not in the phrase the function returns a zero. 
    
Algorithm for check_guess(args):
This function takes the arguments provided, removes spaces from the the guess array and the players current guess and then checks the current guess and if the number of turns for the player is not yet complete the players scores are updated. In the iteration the function also checks if the word belongs to the phrase, which if it doesn't the player loses his/her turn and the then returns to the next round.  Further the scoring is based on the current count of the function and the user, the user loses points based on the count and the after the guess function is completed the dynamic temporary array variables are deleted at the end. This function could be constructed better but the time left is very little.

Algorithm for main(void):
Main initializes variables like guess,phrase and sizes of those arrays. It asks for user input to continue running the program.
    1. After initialization, check to see whose turn it is, prompt the proper player by using the mod     operation. Check the phrase given, while true
    2. Clear screen, prompt player two for the guess word.
    3. Check it against the guess word and deduct or add the proper amount of points.
    4. Prompt the users for continuity.  

*/
#include <iostream>
#include <cstring>
#include <string>
#include <cctype>
using namespace std;
//function prototypes
void get_phrase(char phrase[], int &size, char guess[], int &size_of_guess);
int check_phrase(char guess_word[], char phrase[]);
int check_guess(char guess_word[], char phrase[], int &count, int &start_score, int &player_score, int &success);
/*
@author Harsukh Singh
Main function to be called by the compiler and used during game play
@param void
@return integer 0
*/
int main()
{
  int guess = 10;
  int size = 80;
  int player_one_score = 0;
  int player_two_score = 0;
  char phrase[size];
  char guess_word[guess];
  char continuity;
  int turn = 2;
  cout<<"Welcome to the guessing game, enter a phrase with a special guess word and have your friend guess the special word!"<<endl;
  do{
   int start_score = 10;
   int success = 0;
   int count = 5;
   do{
       if(turn % 2 == 0){
         cout<<"Player 1"<<endl;
       }
       else{
         cout<< "Player 2"<<endl;
        }
       get_phrase(phrase, size, guess_word, guess);
       if(check_phrase(guess_word, phrase) == 0){
         cout<< "Please input a word that belongs to the phrase."<<endl;
      }
    }while(check_phrase(guess_word, phrase) == 0);
    cout<<string(80, '\n');
    while(count >= 0 && success == 0)
    {
      if(turn % 2 == 0){
        cout<<"Player 2"<<endl;
        check_guess(guess_word, phrase, count, start_score,player_two_score, success); 
      }
      else{
        cout<<"Player 1"<<endl;
        check_guess(guess_word, phrase, count, start_score,player_one_score, success);  
      }
    }
    ++turn;
    cout<<"Player 1 Score: "<<player_one_score<<endl;
    cout<<"Player 2 Score: "<<player_two_score<<endl;
    cout<<"Press y if you'd like to keep playing."<<endl;
    cin.get(continuity);
    cin.ignore(100,'\n');
    continuity = tolower(continuity);
    if(continuity == 'y') cout<<"Please switch players"<<endl;
  }while(continuity == 'y');
  return 0;
}
/* @author Harsukh Singh
 * This function gets the necessary arrays from the user to play the game and removes any spaces from the guess word.
 * @param Passed in as reference, the phrase array, the target guess word and the size of arrays.
 * @return void
 */
void get_phrase(char phrase[], int &size, char guess[], int &size_of_guess)
{
  char * compare = new char[size_of_guess];
  int count=0;
  cout<< "Please enter a phrase limited to " << size<<" characters."<<endl;
  cin.get(phrase, size, '\n');
  cin.ignore(100, '\n');
  cout<<"Please enter the guess word that belongs to the phrase limited to "<<size_of_guess<<" characters."<<endl;
  cin.get(compare, size_of_guess, '\n');
  cin.ignore(100, '\n');
  for(unsigned int i = 0; i<(unsigned)strlen(compare);++i)
  {
    if(*(compare+i) != ' ')
    {
      guess[i] = *(compare+i);
      count = count + 1;
      count<<count;
    }
  }
  delete[] compare;
}
/*@author Harsukh Singh
 * This function checks the phrase for the guess word 
 * @param char* guess, char* phrase
 * @return 1 or 0 
 */
int check_phrase(char guess_word[], char phrase[])
{
  char* comp1;
  char* comp2;
  int success = 0;
  for(unsigned int i = 0; i<(unsigned) strlen(guess_word); ++i)
  {
    guess_word[i] = tolower(guess_word[i]);
  }
  for(unsigned int j = 0; j<(unsigned) strlen(phrase); ++j){
    phrase[j] = tolower(phrase[j]);
  }
  for(unsigned int k = 0; k<(unsigned)strlen(phrase); ++k)
  {
    if(phrase[k] == guess_word[0])
    { int count = 0;
      comp1 = &phrase[k];
      comp2 = &guess_word[0];
      while(*comp1 == *comp2)
      {
        comp1 = comp1 +1;
        comp2 = comp2 +1;
        count = count + 1;
        if(count == ( unsigned) strlen(guess_word)-2){
          success = 1;
          return success;
        } 
      }
    }
  }
  return success;
}
/*@author Harsukh Singh
 * Keeps in track of the players score during game play and checks guess during the game play agains the given phrase
 * @params char* guess_word char* phrase, int count, players current score and start score 
 */
int check_guess(char guess_word[], char phrase[], int &count, int &start_score, int &player_score, int& success)
{
  char current_guess[10];
  char* compare_string = new char[10];
  char* compare_guess = new char[10];
  int player_score_temp;
  if(count == 5){
    player_score_temp = player_score + start_score; //only do once
  }
  else{
    player_score_temp = player_score;
  }
  cout<<"Please guess a word from the phrase:  "<<phrase<<endl;
  cin.get(current_guess, 10, '\n');
  cin.ignore(100, '\n');
  int q =0;
  int x =0;
  for(unsigned int i = 0; i<(unsigned)strlen(current_guess);++i) //eat up white space and lower-case all letters
  {  
    if(current_guess[i] != ' ')
    {
      compare_string[x] = tolower(current_guess[i]);
      x = x+1; //increment son
    }
  }
  compare_string[x] = '\0';
  //cout<<"current guess "<<compare_string<<endl;
  for(int k = 0; k< 10; ++k)
  {
    if(guess_word[k] !=' ')
    {
      compare_guess[q] = tolower(guess_word[k]);
      q = q + 1; //increment
    }
  }
  compare_guess[q] = '\0';
  //cout<<"correct guess "<<compare_guess<<endl;
  while(count >= 0)
  {
    if(strcmp(compare_guess, compare_string) == 0)
    {
     success = 1;
     player_score = player_score_temp;
     return count;
    }
    else if(check_phrase(compare_string, phrase) == 0)
    {
      player_score = player_score_temp - 2*count;
      count = 0;
      return count;
    }
    else{
      count = count -1;
      player_score = player_score_temp -2 ;
      return count;
    }
  }
  delete[] compare_guess;
  delete[] compare_string;
}

