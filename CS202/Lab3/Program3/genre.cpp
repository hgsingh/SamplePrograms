#include "table.h"

using namespace std;

/****************
 *@author harsukh singh
 *@function default constructor
 *@args void
 *@return void
 *****************/
genre::genre():genre_title(0), head(0) { }


/****************
 *@author harsukh singh
 *@function copy constructor
 *@args const genre to copy
 *@return void
 ****************/
genre::genre(const genre &to_copy):head(0) 
{
     if(to_copy.genre_title)
    {
        if(genre_title)
            delete[] genre_title;
        genre_title = new char[strlen(to_copy.genre_title) + 1];
        strcpy(genre_title, to_copy.genre_title);
    }
}

/****************
 *@author harsukh singh
 *@function destructor
 *@args void
 *@return void
 *****************/
genre::~genre()
{
    if(genre_title)
        delete[] genre_title;
}

/***********
 *@author harsukh singh
 *@function returns the genre title of the class 
 *@args void 
 *@return char*
 ***********/
char* genre::get_title() const
{
    return genre_title;
}

/***********
 *@author harsukh singh
 *@function set the genre title
 *@args char* genre to set
 *@return void
 ***********/
void genre::set_title(char* title)
{
    if(title)
    {
        if(genre_title)
            delete[] genre_title;
        genre_title = new char[strlen(title) + 1];
        strcpy(genre_title, title);
    }
}

/***********
 *@author harsukh singh
 *@function operator overloading for the display function
 *@args ostream object and genre node object
 *@return ostream residual value
 ***********/
ostream & operator<<(ostream &op1, const genre &op2)
{
    if(!op2.get_title()) 
    {
        op1<<"Nothing to display."<<endl;
        return op1;
    }
    op1<<op2.get_title()<<'\n';
    return op1;
}

/***********
 *@author harsukh singh
 *@function returns the head pointer for the class
 *@args void
 *@return edge_genre's head pointer for the list
 ***********/
edge_genre* & genre::get_head()
{
    return head;
}

/***********
 *@author harsukh singh
 *@function sets the head of the edge genre
 *@args current edge_genre to set
 *@return void
 ***********/
void genre::set_head(edge_genre* current)
{
    head = current;
}
