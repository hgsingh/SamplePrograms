//@author harsukh singh assignment 3 CS202
//5/12/2012
#include "table.h"
using namespace std;
/***********
 *@author harsukh singh
 *@function node constructor
 *@args void
 *@return void
 ***********/
node::node():next(0), a_song(0){}


/***********
 *@author harsukh singh
 *@function copy constructor
 *@args const next_obj
 *@return void
 ***********/
node::node(const node &obj):next(0)
{
    copy_lll(a_song, obj.a_song); 
}

/***********
 *@author harsukh singh
 *@function copy linked list function
 *@args song to copy to as head and song to copy
 *@return int 1 or 0
 ***********/
int node::copy_lll(song * &head, song* to_copy)
{
    if(!to_copy)
    {
        head = NULL;
        return 1;
    }
    head = new song(*to_copy);
    return copy_lll(head->get_next(), to_copy->get_next());
}

/***********
 *@author harsukh singh
 *@function copy constructor
 *@args const song obj
 *@return void
 ***********/
node::node(const song &obj):next(0)
{
   a_song = new song(obj); 
}



/***********
 *@author harsukh singh
 *@function returns the next pointer
 *@args void
 *@return node*& object
 ***********/
node* & node::get_next() 
{
    return next;
}


/***********
 *@author harsukh singh
 *@function returns the song object
 *@args void
 *@return song*& object
 ***********/
song* & node::get_song()
{
    return a_song;
}

/***********
 *@author harsukh singh
 *@function wrapper for display
 *@args void
 *@return void
 ***********/
/*void node::display()
{
    a_song->display();
}
*/


/***********
 *@author harsukh singh
 *@function operator overloading for the display function
 *@args ostream object and const node object
 *@return ostream residual value
 ***********/
ostream & operator<<(ostream &op1, const node &op2)
{
    if(!op2.a_song) 
    {
        op1<<"No song to display."<<endl;
        return op1;
    }
    song* temp = op2.a_song;
    while(temp)
    {
        op1 <<*temp<<'\n';
        temp = temp -> get_next();
    }
    return op1;
}

/***********
 *@author harsukh singh
 *@function display rand function
 *@args head of the list
 *@return song* to add
 ***********/
song* node::display_rand(song * head)
{
    if(!head) return NULL;
    int size = 0;
    song* current = head;
    while(current)
    {
        ++size;
        current = current -> get_next();
    }
    current = head;
    int q = rand() % size;
    for(int i=0; i<q; ++i)
    {
        current = current ->get_next();
    }
    cout<<*current<<endl;
    return current;
}

/***********
 *@author harsukh singh
 *@function function for display 
 *@args void
 *@return void
 ***********/
song* node::display_rand()
{
    return display_rand(a_song);
}



/***********
 *@author harsukh singh
 *@function destructor
 *@args void
 *@return void
 ***********/
node::~node()
{
    if(a_song)
        delete_all(a_song);
    next = NULL;
}

/***********
 *@author harsukh singh
 *@function returns the next pointer
 *@args node*
 *@return void
 ***********/
void node::set_next(node* next_ptr)
{
    next = next_ptr;
}

/***********
 *@author harsukh singh
 *@function compare function for songs
 *@args song
 *@return void
 ***********/
int node::compare(const song &to_compare) const
{
    if((strcmp(a_song->get_artist(),to_compare.get_artist()) == 0) && (strcmp(a_song->get_title(), to_compare.get_title()) == 0))
        return 1;
    else return 0;
}

/***********
 *@author harsukh singh
 *@function compare function for artist
 *@args song
 *@return itn
 ***********/
int node::artist_compare(const song &to_compare) const 
{
    if((strcmp(a_song->get_artist(),to_compare.get_artist()) == 0))
    {
        return 1;
    }
    else return 0;

}

/***********
 *@author harsukh singh
 *@function insert function for the list 
 *@args song to insert
 *@return int success 
 ***********/
int node::insert(const song & to_insert)
{
    if(!a_song)
    {
        a_song = new song(to_insert);//call copy constructor
        return 1;
    }
    else{
        song* temp = a_song;
        a_song = new song(to_insert);
        a_song->set_next(temp);
        return 1;
    }
}

/***********
 *@author harsukh singh
 *@function wrapper for remove function 
 *@args song to remove
 *@return int 1 or 0
 ***********/
int node::remove(char* song_to_remove)
{
    return remove(a_song, song_to_remove);
}

/***********
 *@author harsukh singh
 *@function recursive delete function
 *@args song to remove and character array of the song
 *@return itn
 ***********/
int node::remove(song* &head, char* song_to_remove)
{
    if(!head) return 0;
    if((strcmp(head->get_title(), song_to_remove) == 0))
    {
        song* del_ptr = head;
        head = head->get_next();
        delete del_ptr;
        del_ptr = NULL;
        return 1;
    }
    return remove(head->get_next(), song_to_remove);
}

/***********
 *@author harsukh singh
 *@function delete all function
 *@args the head of the list
 *@return void
 ***********/
void node::delete_all(song* &head)
{
    if(!head) return;
    delete_all(head->get_next());
    delete head;
    head = NULL;
}


