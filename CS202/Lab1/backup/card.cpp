//@author harsukh singh cs 202 assignment 1
//CS 202 4/15/2015
//card class, simulates a node and card object found in a 52 card deck
#include "helper.h" 


//@author harsukh singh cs 202 assignment 1
//CS 202 4/15/2015
//default constructor
//sets all pointers to NULL and sets number to 0
card::card()
{
   number = 0;
   next = NULL;
   prev = NULL;
   flag = false;
   title = NULL;
}


//@author harsukh singhcs 202 assignment 1
//CS 202 4/15/2015
//constructor sets next and prev pointers to null and sets a title passed in as argument
//this constructor is used throughout the assignment
card::card(int num, char* this_title)
{
    number = num;
    next = NULL;
    prev = NULL;
    flag = false;
    title = new char[strlen(this_title) +1];
    strcpy(title, this_title);
}


//@author harsukh singh cs 202 assignment 1
//CS 202 4/15/2015
//another constructor with a next and prev pointer passed in the argument list
card::card(int num, card* next_ptr, card* prev_ptr, char* this_title)
{
    number = num;
    next = next_ptr;
    prev = prev_ptr;
    flag = false;
    title = new char[strlen(this_title) +1];
    strcpy(title, this_title);

}


//@author harsukh singh cs 202 assignment 1
//CS 202 4/15/2015
//destructor
// since the new keyword is used in this class to allocate memory for a card title the memory is deallocated in the destructor if the title is not a null 
card::~card()
{
    if(title != NULL) delete[] title;
}


//@author harsukh singh cs 202 assignment 1
//CS 202 4/15/2015
//getter function for the card title
char* card::get_title()
{
    return title;
}


//@author harsukh singh  cs 202 assignment 1
//CS 202 4/15/2015
//setter function for the card title
void card::set_title(char* this_title)
{
    title = new char[strlen(this_title)+1];
    strcpy(title, this_title);
}


//@author harsukh singh cs 202 assignment 1
//CS 202 4/15/2015
//setter function for the card number value
void card::set_item(int num)
{
    number = num;
}


//@author harsukh singh cs 202 assignment 1
//CS 202 4/15/2015
//getter function for the card number
int card::get_item()
{
    return number;
}


//@author harsukh singh cs 202 assignment 1
//CS 202 4/15/2015
//setter function for card flag
void card::set_flag(bool visited)
{
    flag = visited;
}


//@author harsukh singh cs 202 assignment 1
//CS 202 4/15/2015
//getter function for flag 
bool card::get_flag()
{
    return flag;
}

//@author harsukh singh cs 202 assignment 1
//CS 202 4/15/2015
//pointer setters for card class
void card::set_next(card* next_ptr)
{
    next = next_ptr;
}


void card::set_prev(card* prev_ptr)
{
    prev = prev_ptr;
}

//@author harsukh singh cs 202 assignment 1
//CS 202 4/15/2015
//getter functions for card class
card* card::get_next()
{
    return next;
}


card* card::get_prev()
{
    return prev;
}
