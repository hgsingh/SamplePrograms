//@author harsukh singh  cs 202 assignment 3
//@artist table class hashes a playlist based on particular artist

#include "table.h"
using namespace std;


/************************
 * @author harsukh singh CS202 assignment 3
 * @function default constructor
 * @param const table size
 * @return void
 **************************/
artist_table::artist_table(int table_size)
{
    size = table_size;
    table = new node*[size];
    for(int i=0; i<size;++i)
    {
        table[i] = NULL;
    }  
}

/************************
 * @author harsukh singh CS202 assignment 3
 * @function copy constructor
 * @param table to copy
 * @return void
 **************************/
artist_table::artist_table(const artist_table &to_copy)
{
    size = to_copy.size;
    table = new node*[size];
    for(int i=0; i<size;++i)
    {
        copy_lll(table[i], to_copy.table[i]);
    }  
}

/***********
 *@author harsukh singh
 *@function copy linked list function
 *@args node to copy to as head and node to copy
 *@return int 1 or 0
 ***********/
int artist_table::copy_lll(node * &head, node* to_copy)
{
    if(!to_copy)
    {
        head = NULL;
        return 1;
    }
    head = new node(*to_copy);
    return copy_lll(head->get_next(), to_copy->get_next());
}


/*
* hash function that sums all of the characters in a given array and returns an index in the hash table using the mod of the hash table size. 
* @author harsukh singh CS202 assignment 3
* @param character array of artist title
* @return returns an integer value of hash table index corresponding to the hash function
*/
int artist_table::hash_function(char* key)
{
    if(!key) return -1;
    int sum = 0;
    for(int i = 0; i< (unsigned) strlen(key); ++i)
    {
      sum = sum + key[i];
    }
    int index = sum % size;
    return index;
}

/************************
 * @author harsukh singh CS202 
 * @function default destructor
 * @param deletes list
 * @return void
 **************************/
artist_table::~artist_table()
{
    for(int i = 0; i<size; ++i)
    {
        node* temp = table[i];
        if(table[i])
        {
            delete_list(temp);
        }
    }
    delete[] table;
}

/************************
 * @author harsukh singh CS202 assignment 3
 * @function deletes the list given an index
 * @param a index given as head
 * @return void
 **************************/
void artist_table::delete_list(node* head)
{
    if(!head) return;
    delete_list(head->get_next()); //needed in playlist class
    head->set_next(NULL); //needed in playlist class
    delete head;
}

/************************
 * @author harsukh singh CS202 assignment 3
 * @function displays the list of songs of a given artist
 * @param char* artist
 * @return void
 **************************/
song* artist_table::display(char* artist)
{
    if(!artist) return NULL;
    int index = hash_function(artist);
    song a_artist;
    a_artist.set_artist(artist);
    return display(table[index], a_artist);
}

/************************
 * @author harsukh singh CS202 assignment 3
 * @function displays all function
 * @param void
 * @return void
 **************************/
void artist_table::display_all()
{
    for(int i = 0; i<size; ++i)
    {
        if(table[i])
        {
            node* temp = table[i];
            while(temp)
            {
                cout<<*temp<<endl;
                temp = temp->get_next();
            }
        }
    }
}


/************************
 * @author harsukh singh CS202 assignment 3
 * @function displays a random song from a artist
 * @param head of given index and a comparsion
 * @return NULL or the song
 **************************/
song* artist_table::display(node *head, const song &to_display)
{
    if(!head) return NULL;
    if(compare(*head, to_display) == true)
    {
        return head->display_rand(); 
    }
    return display(head->get_next(), to_display);
}

/************************
 * @author harsukh singh CS202 assignment 3
 * @function += operator adds a song to list of a similar artist
 * @param const song to copy
 * @return *this
 **************************/
artist_table & artist_table::operator+=(const song &op2)
{
    if(!op2.get_artist())
    {
        cout<<"No artist to store"<<endl;
        return *this;
    }
    int index = hash_function(op2.get_artist());
    if(table[index] == NULL) //case where the index has no list or chains
    {
        table[index] = new node(op2); //call constructor to make the song
    }
    //compare stuff here
    else
    {
        node* temp = table[index]; //traverse to end and see if artist can be found
        while(temp)//traversing loop
        {
            if(compare(*temp, op2)== true)
            {
                //song* to_insert = new song(op2); //make object to insert
                temp->insert(op2); //call node insert function
                return *this; //break if insert if successful
            }
            temp = temp->get_next(); //traverse
        }
        if(temp == NULL)//list traversed no similar artist found
        {
            temp = table[index]; //hold onto list
            table[index] = new node(op2); //make new list
            table[index]->set_next(temp); //reattach list
            return *this;
        }
    }
}

/************************
 * @author harsukh singh CS202 assignment 3
 * @function comparing the nodes song head list to the const song op1
 * @param const song op2 and const node op1
 * @return true or false
 **************************/
bool artist_table::compare(const node &op1, const song &op2) const
{
    if(op1.artist_compare(op2) == 1)
    {
        return true;
    }
    return false;
}

/************************
 * @author harsukh singh CS202 assignment 3
 * @function remove operation on LLL
 * @param const song op2 and node of the head
 * @return true or false
 **************************/
int artist_table::remove(node* &temp, const song &compare)
{
    if(!temp) return 0;
    if(!compare.get_artist()) return 0;
    if(this->compare(*temp, compare) == true)
    {
        //cout<<temp<<endl;
        node* del_ptr = temp;
        temp = temp->get_next();
        delete del_ptr;
        del_ptr = NULL;
        return 1;
    }

    return remove(temp->get_next(), compare);
}

/***********
 *@author harsukh singh
 *@function remove a artist from the table
 *@args const dong
 *@return artist table *this
 ***********/
artist_table & artist_table::operator-=(const song & op2)
{
    if(!op2.get_artist()) 
    {
        cout<<"Nothing to remove."<<endl;
        return *this;
    }
    int index = hash_function(op2.get_artist());
    node* temp = table[index];
    int check = remove(temp, op2);
    if(check == 1) 
    {
        cout<<"artist  removed"<<endl;
        return *this;
    }
    else{
        cout<<"artist not found"<<endl;
        return *this;
    }

}

/***********
 *@author harsukh singh
 *@function assignment operator
 *@args const artist_table to copy
 *@return artist table *this
 ***********/
artist_table & artist_table::operator=(const artist_table &op2)
{
    if(this == &op2)
    {
        return *this;
    }
    for(int i = 0; i<size; ++i)
    {
        node* temp = table[i];
        if(table[i])
        {
            delete_list(temp);
        }
    }
    delete[] table;
    size = op2.size;
    table = new node*[size];
    for(int i=0; i<size;++i)
    {
        copy_lll(table[i], op2.table[i]);
    }  
    return *this;
}
