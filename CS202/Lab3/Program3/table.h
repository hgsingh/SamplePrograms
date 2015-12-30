//@author harsukh singh CS202 assignment 3
//5/11/2015

#include <iostream>
#include <fstream>
#include <cstring>
#include <cctype>
#include <cstdlib>

/***********
 *@author harsukh singh
 *@class song class has data of a song, artist genre
 ***********/
class song
{
    protected:
        char* title; //title of song
        char** genre; //song genre
        int length;
        char* artist; //song artist
        song* next; //here? also would need setters and getters
    public:
        song(); //default constructor
        song(int array_length);
        song(const song &song_to_copy); //copy constructor
        virtual ~song(); //destructor
        char* get_title() const; //get title
        char** get_genre() const; //get genre
        char* get_artist() const; //get artist
        //void display();//display function
        friend std::ostream & operator<<(std::ostream & op1, const song &op2); //display  
        void set_artist(char* music_artist); //set artist
        void set_genre(char** music_genre, int genre_length); //set genre
        void set_title(char* music_title); //set title
        song* & get_next(); //next getter
        void set_next(song* next_ptr); //next setter
	int get_length() const;
};

/***********
 *@author harsukh singh
 *@class node class for implementation for a linked structure
 ***********/
class node
{
    public:
        node(); //default constructor for node
        node(const node &obj); //copy constructor
        node(const song & obj); //song object to set
        node* & get_next(); //next pointer retriever
        void set_next(node* next_ptr); //set next 
        int compare(const song &to_compare) const; //compares songs
        int artist_compare(const song &to_compare) const;//compare function for artist
        int insert(const song &to_insert); //insert function
        int remove(char* song_to_remove); //remove function
        //void display(); //display function
        friend std::ostream & operator<<(std::ostream & op1, const node &op2); //display  
        song* & get_song();
        virtual ~node(); //destructor
        song* display_rand();
    private:
        node* next; //next pointer
        int remove(song* &head, char* song_to_remove); //remove function
        int copy_lll(song* &head, song* to_copy);//copy lll function
        song* a_song; //song pointer
        void delete_all(song* &head);
        song* display_rand(song* head);
};

/***********
 *@author harsukh singh
 *@class class represents a CLL queue
 ***********/
class playlist
{
    public:
        playlist(); //default constructor
        virtual ~playlist(); //destructor
        playlist(const playlist &to_copy);//copy constructor
        void copy_cll(node* to_copy);
        playlist & operator=(const playlist &op2); //assignment operator
        playlist & operator+=(const song &op2); //add a song to end of list
        playlist & operator-=(const song &op2); //remove a song from the list
        int remove(node* &temp, const song &to_compare); //remove function
        friend std::ostream & operator<<(std::ostream & op1, const playlist &op2); //display 
    private:
        node* rear; //head of the list
        void copy_cll(node* &rear, node* to_copy, node* rear_check); //copy cll 
        void delete_all(node* &head); //delete all function
};

/*****************
 * @author harsukh singh
 * @class hash table adt that hashes based on artist title
 ******************/
class artist_table
{
    private:
        int size; //size of the table 
	node **table;
        void delete_list(node* head);
        song* display(node* head, const song &to_display);
    public:
        artist_table(const int table_size = 5); //constructor
        virtual ~artist_table(); //default destructor
        artist_table(const artist_table &table_copy); //copy constructor
        int copy_lll(node* &head, node* to_copy);
        int hash_function(char* key); //hasher
        artist_table & operator+=(const song &op2); //add a song to end of list
        artist_table & operator-=(const song  &op2); //remove a song from the end of the list this will remove the entire artist
        int remove(node* &temp, const song &compare);
        artist_table & operator=(const artist_table &op2);
        bool compare(const node &op1, const song &op2) const; //implement check artist here this
        song* display(char* artist);
        void display_all();
};

class genre; //declaration  
/***********
 *@author harsukh singh
 *@class implements the edge of a graph
 ***********/
class edge_genre 
{
    protected:
        edge_genre* next; //next for edge genre
        song* a_song;
        int length;
        genre ** adjacent; //adjacent genre 
    public:
        edge_genre(); //constructor
        edge_genre(const song & obj); //copy constructor
        virtual ~edge_genre(); //destructor
        edge_genre* & get_next();
        void set_next(edge_genre* next_ptr);
        void display();
        song* get_song();
        int set_genre(genre &to_set);
        genre* get_genre();
};



/***********
 *@author harsukh singh
 *@class node class for implementation for a linked structure
 ***********/
class genre 
{
    protected:
        edge_genre* head; //private head for adding the adjacency list
        char* genre_title; //title for the genre
    public:
        virtual ~genre(); //destructor
        genre(); //default constructor
        genre(const genre &to_copy); //copy constructor
        char* get_title() const; //title getter
        void set_title(char* title); //title setter
        edge_genre* & get_head(); //gets the ehad of the list
        void set_head(edge_genre* current); //head setter
        friend std::ostream & operator<<(std::ostream &op1, const genre &op2);
};



/***********
 *@author harsukh singh
 *@class graph implementation of graphs
 ***********/
class graph
{
    public:
        graph(int size); //constructor
        virtual ~graph();
        int insert_vertex(char* to_insert);
        int find_location(const char* key_value);
        int display_adjacent(char* key_value);
        void display_all();
        int check_string(char* guess, char* check);
        int insert_edge(const song &obj);
        song* get_song(char* key_value, int q);
        int get_next(char* key_value, int q);
    private: 
        int list_size; //size of adjacency list
        genre* adjacency_list; //genre adjacency list
        int remove_list(edge_genre* &current); //removes a linear linked list
};

/***********
 *@author harsukh singh
 *@class graph implementation of graphs
 ***********/
class manager
{
    public:
        manager();
        ~manager();
        int load_graph(char* file_name);
        int insert_songs(char* file_name);
        void test();
        void start_program(); 
    private:
        graph* genre_graph;
        playlist liked_songs;
        artist_table artist_map;
};
