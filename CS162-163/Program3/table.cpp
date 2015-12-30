/**
  CS-163 Assignment 3
  table.cpp
  Purpose: Creates a hash table data structure, with an associated hash 
  function. This ADT reads from a file and creates a node as they are read.
  The ADT also implements the required function from the assignment.

  @author harsukh singh
  @version 1.0 2/25/2015
*/

#include "cs163_program3.h"
using namespace std;

/*
* Constructor for table class, initializes hash table size integer and sets all pointers in hash table to null.
* @author harsukh singh
* @param integer size of the table
* @return 
*/
table::table(int size)
{
  hash_table_size = size;
  hash_table = new node*[hash_table_size];
  for(int i = 0; i<hash_table_size;++i)
  {
    hash_table[i] = NULL;
  }
}

/*
* hash function that sums all of the characters in a given array and returns an index in the hash table using the mod of the hash table size. 
* @author harsukh singh
* @param character array of job title
* @return returns an integer value of hash table index corresponding to the hash function
*/
int table::hash_function(char* key)
{
    int sum = 0;
    for(int i = 0; i< (unsigned) strlen(key); ++i)
    {
      sum = sum + key[i];
    }
    int index = sum % hash_table_size;
    return index;
}

/*
* Creates a node based on the job object passed in parameter and adds it to the head of the associated index of the hash table. 
* @author harsukh singh
* @param object of job type
* @return returns a integer value of 1.
*/
int table::create_node(jobs &to_load) 
{
  node* new_node = new node;
  new_node->job = new jobs;
  new_node->job->employers_name = new char[200];
  new_node->job->location = new char[200];
  new_node->job->job_title = new char[200];
  new_node->job->job_description = new char[1024];
  new_node->job->experience = new char[1024];
  new_node->job->pay_rate = new char[200];
  strcpy(new_node->job->employers_name, to_load.employers_name);
  strcpy(new_node->job->location, to_load.location);
  strcpy(new_node->job->job_title, to_load.job_title);
  strcpy(new_node->job->job_description, to_load.job_description);
  strcpy(new_node->job->experience, to_load.experience);
  strcpy(new_node->job->pay_rate, to_load.pay_rate);
  int index = hash_function(new_node->job->job_title); 
  if(hash_table[index] == NULL)
  {
    hash_table[index] = new_node;
    new_node -> next = NULL;
    return 1;
  }
  node* temp = hash_table[index];
  hash_table[index] = new_node;
  hash_table[index] -> next = temp;
  return 1;
}

/*
* Retrieves information from hash table, given the array title and keyword objects and the size of the keywords 
* @author harsukh singh
* @param character array of title, keys of keyword type, size of keys integer type
* @return returns a flag of integer type 1 or 0 corresponding to pass or fail.
*/
int table::retrieve(char* key, keywords* keys_to_find, int &size_of_keys) //key val has to be determined from the main function
{
  int flag = 0;
  int index = hash_function(key);
  node* current = hash_table[index]; // have a node pointer to the hash table index
  if(current == NULL) return flag;
  while(current)
  {
    for(int i = 0; i<size_of_keys; ++i)
    {
      int found  = check_phrase(keys_to_find[i].keys,current->job->job_description);
      //cout<<found<<endl;
      int loc = check_phrase(keys_to_find[i].keys,current->job->location);
      //cout<<loc<<endl;
      int name = check_phrase(keys_to_find[i].keys,current->job->employers_name);
      //cout<<name<<endl;
      if(found == 1 || loc == 1 || name == 1){
        display(current); // call display function here 
        flag = 1;
      }
    }
    current = current -> next;
  }
  return flag; 
}

/*
* Composite function, reads jobs from a file, passes job into the create node function.
* @author harsukh singh
* @param  character array of file name
* @return returns a integer value of 0 or 1.
*/
int table::read_jobs(char* file_name)
{
  ifstream reader;
  reader.open(file_name);
  if(!reader){
    cout<<"Unable to load file."<<endl;
    return 0;
  }
  while(reader && !reader.eof())
  {
    jobs job;
    job.employers_name = new char[200];
    job.location = new char[200];
    job.job_title = new char[200];
    job.job_description = new char[1024];
    job.experience = new char[1024];
    job.pay_rate = new char[200];
    while(reader.peek() != '\n' && !reader.eof()){ 
      reader.get(job.employers_name,200,':');
      reader.ignore(100, ':');
      reader.get(job.location,200,':');
      reader.ignore(100, ':');
      reader.get(job.job_title,200,':');
      reader.ignore(100, ':');
      reader.get(job.job_description, 1024,':');
      reader.ignore(100, ':');
      reader.get(job.experience, 1024,':');
      reader.ignore(100, ':');
      reader.get(job.pay_rate, 200,':');
      reader.ignore(100, ':');
    }
    reader.ignore();
    if(!reader.eof())
      create_node(job);
    delete[] job.employers_name;
    delete[] job.location;
    delete[] job.job_title;
    delete[] job.job_description;
    delete[] job.experience;
    delete[] job.pay_rate;
  }
  reader.clear();
  reader.close();
  return 1;
}

/*
* Reads a job to output buffer based on the current pointer.
* @author harsukh singh
* @param pointer to node object
* @return returns a integer value of 0 or 1.
*/
int table::display(node* current)
{
  if(!current) return 0;
  cout<< current -> job -> employers_name <<endl;
  cout<< current -> job -> location <<endl;
  cout<< current -> job -> job_title <<endl;
  cout<< current -> job -> job_description <<endl;
  cout<< current -> job -> experience <<endl;
  cout<< current -> job -> pay_rate <<endl;
  return 1;
}

/*
* Displays all jobs in a given hash table.
* @author harsukh singh
* @param 
* @return returns a integer value of 0 or 1.
*/
int table::display_all()
{
 int count = 0;
 for(int i = 0; i< hash_table_size;++i)
 {
   if(hash_table[i] == NULL)
   {
      ++count;
      if(count == hash_table_size-1) return 0;
   }
   else{
    node* current = hash_table[i];
    while(current)
    {
      cout<< current -> job -> employers_name <<endl;
      cout<< current -> job -> location <<endl;
      cout<< current -> job -> job_title <<endl;
      cout<< current -> job -> job_description <<endl;
      cout<< current -> job -> experience <<endl;
      cout<< current -> job -> pay_rate <<endl;
      current = current ->next;
    }
   }
 }
 return 1;
}

// int table::displayLLL(node * head){
//     if(!head) return 0;
//     else{
//       cout << "start to do job" << endl;
//       cout<< head -> job -> employers_name <<endl;
//       cout<< head -> job -> location <<endl;
//       cout<< head -> job -> job_title <<endl;
//       cout<< head -> job -> job_description <<endl;
//       cout<< head -> job -> experience <<endl;
//       cout<< head -> job -> pay_rate <<endl;
//     }
//     return 1 + displayLLL(head->next);
// }

/*@author Harsukh Singh
 * This function checks the phrase for the key word 
 * @param char* guess, char* phrase
 * @return 1 or 0 
 */
int table::check_phrase(char* key_word, char* phrase)
{
  char* comp1;
  char* comp2;
  int success = 0;
  for(unsigned int i = 0; i<(unsigned) strlen(key_word)+ 1; ++i)
  {
    key_word[i] = tolower(key_word[i]);
  }
  for(unsigned int j = 0; j<(unsigned) strlen(phrase)+ 1; ++j){
    phrase[j] = tolower(phrase[j]);
  }
  for(unsigned int k = 0; k<(unsigned)strlen(phrase)+ 1; ++k)
  {
    if(phrase[k] == key_word[0])
    { 
      int count = 0;
      comp1 = &phrase[k];
      comp2 = &key_word[0];
      while(*comp1 == *comp2)
      {
        comp1 = comp1 +1;
        comp2 = comp2 +1;
        count = count + 1;
        if(count == ( unsigned) strlen(key_word)){
          success = 1;
          return success;
        } 
      }
    }
  }
  return success;
}
/*
* Destructor for hash_table and associated nodes. 
* @author harsukh singh
* @param 
* @return 
*/
table::~table()
{
  for(int i = 0; i< hash_table_size; ++i)
  {
    node* temp = hash_table[i];
    if(hash_table[i])
    {
      while(temp->next)
      {
        delete[] temp->job-> employers_name;
        delete[] temp->job-> location;
        delete[] temp->job-> job_title;
        delete[] temp->job-> job_description;
        delete[] temp->job-> experience;
        delete[] temp->job-> pay_rate;
        delete temp->job;
        delete temp;
        temp = temp->next;
      }
      delete[] temp->job-> employers_name;
      delete[] temp->job-> location;
      delete[] temp->job-> job_title;
      delete[] temp->job-> job_description;
      delete[] temp->job-> experience;
      delete[] temp->job-> pay_rate;
      delete temp->job;
      delete temp;
    }
    hash_table[i] = NULL;
  }
  delete[] hash_table;
}
