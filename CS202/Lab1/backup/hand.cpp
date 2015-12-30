//@author harsukh singh  cs 202 assignment 1
//@hand class makes a hash table that represents the players hand

#include "helper.h"
using namespace std;


/************************
 * @author harsukh singh CS202 assignment 1
 * @function default constructor
 * @param const table size
 * @return void
 **************************/
hand::hand(int table_size)
{
    size = table_size;
    players_hand = new card*[size];
    for(int i=0; i<size;++i)
    {
        players_hand[i] = NULL;
    }  
    current_size = 0;
}


/************************
 * @author harsukh singh CS202 assignment 1
 * @function hash function
 * @param key integer 
 * @return index of table collision resolution technique used is the chaining
 **************************/
int hand::hash_function(int key)
{
    if(key > size) return -1;
    if(key <= 0) return -1;
    int index = (key - 1) % size;
    return index;
}


/************************
 * @author harsukh singh CS202 assignment 1
 * @function deletes the list given an index
 * @param a index given as head
 * @return void
 **************************/
void hand::delete_list(card* head)
{
    if(!head) return;
    delete_list(head->get_next());
    head->set_next(NULL);
    delete head;
}


/************************
 * @author harsukh singh CS202 assignment 1
 * @function function checks if the table is empty
 * @param void
 * @return boolean true or false
 **************************/
bool hand::is_empty()
{
    int count = 0;
    for(int i = 0; i< size; ++i)
    {
        if(players_hand[i] == NULL)
        {
            ++count;
        }
    }
    if(count == size) return true;
    return false;
}


/************************
 * @author harsukh singh CS202 assignment 1
 * @function gets the players cards associated with an index in the hash table
 * @param number
 * @return card* pointer that will return the pointer related to the index
 **************************/
card* hand::get_from_player(int num)
{
    if((num > size) || (num <= 0)) return NULL;
    int index = hash_function(num);
    if(index == -1) return NULL;
    return players_hand[index];
}


/************************
 * @author harsukh singh CS202 
 * @function sets the index related to num to zero
 * @param number integer
 * @return void
 **************************/
void hand::set_to_null(int num)
{
    if((num > size) || (num <= 0)) return;
    int index = hash_function(num);
    if(index == -1) return;
    players_hand[index] = NULL;
}


/************************
 * @author harsukh singh CS202 
 * @function default destructor
 * @param deletes list
 * @return void
 **************************/
hand::~hand()
{
    for(int i = 0; i<size; ++i)
    {
        card* temp = players_hand[i];
        if(players_hand[i])
        {
            delete_list(temp);
        }
    }
    delete[] players_hand;
}


/************************
 * @author harsukh singh CS202 
 * @function displays the players hand
 * @param void
 * @return integer success or false
 **************************/
int hand::display()
{
    int count = 0;
    for(int i = 0; i<size; ++i)
    {
        if(players_hand[i] == NULL)
        {
            ++count;
            if(count == size) return 0;
        }
        else{
            card* current = players_hand[i];
            while(current)
            {
                cout<<current->get_title() << " "
                << current->get_item()
                <<endl;
                current = current -> get_next();
            }
        }
    }
    return 1;
}


/************************
 * @author harsukh singh CS202 
 * @function getter function for returns the players hand
 * @param  void
 * @return card**
 **************************/
card** hand::get_hand()
{
    return players_hand;
}


/************************
 * @author harsukh singh CS202 
 * @function inserts card into the hand
 * @param card that is being inserted
 * @return returns index
 **************************/
int hand::insert_card(card* &this_card)
{
    if(this_card == NULL) return -1;
    int index = hash_function(this_card->get_item());
    if(index == -1 ) return -1;
    if(players_hand[index] == NULL)
    {
        players_hand[index] = this_card;
	this_card->set_next(NULL);
        return index;
    }
    card* place_holder = players_hand[index];
    card* temp = this_card;
    players_hand[index] = this_card;
    this_card ->set_next(place_holder);
    return index;
}


/************************
 * @author harsukh singh CS202 
 * @function counts the number of nodes or cards at a given index of the table
 * @param number to check for
 * @return number of cards contained in that index
 **************************/
int hand::check_book(int number)
{    
    int index = hash_function(number);
    if(index == -1) return -1;
    int count = 0;
    if(!players_hand[index]) return 0;
    card* temp = players_hand[index];
    while(temp)
    {
        temp = temp->get_next();
        ++count;
    }
    return count;
}


/************************
 * @author harsukh singh CS202 
 * @function checks for a book at every location of the table
 * @param void
 * @return the score if a book is forund
 **************************/
int hand::check_book()
{
    int count;
    int score = 0;
    for(int i = 1; i<=size; ++i)
    {
        count = check_book(i);
        if(count == 4)
        {
            ++score;
            card* index = get_from_player(i);
            delete_list(index);
	    set_to_null(i);
        }
    }
    return score;
}


/************************
 * @author harsukh singh CS202 
 * @function inserts a set of cards to a given index
 * @param card* and a number for the index to check for
 * @return returns 1 or 0
 **************************/
int hand::insert_cards(card* this_card, int num)
{
    if(this_card == NULL) return 0;
    int index = hash_function(num);
    if(index == -1) return 0;
    if(!players_hand[index]) 
    {
        players_hand[index] = this_card;
        return 1;
    }
    card* temp = players_hand[index];
    while(temp -> get_next())
    {
	temp = temp -> get_next();
    }
    temp->set_next(this_card);
    return 1;
}
