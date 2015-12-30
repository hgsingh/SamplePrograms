//@author harsukh singh cs 202 assignment 1
//CS 202 4/15/2015
//suit class generates a list with an associated title
#include "helper.h"
using namespace std;


//@author harsukh singh cs 202 assignment 1
//CS 202 4/15/2015
//constructor for the suit class creats a suit with head set to null 
// and passes a title in as a param
suit::suit(char* this_title)
{
    title = new char[strlen(this_title)+1];
    strcpy(title, this_title);
    head = NULL;
}


//@author harsukh singh cs 202 assignment 1
//CS 202 4/15/2015
//default constructor for a suit class
suit::suit()
{
    title = NULL;
    head = NULL;
}


//@author harsukh singh cs 202 assignment 1
//CS 202 4/15/2015
//destructor that destroys the list if head is not null
int suit::destructor(card* head)
{
    if(head == NULL)
    {
        return 1;
    }
    destructor(head->get_next());
    head->set_next(NULL);
    head->set_prev(NULL);
    delete head;
    return 1;
}


//@author harsukh singh cs 202 assignment 1
//CS 202 4/15/2015
//default destructor
suit::~suit()
{
    if(title != NULL) delete[] title;
    destructor(head);
}


//@author harsukh singh cs 202 assignment 1
//CS 202 4/15/2015
//setter function for the suit class will set the title
void suit::set_title(char* this_title)
{
    title = new char[strlen(this_title) + 1];
    strcpy(title, this_title);
}


//@author harsukh singh cs 202 assignment 1
//CS 202 4/15/2015
//getter function for suit class will return the title of the suit
char* suit::get_title()
{
    return title;
}


//@author harsukh singh cs 202 assignment 1
//CS 202 4/15/2015
//make suit function generates a list based on the count specified
int suit::make_suit(int size, int count)
{
    head = make_suit(head, head, size, count, title);
    return 1;
}
//@author harsukh singh cs 202 assignment 1
//CS 202 4/15/2015
/*make suit function generates a list list recursively based on head and the size parameter passed in, copies the title variable of class into the cards that are generated.*/
card* suit::make_suit(card* head, card* temp, int size, int count, char* this_title )
{
    if(head == NULL)
    {
        head = new card(count, this_title);
        ++count;
        card* prev = temp;
        temp = head;
        head->set_prev(prev);

    }
    if(count == size)
    {
	head -> set_next(NULL);
	return head;
    }
    head->set_next(make_suit(head->get_next(), temp, size, count, this_title));
    return head;
}


//@author harsukh singh cs 202 assignment 1
//CS 202 4/15/2015
//returns the head of the suit
card* suit::get_suit()
{
    return head;
}


//@author harsukh singh cs 202 assignment 1
//CS 202 4/15/2015
//setter function for head
void suit::set_head(card* temp)
{
    head = temp;
}

//@author harsukh singh cs 202 assignment 1
//CS 202 4/15/2015
//test function to see if list is built
int suit::display_suit()
{
    if(!head) return 0;
    card* current = head;
    while(current->get_next() != NULL)
    {
        int to_display = current -> get_item();
        cout<<current->get_title()<<endl;
        cout<<to_display<<endl;
        current = current->get_next();
    }
    /*while(current != head)
    {
        cout<<current->get_item()<<endl;
        cout<<current->get_title()<<endl;
        current = current -> get_prev();
    }*/
    return 1;
}
