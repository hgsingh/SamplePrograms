//@author harsukh singh assignment 1
//player class with functions related to player
#include "prog1.h"
using namespace std;


//@author harsukh singh CS 202 assignment 1
//default constructor sets score to zero
player::player()
{
    score = 0;
}


//@author harsukh singh cs202 assignment 1
//display hand function displays the players hand
void player::display_hand()
{
    player_hand.display();
}

//@author harsukh singh cs 202 assignment 1
//wrapper function for check book of the players class will update the score if a book is found
int player::check_book()
{   
   int this_score =  player_hand.check_book();
   score = this_score + score;
   cout<<"now is "<<score<<"."<<endl;
}

//@author harsukh singh cs 202 assignment 1
//checks if hand is empty based on the is empty function if hand class 
bool player::is_hand_empty()
{
    return player_hand.is_empty();
}


//@author harsukh singh cs 202 assignment 1
//checks player hand for a number wrapper for hand class function 
bool player::check(int num)
{
    int to_check = player_hand.check_book(num);
    if((to_check == 0) || (to_check == -1)) return false;
    return true;
}

//@author harsukh singh cs 202 assignment 1
//draw card function will call hand class draw function, which makes this function a wrapper function 
int player::draw_card(card* to_draw)
{
    int check = player_hand.insert_card(to_draw);
    return check;
}

//@author harsukh singh cs 202 assignment 1
//retrieves the list of cards associated with num from player
card* player::get_from_player(int num)
{
    return player_hand.get_from_player(num);
}


//@author harsukh singh cs 202 assignment 1
//returns the players score 
int player::get_score()
{
    return score;
}


//@author harsukh singh cs 202 assignment 1
//inserts a list relating to the key given by num and stores it into the table used during the exchange of cards
void player::get_cards(card* these_cards, int num)
{
    player_hand.insert_cards(these_cards, num);
}

//@author harsukh singh cs 202 assignment 1
//removes a list from a players hand when exchanging cards
void player::remove_cards(int num)
{
    player_hand.set_to_null(num);
}


//@author harsukh singh cs 202
//sets score or updates the score 
void player::set_score(int current_score)
{
    score = current_score;
}


//@author harsukh singh cs 202
//default destructor
player::~player()
{

}