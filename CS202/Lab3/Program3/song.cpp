//@author harsukh singh CS202 assignment 3
//5/11/2015
#include "table.h"
using namespace std;

/***********
 *@author harsukh singh
 *@function default constructor
 *@args void 
 *@return void
 ***********/
song::song():title(0), genre(0), artist(0), length(0),next(0){ } //zero equivalent values set


/***********
 *@author harsukh singh
 *@function constructor sets the genre array to null
 *@args void 
 *@return void
 ***********/
song::song(int array_length):title(0), artist(0), next(0)
{
    if(array_length != 0 && array_length > 0)
    {
        length = array_length;
       // cout<<"length of array set in constructor is "
          //  <<length<<endl;
        genre = new char*[length];
        for(int i= 0; i<length;++i)
        {
            genre[i] = NULL;
        }
    }
    else
    {
        cout<<"constructor called with zero length."<<endl;
        cout<<"class members not initialized."<<endl;
    }
}

/***********
 *@author harsukh singh
 *@function copy constructor 
 *@args void 
 *@return void
 ***********/
song::song(const song &song_to_copy):next(0)
{
    if(song_to_copy.title && song_to_copy.artist && song_to_copy.genre)
    {
        title = new char[strlen(song_to_copy.title) + 1];
        artist = new char[strlen(song_to_copy.artist) + 1];
        strcpy(title,song_to_copy.title);
        strcpy(artist, song_to_copy.artist);
        length = song_to_copy.length; 
        genre = new char*[length];
        for(int i =0; i<length; ++i)
        {
            *(genre + i) = new char[strlen(song_to_copy.genre[i]) + 1];
            strcpy(*(genre+i), song_to_copy.genre[i]);
        }
    }
    else{
        cout<<"constructor called with null objext."<<endl;
        cout<<"class members not initialized."<<endl;
    }
}


/***********
 *@author harsukh singh
 *@function destructor 
 *@args void 
 *@return void
 ***********/
song::~song()
{
    if(title)
    {
        delete[] title;
        title = NULL;
    }
    if(artist)
    {
        delete[] artist;
        artist = NULL;
    }
    if(genre != NULL)
    {    
        for(int i = 0; i<length; ++i)
        {
            if(genre[i])
                delete[] genre[i];
        }
    }
    delete[] genre;
    next = NULL;
}

/***********
 *@author harsukh singh
 *@function returns the title of the class 
 *@args void 
 *@return char*
 ***********/
char* song::get_title() const
{
    return title;
}


/***********
 *@author harsukh singh
 *@function returns the array of array of genres 
 *@args void 
 *@return char*
 ***********/
char** song::get_genre() const
{
    return genre;
}


/***********
 *@author harsukh singh
 *@function returns the artist of the class 
 *@args void 
 *@return char*
 ***********/
char* song::get_artist() const
{
    return artist;
}


/***********
 *@author harsukh singh
 *@function set the artist name
 *@args char* music artist
 *@return void
 ***********/
void song::set_artist(char* music_artist)
{
    if(music_artist)
    {
        if(artist)
            delete[] artist;
        artist = new char[strlen(music_artist) + 1];
        strcpy(artist, music_artist);
    }
}

/***********
 *@author harsukh singh
 *@function sets the genre array
 *@args char** music genre
 *@return void
 ***********/
void song::set_genre(char** music_genre, int genre_length)
{
    if(music_genre != NULL)
    {
        if(genre) //delete genre here
        {
             for(int i = 0; i<length; ++i)
             {
                 if(genre[i])
                    delete[] genre[i];
             }
        }
        delete[] genre;
        length = genre_length;
        genre = new char*[length];
        for(int i =0; i<length; ++i)
        {
            *(genre + i) = new char[strlen(music_genre[i]) + 1];
            strcpy(*(genre+i), music_genre[i]);
        }
    }
}


/***********
 *@author harsukh singh
 *@function copy the title of the song
 *@args char* music title
 *@return void
 ***********/
void song::set_title(char* music_title)
{
    if(music_title)
    {
        if(title)
            delete[] title;
        title = new char[strlen(music_title) + 1];
        strcpy(title, music_title);
    }
}

/***********
 *@author harsukh singh
 *@function display function displays things that are private
 *@args void
 *@return void
 ***********/
/*void song::display()
{
    if(title)
        cout<<title<<endl;
    if(artist)
        cout<<artist<<endl;
    for(int i=0; i<length;++i)
    {
        if(genre[i])
            cout<<genre[i]<<endl;
    }
}
*/

/***********
 *@author harsukh singh
 *@function display function using operator overloading
 *@args ostream object for display and a const song object to display
 *@return residual value of the ostream object
 ***********/
ostream & operator<<(ostream &op1, const song &op2)
{
    op1<<op2.title<<'\n';
    op1<<op2.artist<<'\n';
    int len =  op2.length;
    for(int i  =0; i< len; ++i)
    {
        if(op2.genre[i])
        {
            op1<<op2.genre[i]<<'\n';

        }
    }
    return op1;
}

/***********
 *@author harsukh singh
 *@function get next function for the song object
 *@args void
 *@return song*
 ***********/
song*& song::get_next()
{
    return next;
}

/***********
 *@author harsukh singh
 *@function set next function for the song object
 *@args next song object
 *@return void
 ***********/
void song::set_next(song* next_ptr)
{
    next = next_ptr; 
}

/***********
 *@author harsukh singh
 *@function getter function for length
 *@args void
 *@return int
 ***********/
int song::get_length() const
{
    return length;
}

