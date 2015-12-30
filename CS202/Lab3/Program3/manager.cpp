//@author harsukh singh
//program 3 5/22/2015

#include "table.h"

using namespace std;

/********
 *@author harsukh singh
 *@function default constructor
 *@args void
 *@return void
 * ******/
manager::manager() 
{ 
    genre_graph = new graph(5); //hard coded graph size
}

/********
 *@author harsukh singh
 *@function destructor
 *@args void
 *@return void
 * ******/
manager::~manager()
{ 
    delete genre_graph;
}

/********
 *@author harsukh singh
 *@function graph vertex loader
 *@args char* file name
 *@return 1 or 0 depending on success
 * ******/
int manager::load_graph(char* file_name) //takes genre filename
{
    ifstream reader;
    reader.open(file_name);
    if(!reader){
        cout<<"Unable to load file."<<endl;
        return 0;
    }
    while(reader && !reader.eof())
    {
        char genre_read[50];
        while(reader.peek() != '\n' && !reader.eof())
        {
            reader.get(genre_read, 50, '|');
            reader.ignore(100, '|');
            genre_graph->insert_vertex(genre_read);
        }      
        reader.ignore();
        reader.peek();
    }
    reader.clear();
    reader.close();
    return 1; 
}

/********
 *@author harsukh singh
 *@function insert songs function based on filename into the graph and the hash table
 *@args char* file name
 *@return 1 or 0 depending on success
 * ******/
int manager::insert_songs(char* file_name)
{
    char* genre[20];
    for(int i= 0; i<20; ++i)
    {
        genre[i] = new char[50];
    }
    ifstream reader;
    reader.open(file_name);
    if(!reader){
        cout<<"Unable to load file."<<endl;
        return 0;
    }
    while(reader && !reader.eof())
    {
        char artist[100];
        char song_name[100];
        int size = 0;
        while(reader.peek() != '\n' && !reader.eof())
        {
            reader.get(artist, 100, ':');
            reader.ignore(100, ':');
            reader.get(song_name, 100, ':');
            reader.ignore(100, ':');
            while(reader.peek() != '\n')
            {
                reader.get(genre[size], 50, ':');
                reader.ignore(100, ':');
                ++size;
            }
        }
        reader.ignore();
        song song_to_load(size);
        song_to_load.set_title(song_name);
        song_to_load.set_artist(artist);
        song_to_load.set_genre(genre, size);
        //cout<<song_to_load<<endl;
        artist_map+=song_to_load;
        genre_graph->insert_edge(song_to_load);
	reader.peek();
    }
    for(int i=0; i<20; ++i)
    {
	if(genre[i])
        {
	    delete[] genre[i];
        }
    }
    reader.clear();
    reader.close();
    return 1; 
}

//test function please do not use
//@author harsukh singh
void manager::test()
{
    playlist new_playlist;
    song a_song(4);
    song cool_song(2);
    song this_song(2);
    char* gen[2];
    char* ge[2];
    char* genre[4];
    genre[0] = "does\0";
    genre[1] = "this\0";
    genre[2] = "work\0";
    genre[3] = "yet\0";
    ge[0] = "rock\0";
    ge[1] = "pop\0";
    gen[0] = "electronica\0";
    gen[1] = "chillout\0";
    this_song.set_genre(gen,2);
    this_song.set_title("talismanic\0");
    this_song.set_artist("atb\0");
    cool_song.set_artist("jb\0");
    cool_song.set_title("wtf\0");
    cool_song.set_genre(ge,2);
    a_song.set_genre(genre,4 );
    a_song.set_title("please let this work\0");
    a_song.set_artist("nick\0");
    new_playlist+=a_song; //add check
    new_playlist+=cool_song; //add check
    new_playlist+=this_song; //add check
    cout<<"displayling original list"<<endl;
    cout<<new_playlist<<endl;
    playlist a_playlist = new_playlist; //assignment operator check
    cout<<"displaying copied list"<<endl;
    cout<<a_playlist<<endl;
    cout<<"test remove function"<<endl;
    new_playlist-=a_song; //remove check
    cout<<"displaying updated list"<<endl;
    cout<<new_playlist<<endl;
    genre_graph->display_all(); 
    artist_map.display_all();
}

/********
 *@author harsukh singh
 *@function start program function
 *@args void
 *@return void
 * ******/
void manager::start_program()
{
    char choice;
    cout<<"Please enter 'g' to search by genre."<<endl;
    cout<<"Please enter 'a' to search by artist."<<endl;
    cout<<"Press anything else to exit."<<endl;
    cin.get(choice);
    cin.ignore(100, '\n');
    if(choice == 'g')
    {
        cout<<"Please enter the genres you would like to search for."<<endl;
        cout<<"Choices include pop, rock, hip hop and rap."<<endl;
        char genre_pick[30];
        cin.get(genre_pick, 30, '\n');
        cin.ignore(100, '\n');
        cout<<"Now playing..."<<endl;
        int to_find = genre_graph->display_adjacent(genre_pick);
        char like;
        cout<<"Do you like this song? Please press 'y' or 'n'."<<endl;
        cin.get(like);
        cin.ignore(100, '\n');
        if(like == 'y')
        {
            song* to_set = genre_graph->get_song(genre_pick, to_find);
            liked_songs+=*to_set;
            cout<<"Current playlist is..."<<endl;
            cout<<liked_songs<<endl;
        }
        else{
            this->start_program();
        }
        while(like == 'y')
        {
            cout<<"Playing next song"<<endl;
            to_find = genre_graph->get_next(genre_pick, to_find);
            cout<<"Do you like this song? Please press 'y' or 'n'."<<endl;
            cin.get(like);
            cin.ignore(100, '\n');
            if(like == 'y')
            {
                song* to_set = genre_graph->get_song(genre_pick, to_find);
                liked_songs+=*to_set;
                cout<<"Current playlist is..."<<endl;
                cout<<liked_songs<<endl;
            }
        }
    }
    if(choice == 'a')
    {
        cout<<"Please enter the artist you would like to play."<<endl;
        char artist_pick[50];
        cin.get(artist_pick, 50, '\n');
        cin.ignore(100, '\n');
        cout<<"Now playing..."<<endl;
        song* to_add = artist_map.display(artist_pick);
        liked_songs += *to_add;
        char** to_get = to_add->get_genre();
        cout<<"Switching songs..."<<endl;
        int to_find = genre_graph->display_adjacent(to_get[0]);
        char like;
        cout<<"Do you like this song? Please press 'y' or 'n'."<<endl;
        cin.get(like);
        cin.ignore(100, '\n');
        if(like == 'y')
        {
            song* to_set = genre_graph->get_song(to_get[0], to_find);
            liked_songs+=*to_set;
            cout<<"Current playlist is..."<<endl;
            cout<<liked_songs<<endl;
        }
        else{
            this->start_program();
        }
        while(like == 'y')
        {
            cout<<"Playing next song"<<endl;
            to_find = genre_graph->get_next(to_get[0], to_find);
            cout<<"Do you like this song? Please press 'y' or 'n'."<<endl;
            cin.get(like);
            cin.ignore(100, '\n');
            if(like == 'y')
            {
                song* to_set = genre_graph->get_song(to_get[0], to_find);
                liked_songs+=*to_set;
                cout<<"Current playlist is..."<<endl;
                cout<<liked_songs<<endl;
            }
        }
    }
    else{
        cout<<"exiting."<<endl;
    }
}
