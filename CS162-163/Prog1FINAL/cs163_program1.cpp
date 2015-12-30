#include <iostream>
#include <cstring>
#include <fstream>
#include <algorithm>
#include <cctype>
#include "cs163_program1.h"
using namespace std;

/*Author:: Harsukh Singh
 * Description:: constructor for the linear linked list of dynamic hero arrays and power struct this class reads in and 
 * makes a user database 
 * Arguments:: None
 */
Hero_Match::Hero_Match()
{
    head = NULL;
    current = NULL;
    temp = NULL;
}
/*Author:: Harsukh Singh
 * Description:: load heros in
 * Arguments:: None
 */
int Hero_Match::load_heros(char power_file_name[], char hero_file_name[])
{
  ifstream power; //create input file object
  ifstream heros; //output file stream object
  power.open(power_file_name, ios::in);
  heros.open(hero_file_name, ios::in); //empty file that will need to added into from this function
  int length; //number of characters in file
  if(!heros){
    cout<< "Unable to load file"<<endl;
  }
  if(!power){
    cout<< "Unable to load file"<<endl;
  }  
  else
  {// This conditional statement is used to also check if the get function will be successful when used
    power.seekg(0, power.end); //goes to end
    length = power.tellg(); // gets size 
    power.seekg(0, power.beg); //goes back to beginning
    power.clear(); // reset error flags
  }
  length = int(length/6); // everything up to here works
  int count = 1;
  node_type* node;
  while(power && !power.eof())
  {
    if(count == 1)
    {
      node = new node_type;
      node->next = NULL;
    }
    if(power.peek() == '\n' && !power.eof())
    {
      node = new node_type; //create new object at every new line
      node->next = NULL;
      power.ignore(1, '\n');
    }
    while(power.peek() != '\n' && !power.eof()) //to not get stuck in an inifinite loop if files are not read correctly...defensive programming 101
    {
	node -> power_type = new Power; //instantiate new Power object struct
        node -> power_type -> power = new char[length]; //dynamically allocate arrays in power_type object, see .h file
	node -> power_type -> situation = new char[length]; // allocate every array except for heros which will only need 
	power.get(node -> power_type -> power,length,':');
	power.ignore(100,':');
	power.get(node -> power_type -> situation, length, ':');
	power.ignore(100,':');
	power>> node -> power_type -> number;
	power.ignore(100,':');
	int number = node -> power_type -> number;
	node -> heroes = new Hero[number]; //instantiate new Hero object struct
	for(int i = 0; i< number && power.peek() != '\n'; ++i) // now for loop the number of characters into the hero file
	{
	  node -> power_type -> hero = new char[length];
	  node -> heroes[i].name = new char[length]; //
	  node -> heroes[i].description = new char[length*6]; //
	  power.get(node -> power_type -> hero,length,':'); // get hero name from power file and store it in the hero object name array
	  power.ignore(100,':');
	  heros.seekg(0, heros.beg); //goes back to beginning
	  while(heros && !heros.eof() /*&& success == 0*/)// now search the file line by line to get the hero description
	  {
	    heros.get(node -> heroes[i].name, length, ':'); //
	    heros.ignore(100,':');
	    //cout<<"Heros name: "<< node -> heroes[i].name<<endl;
	    //cout<< "Comparison: "<<node -> power_type -> hero<<endl;
	    if(heros.peek() == '\n')
	    {
	      heros.ignore();
	      //cout<<"Peek character: "<<power.peek()<<endl;
	    }
	    if(strcmp(node -> heroes[i].name, node -> power_type -> hero) == 0) { //
	      heros.get(node -> heroes[i].description, length*6, ':'); //
	      heros.ignore(100,':');
	      if(heros.peek() == '\n')
	      {
		  heros.ignore();
	      }
	      break;
	    }
	    if(strcmp(node -> heroes[i].name, node -> power_type -> hero) != 0){
	      for(int k = 0; k< length; ++k) // clear array
		{
		  node -> heroes[i].name[k] = -1; //
		}
	    }
	    heros.peek();
	  }
	}
	count = count +1;
	power.peek();
	
    }
    if(head != NULL)
    {
      current = head;
      while(current->next != NULL)
      {
	current = current -> next; // traversing to next NULL pointer
      }
      current-> next = node;
    }
    else{
      head = node;  
    }
      // counting the number of node objects added
      power.peek();
  }
 power.close();
 heros.close();
 cout<<"Number of nodes added:  " << count<<endl;
 return count;
}
/*Author:: Harsukh Singh
 * Description:: user prompt
 * Arguments:: None
 */
 int Hero_Match::prompt()
{
  int choice;
  cout<<"Welcome to the hero database!"<<endl;
  cout<<"Please press 1 to view all heros and powers."<<endl;
  cout<<"Please press 2 to display heros of a desired power."<<endl;
  cout<<"Please press 3 to display power for a particular situation."<<endl;
  cout<<"Please press 4 to remove a desired power."<<endl;
  cout<<"Please press 5 to add a new hero." <<endl;
  cin>>choice;
  cin.ignore(100, '\n');
  if(choice>0 && choice<6)
  {
   return choice; 
   cin.clear();
  }
  else{
   return Hero_Match::prompt(); 
   cin.clear();
  }
}
/*Author:: Harsukh Singh
 * Description:: Display all
 * Arguments:: None
 */
int Hero_Match::display()
{
  current = head;
  if(head == NULL)
  {
   cout<<"No list to display"<<endl;
   return 0;
  }
  else{
    while(current != NULL && current-> next != NULL  )
    {
      cout<<"Power: "<< current -> power_type-> power  <<endl;
      cout<< "Situation: "<<current -> power_type-> situation  <<endl;
      cout<< "Number: " << current -> power_type-> number<< endl;
      int number = current -> power_type-> number;
      for(int i = 0; i< number; ++i)
      {
	cout<< "Heroes with this Power: " <<'\n';
	cout<< current->heroes[i].name << '\n'; //
	cout<< "Description: " <<'\n';
	cout<< current-> heroes[i].description<<endl; //
      }
      current = current -> next; 
     }   
     return 1;
    }
    
}
/*Author:: Harsukh Singh
 * Description:: displays power based on super power
 * Arguments:: character array of super power
 */
int Hero_Match::display(char super_power[])
{
 current = head;
 int success = 0;
 if(head == NULL)
 {
   cout<< "Error Power and Heoroes files cannot be found!" <<endl; 
   return success;
 }
 else{
  while(current != NULL && current->next != NULL && success == 0)
  {
    if(strncmp(super_power, current->power_type->power, 6)== 0){
      cout<<"Power: "<< current -> power_type-> power  <<endl;
      cout<< "Situation: "<<current -> power_type-> situation  <<endl;
      cout<< "Number: " << current -> power_type-> number<< endl;
      int number = current -> power_type-> number;
      for(int i = 0; i< number; ++i)
      {
	cout<< "Heroes with this Power: " <<'\n';
	cout<< current->heroes[i].name << '\n'; //
	cout<< "Description: " <<'\n';
	cout<< current-> heroes[i].description<<endl; //
      }
      success = 1;      
    }
    else{
      current = current -> next;
    }
  }
    return success; // if success is 0 prompt something in main
 }  
}
/*Author:: Harsukh Singh
 * Description:: removes power based on arguments
 * Arguments::  character array of a super power
 */
int Hero_Match::remove_power(char super_power[])
{
 node_type* delete_pointer = NULL;
 temp = head;
 current = head;
 int success = 0;
 while(current != NULL && current->next != NULL && strcmp(super_power, current->power_type->power)!= 0)
 {
  temp = current; 
  current = current -> next;
 }
 if(head == NULL)
 {
   cout<< "No powers to remove." <<endl; 
   delete delete_pointer;
   return success;
 }
 else{
      delete_pointer = current;
      current = current->next;
      temp->next =current;
      int number = delete_pointer -> power_type-> number;
      for(int i = 0; i< number; ++i)
      {
	delete[] delete_pointer->heroes[i].name; 
	delete[] delete_pointer-> heroes[i].description;
      }
      delete[] delete_pointer->heroes;
      delete[] delete_pointer->power_type->power;
      delete[] delete_pointer->power_type->situation;
      delete[] delete_pointer->power_type-> hero;
      delete   delete_pointer->power_type;
      delete delete_pointer;
      success = 1;      
    }
    return success; // if success is 0 prompt something in main
}
/*Author:: Harsukh Singh
 * Description:: adds hero based on users entry
 * Arguments:: None
 */

int Hero_Match::add_hero()
{
  char* temp_name = new char[33];
  cout<<"Please enter the hero's name limited to 33 characters"<<endl;
  cin.get(temp_name,33,'\n');
  cin.ignore(100, '\n');
  current = head;
  int success = 1;
  int break_point = 1;
  if(head == NULL)
  {
   cout<<"Input files need to be checked."<<endl;
   success = 0; 
   return success;
  }
  while(break_point == 1){
    cout<< "What kind of powers does "<< temp_name<< " have"<<endl; //prompt user to check what kinds of power this hero has
    char* temp_power = new char[33];
    cin.get(temp_power,33,'\n');
    cin.ignore(100, '\n');
    while(current != NULL ) // loop through and create a check to see if heroes have already been listed
    {
      if(strcmp(temp_power, current -> power_type -> power) != 0 && current != NULL)
      {
	current = current -> next;
	success = 0;
      }
      else{
	  current -> power_type -> number = current -> power_type -> number + 1;// increment number
	  int number = current -> power_type -> number; 
	  node_type* node = new node_type;
	  node-> heroes = new Hero[current -> power_type -> number];  
	  memcpy(node-> heroes, current->heroes,sizeof(current->heroes));
	  delete[] current->heroes;
	  current->heroes = node-> heroes;
	  node->heroes = NULL;
	  current -> heroes[number].name = new char[33];
	  current -> heroes[number].description = new char[33];
	  strcpy(current->heroes[number].name, temp_name);
	  strcpy(current-> power_type -> hero, temp_power );
	  char  description[] ="New hero added";
	  strcpy(current -> heroes[number].description, description);
	  success = 1;
	  cout<<"Power added successfully"<<endl; //add description //also add hero name for power struct
      }
    }
    if(success == 0 && current == NULL)
    {
      cout<< "Adding new power."<<endl;
      node_type* new_node = new node_type;
      new_node -> next = NULL;
      current -> next = new_node;
      new_node -> power_type = new Power;
      new_node -> power_type -> power = new char[33];
      new_node -> power_type -> hero = new char[33];
      new_node -> power_type -> situation = new char[33*2];
      char  situation[] ="User defined situation";
      strcpy(current -> power_type->situation, situation);
      strcpy(new_node -> power_type -> power, temp_power );
      strcpy(new_node -> power_type -> hero, temp_name);
      new_node -> power_type -> number = 1;
      new_node -> heroes = new Hero[new_node -> power_type -> number];
      new_node -> heroes[0].name = new char[33];
      new_node -> heroes[0].description = new char[33];
      strcpy(new_node->heroes[0].name, temp_name);
      char  description[] ="New hero added";
      strcpy(new_node -> heroes[0].description, description);
    }
    cout<< "Does this hero have more powers?"<< " Please press y for yes or n for no."<<endl;
    char answer;
    cin.get(answer);
    cin.ignore(100, '\n');
    tolower(answer);
    cout<<"Your choice was  "<< answer<<endl;
    if(answer == 'n')
    {
      delete[] temp_power;
      break_point = 0;
    }
    delete[] temp_power;
  }
  
    delete[] temp_name;
    return success;
}
/*Author:: Harsukh Singh
 * Description:: Finds a power based on situation
 * Arguments:: a situation
 */
char* Hero_Match::find(char situation[])
{
 current = head;
 while(current != NULL)
 {
   if(strncmp(current->power_type->situation, situation,  6)!= 0)
   {
     break;
   }
  current = current -> next;
 }
 if(head == NULL || current==NULL)
 {
   cout<< "No powers to find." <<endl; 
   return NULL;
 }
  return current->power_type->power; 
}

/*Author:: Harsukh Singh
 * Description:: Destructor
 * Arguments:: None
 */
Hero_Match::~Hero_Match()
{
  current = head;
  if(head == NULL)return;
  while(current != NULL && current->next != NULL)
  {
   head = current->next;
   // delete more stuff here
   int number = current -> power_type-> number;
   if(current->power_type == NULL && current->heroes == NULL)
   {
    delete current;
    head = current; 
    head = current->next;
   }
     
   for(int i = 0; i< number ; ++i)
   {
      delete[] current->heroes[i].name; 
      delete[] current-> heroes[i].description;
   }
   delete[] current->heroes;
   delete[] current->power_type->power;
   if(current->power_type->situation != NULL)
   {
    delete[] current->power_type->situation;
   }
   delete[] current->power_type-> hero;
   delete   current->power_type;
   delete current;
   current = head;
  }
  head = NULL;
  //delete head;
  //delete current;
  //delete temp;
}