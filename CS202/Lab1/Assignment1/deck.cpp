//@author harsukh singh assignment 1
//CS 202 4/15/2015
//deck class generates an array of linear linked list

#include "helper.h"
using namespace std;


//@author harsukh singh assignment 1
//CS 202 4/15/2015
//constructor for deck, the number of cards are hard coded
deck::deck()
{
    number_of_suits = 4;
    suits = new suit[number_of_suits];
    size_of_suit = 10;
    suits[0].set_title("hearts");
    suits[1].set_title("spades");
    suits[2].set_title("diamond");
    suits[3].set_title("clubs");
    for(int i=0; i<number_of_suits;++i)
    {
        suits[i].make_suit(size_of_suit+1, 1);
	//suits[i].display_suit();
    }

}

//@author harsukh singh assignment 1
//CS 202 4/15/2015
//shuffle function for suits will shuffle an entire array of linked list
void deck::shuffle(suit* &suits)
{
    //function is divided into two parts a horizontal shuffle between cards in a suits and a vertical shuffle between suits
    for(int i = 0; i<number_of_suits; ++i){
        card* ptr_array[size_of_suit];
        /*for(int j = 0; j<size_of_suit;++j)
        {
            ptr_array[j] = NULL;
        }*/
        //srand(1000*i);
        horizontal_shuffle(&suits[i], ptr_array, size_of_suit);
       // suits[i].display_suit();
    }
    //cout<<"Beginning vertical shuffle"<<endl;
    vertical_shuffle(suits);
    /*for(int k = 0; k<number_of_suits; ++k)
    {
        suits[k].display_suit();
    }*/

}

//@author harsukh singh assignment 1
//CS 202 4/15/2015
//horizontal shuffle will shuffle the linked list with a pointer array also known as fisher-yates shuffle
void deck::horizontal_shuffle(suit *this_suit, card** ptr_array, int size)
{
    ptr_array[0] = this_suit->get_suit(); // returns a card* to *ptr_array[0] which is head 
    card* temp = this_suit->get_suit(); // traversal pointer
    for(int i = 1; (i< size && temp != NULL) ; ++i)
    {
       temp = temp->get_next(); // go next 
       ptr_array[i] = temp; //fill the array with pointers to the suits cards
    }
    for(int i = size - 1; i>0; --i)
    {
        //srand(time(NULL)); //seed value for temp
        int j = rand() % (i+1); //generate a random index 
        swap(ptr_array[i], ptr_array[j]); //swap the value of the pointers
    }
    /*for(int i = 0; i < size; ++i) 
    {
        cout<< ptr_array[i]->get_item();
        cout<< ptr_array[i]->get_title();
        cout<<endl;
    }*/
    this_suit->set_head(ptr_array[0]); //set head to the front 
    ptr_array[0]->set_prev(this_suit->get_suit()); //set previous
    for(int i = 1; i<size;++i)
    {
        ptr_array[i-1]-> set_next(ptr_array[i]); //iterate through and set next and prev
        ptr_array[i]-> set_prev(ptr_array[i-1]);
    }
    ptr_array[size - 1] -> set_next(NULL);
}


//@author harsukh singh assignment 1
//CS 202 4/15/2015
//shuffles vertically between suits this happens by generating two random indices in the arry and and getting a card object then swapping them
void deck::vertical_shuffle(suit* &suits)
{
    for(int i= 0; i<20; ++i){
        //srand(time(NULL));
        int index_one = rand() % number_of_suits; //two indices are required for a vertical shuffle
        //srand(104*1000*i+1);                                    //the indices point to the array of suits
        int index_two = rand() % number_of_suits;
        //int k = 1;
        while(index_one == index_two)
        {
            //srand(k*104);
            index_one = rand() % number_of_suits;
           // ++k;
            //srand(k*104);
            index_two = rand() % number_of_suits;
           // ++k;
        }
        card* ptr_one = suits[index_one].get_suit();
        card* ptr_two = suits[index_two].get_suit();
        //srand(k*104*i+1);
        int val_one = rand() % size_of_suit; //gets the number of times to call next to find card that needs to  be exchanged
        //srand(k*104*1000);
        int val_two = rand() % size_of_suit;
        for(int i = 0; i<=val_one && !ptr_one; ++i)
        {
            ptr_one -> get_next(); //gets 
        }
        for(int i = 0; i<=val_two && !ptr_two; ++i)
        {
            ptr_two -> get_next();
        }
        //swapping pointers for cards
        card* temp_one = ptr_one -> get_next();
        card* temp_two = ptr_one -> get_prev();
        ptr_one -> set_next(ptr_two->get_next());
        ptr_one -> set_prev(ptr_two->get_prev());
        ptr_two -> set_next(temp_one);
        ptr_two -> set_prev(temp_two);
    }
}

//@author harsukh singh assignment 1
//CS 202 4/15/2015
//swap function, modifies the pointers by, swapping addresses thus the pointers are passed by reference
void deck::swap(card* &i, card* &j)
{
    card* k = i;
    i = j;
    j = k;
}  

//@author harsukh singh assignment 1
//CS 202 4/15/2015
//draw card function will return the card at the top of the deck
card* deck::draw_card(suit* &suits)
{   
    int i = 0;
    bool next_card = false;
    card* to_return = suits[i].get_suit();
    while(to_return == NULL)
    {
	++i;
	to_return = suits[i].get_suit();
    }
    if(to_return == NULL)
    {
        cout<<"The deck is empty."<<endl;
        return to_return;
    }
    card* temp = to_return->get_next();
    if(temp != NULL){
	suits[i].set_head(temp);
	temp->set_prev(temp);
    }
    else{
	suits[i].set_head(NULL);
    }
    to_return->set_next(NULL);
    to_return->set_prev(NULL);
    return to_return;
}


//@author harsukh singh assignment 1
//CS 202 4/15/2015
//draw card wrapper function
card* deck::draw_card()
{
    return draw_card(suits);
}


//@author harsukh singh assignment 1
//CS 202 4/15/2015
//shuffle function for deck
void deck::shuffle()
{
    shuffle(suits);
}


//@author harsukh singh assignment 1
//CS 202 4/15/2015
//destructor for deck class
deck::~deck()
{
    delete[] suits;
}
