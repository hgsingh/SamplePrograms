/*****************
 * @author harsukh singh CS202 assignment 1
 * header file defines card class
 * suit class, deck class, hand class
 * libraries are also included from this class
 ******************/

#ifndef _HELPER
#define _HELPER
#include <cstring>
#include <cctype>
#include <cstdlib>
#include <iostream>
#include <ctime>

/*****************
 * @author harsukh singh
 * Card class emulates a node to create a variety of linked structures
 * The card class represents what one would find in a normal card from a deck of 52
 * this includes the title, number and next and previous pointers
 ******************/
class card
{
    private:
        int number; //number
        card* next; //next pointer
        card* prev; //previous pointer
	bool flag; //flag if card is being used, not used in the current versions of the game
        char* title; //title of the card
    public: //function prototypes are defined in the implementation file this class is mostly setters and getters
        card();
        card(int num, char* title);
        card(int num, card* next_ptr, card* prev_ptr, char* title);
	~card();
        void set_item(int num);
	void set_next(card* next_ptr);
	void set_prev(card* prev_ptr);
	void set_flag(bool visited);
	bool get_flag();
        char* get_title();
        void set_title(char* title);
	card* get_next();
	card* get_prev();
        int get_item();
};


/*****************
 * @author harsukh singh
 * The suit class generates a doubly linked list and the list is encapsulated in the deck class
 ******************/
class suit
{
    private:
        char* title; //title of the list that matches the title of the card
	card* head; //head pointer for the doubly linked list
        card* make_suit(card* head, card* temp, int size, int count, char* this_title); //make suit function
        int destructor(card* head); //destructor
    public:
	suit(char* this_title);
	suit();
	~suit();
        void set_title(char* this_title);
        char* get_title();
        int make_suit(int size, int count);
	card* get_suit();
        int display_suit();
        void set_head(card* temp);
};


/*****************
 * @author harsukh singh
 * The deck class generates four suits and implements a shuffle function
 ******************/
class deck{
    private:
        suit* suits;
        int size_of_suit;
        card* draw_card(suit* &suits);
        int number_of_suits;
        void shuffle(suit* &suits);
        void swap(card* &i, card* &j);
        void vertical_shuffle(suit* &suits);
        void horizontal_shuffle(suit* this_suit, card** ptr_array, int size);
    public:
        deck();
        ~deck();
        card* draw_card();
        void shuffle();
};


/*****************
 * @author harsukh singh
 * hand class generates a hand of the user, implemented as a hash map and uses the card as containment class
 ******************/
class hand{
    private:
        int size; //size of the table 
	card** players_hand;
        int current_size;
    public:
        hand(int table_size = 10);
        ~hand();
        card** get_hand();
        card* get_from_player(int num);
        bool is_empty();
        void delete_list(card* head);
	void set_to_null(int num);
        int hash_function(int key);
        int check_book();
        int insert_card(card* &this_card);
        int insert_cards(card* this_card, int number);
	int check_book(int number);
        int display();
};


#endif
