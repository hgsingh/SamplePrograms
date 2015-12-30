/**
  CS-163 Assignment 3
  main.cpp
  Purpose: Entry point function program starts execution here. 
  @author harsukh singh
  @version 1.0 2/25/2015
*/

#include "cs163_program3.h"
using namespace std;

/*
* This function begins by initializing a file name of type char* object. This   is the desired file to be read in. The function then declares a class object  of table type to create a hash table. The function then calls a member 
  function of the class to read in the jobs. The function then continues to 
  prompt the client to get a desired job title to hash on and exact the search  to one job using keywords. 
* @author harsukh singh
* @param 
* @return returns a integer value of 0.
*/
int main()
{
  char file_name[] = "jobs.txt"; //file to open
  table hashing_table; 
  cout<<"Loading Jobs."<<endl;
  hashing_table.read_jobs(file_name);
  char option;
  cout<< "If you would like to display all jobs press q, to search for a job press enter"<<endl;
  option = cin.get();
  cin.ignore(100, '\n');
  option = tolower(option);
  if(option == 'q'){
    cout<<"Displaying Jobs."<<endl;
    hashing_table.display_all();
  }
  char* key = new char[100];
  struct keywords* search_words = new keywords[10];
  for(int i = 0; i < 10; ++i)
  {
    search_words[i].keys = new char[30];
  }
  cout<<"Please enter a job title that you would like to find."<<endl;
  cin.get(key, 100, '\n');
  cin.ignore(100, '\n');
  for(int j = 0; j < (unsigned) strlen(key)+1; ++j)
  {
    key[j] = tolower(key[j]);
  }
  cout<< "The job title you entered is "<<key<<endl;
  int size_of_keys = 0;
  bool add_word = true;
  int i = 0;
  while(add_word)
  {
    cout<<"Please enter a keyword related to the job title that is limited to 30 characters."<<endl;
    cin.get(search_words[i].keys, 30, '\n');
    cin.ignore(100, '\n');
    for(int k = 0; k< (unsigned) strlen(key)+1; ++k)
    {
      search_words[i].keys[k] = tolower(search_words[i].keys[k]);
    }
    cout<<"The key word entered is "<<search_words[i].keys<<endl;
    ++size_of_keys;
    ++i;
    cout<<"If you would like to add more words, please press y."<<endl;
    char a = cin.get();
    cin.ignore(100, '\n');
    a = tolower(a);
    if(a !='y') add_word = false;
  }
  int success = hashing_table.retrieve(key, search_words, size_of_keys);
  if(success == 0) cout<< "This job does not exist"<<endl;
  for(int i = 0; i<10; ++i)
  {
    delete[] search_words[i].keys;
  }
  delete[] search_words;
  return 0;
}
