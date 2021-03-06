/* Author: Harsukh Singh, Date: 1/21/2014, CS 162 Program 1 (Intructor Karla Fant)
 * 600 word algorithm starts here
 *INTRODUCTION:
 *The program utilizes two functions check_choice and scoring although this could have been done inside main. The 	*algorithm itself consists of taking a choice for a player using the get function provided by the iostream library and *checking it using comparison operations checks against the available values, being R, S and P and either returns a 1 *or 0. If the function returns 1, the user is prompted until a valid choice is entered or continues to capitalize the *choice.  Given that a correct choice was entered the choice is stored in a array with size length 2 for comparison *purposes. Player 2 is also given a similar set of choices. The screen is cleared each time. The scoring algorithm is a *set  of string comparators which determine which is a higher score, these values are hard coded, however a much clever *aglorithm  might be constructed by comparing the previous boolean values to determine the next set of values for n  *items. An example of this is rock, paper, scissors, lizard and spock. Spock smashes scissors and vaporizes rock; he is *poisoned by lizard and disproven by paper. Lizard poisons Spock and eats paper; it is crushed by rock and decapitated *by scissors. In this case the scoring counter function would be a little more sophisticated which would require a *little more time. Maybe this isn't even possible. However the array with two indices are used to store the value of *the score and updated anytime the player scores. To ignore all other values and just keep the first one cin.ignore is *used. The check choice function is a recursive function where the else returns the function if the correct value is *not returned thus not allowing for a boolean zero. The players can decide on a gaming period which consists of how *many times one plays the game, usually in the real word this is three. To check whether the user has entered a digit *the cctype library is used to make the isdigit function call. The string library is used to create blank spaces. 
 * 
 * 1. Initialize needed variables
 * 	i. Dummy variable i for counting through the while loop.
	ii.Character variable choice which determines the input choice from the buffer stream.
	iii. Character array choice_array needed for storing the chars of choices in an array.
	iv. Integer array score_collector to collect and return scores.
	 v.Integer  gaming_period to determine how many times the game is to be played.
	vi. Integer val boolean 1 or 0.
	vii. Integer pointer for score.
  2. Prompt the players and ask for a relevant gaming period.
      i. Decided appropriate gaming period.
      ii. Let user enter the appropriate gaming period.
      iii. If the gaming period is not appropriate ask for it again.
      iv. Check through various conditions, whether it is a digit, and within the appropriate range. 
  3. While the gaming period is within a valid range prompt players for their choices. (Iteration)
      i. Check each players choice and store appropriately (See 1)
      ii. Check the choice and see if it is within the appropriate parameters (See 4)
      iii. Capitalize each choice.
      iv. Prompt user on storage of the choice.
      v. Clear screen.
      vi. Check and update score. (See 5)
   4. Check choice function receives the choice parameter passed as a reference.
      i. If the choice is within the appropriate parameters which in this case means the passed parameter having the value return 1, which is a boolean true flag. 
      ii. Otherwise prompt the user on the incorrect choice and get another value, and clear the buffer stream. Then return the function to check again if the choice fits within a valid range. (Recursion)
   5. Scoring function takes in two parameters each pointers to arrays and returns a pointer to the score_collector function.
      i. Construct if statements to check the value of the choice array. 
      ii. Update score.
      iv. Return the array. 
 */

#include <iostream>
#include <cctype>
#include <string>
using namespace std;

/* Function check_choice checks the input choice and either returns 1 or the function itself until it returns 1
 * Parameters: char choice (passed by reference only) 
 * Return type int.
 */
int check_choice(char &choice)
{
  choice = toupper(choice);
  if(choice == 'R'){
    return 1;
  }
  else if( choice == 'P'){
    return 1;
  } 
  else if ( choice == 'S' ){
    return 1;
  }
  else{
    cout<< "You've chosen an invalid move, please try again"<<endl;
    choice= cin.get();
    cin.ignore(100, '\n');
    return check_choice(choice);
  }
}
/*Scoring function returns pointer to score collector object
 *Parameters: Pointers to choice array and score collector
 * Return type integer pointer.
 */
int* scoring(char* choice_array, int* score_collector )
{
  if(choice_array[0] == 'P' && choice_array[1] == 'R'){
    cout<< "Player 1 wins and Player 2 loses. \n"<<endl;
    score_collector[0] = score_collector[0] +1;
  }
  else if(choice_array[0] == 'P' && choice_array[1] == 'S'){
    cout<< "Player 1 loses and Player 2 wins. \n"<<endl;
    score_collector[1] = score_collector[1] +1;
  }
  else if(choice_array[0] == 'R' && choice_array[1] == 'P'){
    cout<< "Player 2 wins and Player 1 loses. \n"<<endl;
    score_collector[1] = score_collector[1] +1;
  }
  else if(choice_array[0] == 'R' && choice_array[1] == 'S'){
    cout<< "Player 1 wins and Player 2 loses. \n"<<endl;
    score_collector[0] = score_collector[0] +1;
  }
  else if(choice_array[0] == 'S' && choice_array[1] == 'P'){
    cout<< "Player 1 wins and Player 2 loses. \n"<<endl;
    score_collector[0] = score_collector[0] +1;
  }
  else if(choice_array[0] == 'S' && choice_array[1] == 'R'){
    cout<< "Player 2 wins and Player 1 loses. \n"<<endl;
    score_collector[1] = score_collector[1] +1;
  }
  else if(choice_array[0] == choice_array[1]){
    cout<< "This is a tie. \n";
  }
  else{ 
    cout<< "What does life really mean? \n";
    return 0;
  }
  return score_collector;
}
// main see algorithm
int main ()
{

  char choice;
  int i = 0;
  char choice_array[2];
  int score_collector[2] = {0,0}; 
  int gaming_period;
  int val = 0;
  int* score = NULL;
  cout<< "Welcome to the Rock, Paper, Scissors Game"<<endl;
  cout<< "The rules for the game are simple Rock defeats Scissors, Scissors defeats Paper and Paper defeats Rock"<<endl;
  cout<< "How many times would you like to play? Please enter a number between 1 to 100"<<endl;
  cin>> gaming_period;
  cin.clear();
  cin.ignore(100, '\n');
  cout<< "You've chosen to play " << gaming_period <<" times." <<endl;
  while(!cin.fail()){
    if((gaming_period<1 || gaming_period>100) && isdigit(gaming_period) == 0){
      cout<< "Invalid choice."<<endl;
      cout<< "How many times would you like to play?"<<endl;
      cin>>gaming_period;
      cin.clear();
      cin.ignore(100, '\n');
    }
    else
      break;
  }
  cout<< "Lets play \n"<<endl;
  for(int i = 0; i<gaming_period; i++){
    cout<< "Player 1 please enter your choice\n"<<endl;
    cout<< "Please press R for Rock, P for Paper and S for Scissors"<<endl;
    cin>>choice;
    cin.clear();
    cin.ignore(100, '\n');
    choice = toupper(choice);
    val = check_choice(choice);
    choice_array[0] = choice ;
    cout<< "Your choice has been recorded\n";
    cout << string(80, '\n');
    cout<< "Player 2 please enter your choice \n"<<endl;
    cin>>choice;
    cin.clear();
    cin.ignore(100, '\n');
    choice = toupper(choice);
    val = check_choice(choice);
    choice_array[1] = choice ;
    cout<< "Your choice has been recorded \n";
    cout << string(80, '\n');
    score = scoring(choice_array, score_collector); 
    cout<< "Current Score is:"<< "Player 1: "<< score[0] << " Player 1: "<< score[1] <<endl;
  }
  

  return 0;
}

