#include "table.h"

using namespace std;

/***********
 *@author harsukh singh
 *@function constructor copy
 *@args const song obj
 *@return void
 ***********/
edge_genre::edge_genre():a_song(0), next(0), adjacent(0), length(0) { }

/***********
 *@author harsukh singh
 *@function constructor copy
 *@args const song obj
 *@return void
 ***********/
edge_genre::edge_genre(const song &obj):next(0)
{
   a_song = new song(obj);
   adjacent = new genre*[obj.get_length()];
   length = obj.get_length();
   for(int i=0; i< length; ++i)
   {
       adjacent[i] = NULL;
   }
}

/***********
 *@author harsukh singh
 *@function destructor
 *@args void
 *@return void
 ***********/
edge_genre::~edge_genre()
{
    for(int i = 0; i<length; ++i)
    {
        if(adjacent[i])
            adjacent[i] = NULL;
    }
    delete[] adjacent;
    if(a_song)
        delete a_song;
    next = NULL;
}

/***********
 *@author harsukh singh
 *@function get_next()
 *@args void
 *@return edge genre
 ***********/
edge_genre* & edge_genre::get_next()
{
    return next;
}


/***********
 *@author harsukh singh
 *@function set next()
 *@args edge_genre to set
 *@return void
 ***********/
void edge_genre::set_next(edge_genre* next_ptr)
{
    next = next_ptr;
}

/***********
 *@author harsukh singh
 *@function display function
 *@args void
 *@return void
 ***********/
void edge_genre::display()
{
    if(a_song)
        cout<<*a_song<<endl;
}

/***********
 *@author harsukh singh
 *@function set genre function
 *@args genre to set
 *@return 1 for true... -1 for false 
 ***********/
int edge_genre::set_genre(genre &to_set)
{
    for(int i = 0; i<length; ++i)
    {
       if(adjacent[i] == NULL)
       {
           adjacent[i] = &to_set;
           return 1;
       }
    }
    return -1;
}


/***********
 *@author harsukh singh
 *@function getter forgenre function
 *@args void
 *@return pointer to a genre
 ***********/
genre* edge_genre::get_genre()
{
    int genre = rand() % length;
    while(adjacent[genre] == NULL)
    {
        genre = rand() % length;
    }
    return adjacent[genre];
}


/***********
 *@author harsukh singh
 *@function get song function
 *@args void
 *@return reference of the song pointed to by the song pointer
 ***********/
song* edge_genre::get_song()
{
    return a_song;
}
