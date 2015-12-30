/**
  CS-163 Assignment 3
  cs163_program.h
  Purpose: Specification file to implement the client and ADT program.
  @author harsukh singh
  @version 1.0 2/25/2015
*/

#include <fstream> //file read and write
#include <iostream> //IO buffer
#include <cctype>   
#include <cstring>  //string operations

/*
  Jobs struct object, contains character array member objects.
  @author harsukh singh
*/
struct jobs
{
  char* employers_name;
  char* location;
  char* job_title;
  char* job_description;
  char* experience;
  char* pay_rate;
};

/*
  Keyword struct object, contains key of character array type.
  @author harsukh singh
*/
struct keywords
{
  char* keys;
};

/*
  Node object used for singly linked structure.
  @author harsukh singh
*/
struct node
{
  jobs* job;
  node* next;
};

/*
  Table class for table ADT and associated functions.
  @author harsukh singh
*/
class table
{
  public:
    table(int size = 7);
    ~table();
    int load_table(jobs &to_load); //successfully returns 1 or 0 and loads a given job object into table
    int hash_function(char* key);
    int display_all();
    //int displayLLL(node * head);
    int display(node* current);
    int check_phrase(char* key_word, char* phrase);
    int retrieve(char* key, keywords* keys_to_find, int &size_of_keys);
    int create_node(jobs &to_load);
    int read_jobs(char* file_name); //reads in jobs and calls to load job objects into table
    int retrieve(char* key, jobs &found); //retrieves jobs based on title given
  private:
    node** hash_table;
    int hash_table_size; 
};
