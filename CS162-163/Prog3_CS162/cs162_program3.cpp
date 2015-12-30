/*
@author harsukh singh
600 word algorithm starts here...

This program is used for building resumes. It uses three structs, a struct for name, a struct for university and a struct for employment information. Libraries used in this program include the iostream library, the file IO library fstream and the c-string library and cctype for string comparison. The functions consist of a two write mutator functions and two get functions. The get functions get the persons name, education history and employment record, each passes the struct object as a reference into the function local parameters. The write functions take a character array of the file to write to and the struct objects to write. The write name and education function is condensed into one function based on assumption that most people only have one name and education, (college education). The employment write function writes, employment information and keeps writing until the user enters in something different.
Algorithm for main:
  1) Create a character array to write to.
  2) Create a name and struct objects locally in main.
  3) Call get functions for objects to write to.
  4) Write to file.
  5) Set a response variable to true.
  6) Ask if user would like to enter employment information.
  7) If true,
    a) Make a local employment struct object and get necessary information for the struct object.
    b) Write to the file.
    c) Ask for user to continue or exit.
      i) If continue step through another a-c above.
  8) Read and display. 
  9) Exit.
Algorithm for get functions:
  1) Pass object locally by reference.
  2) Ask user for required information.
  3) Store the information from input stream into array.
  4) Clear the buffer using ignore until the new line character is reached or 100 characters have been extracted.
  5) Repeat 2-5 until the done.
Algorithm for write function:
  1) Create a local ostream object.
  2) Open file in append mode.
  3) If file cannot be opened return false.
  4) Write to file information using the insertion operator and call struct members using the member access operator.
  5) If this is called after writing the employment information, write delimiter after.
Algorithm for read and display function:
  1) Declare reader ifstream object in input mode.
  2) Open file.
  3) Declare count variable.
  4) Declare length array to store character count.
  5) Declare a character array.
  6) Declare a dummy variable for the length array.
  7) If a file does not exist return a false boolean.
  8) If a file exists read until the delimiter is found and keep count of the characters until the delimiter is reached.
    i) Add the count to the length array, increment count.
    i) Ignore the new line character.
    ii) Check if the next character is EOF.
        a) If the count is 1 then go the beginning and display file.
        b) Otherwise check the last count in the length array and go back using seekg then display file.
    iii) If not EOF, zero dummy variable and increment it again.
  9) Return true.

*/
//@author harsukh singh
#include <iostream>
#include <fstream>
#include <cstring>
#include <cctype>
using namespace std;
struct name
{
  char first_name[30];
  char last_name[30];
};
struct university
{
  char college[127];
  char major[30];
  double gpa;
};
struct employment
{
 char start_date[20];
 char end_date[20];
 char company[127];
 char description[1024];
};
int write_resume(char to_write[], employment &employer); //writes things file named to_write
int write_name_education(char to_write[], name &new_name, university &new_university); //writes name to file
void get_name(name &new_name); //gets persons name, takes a name object as parameter
void get_education(university &new_university); //gets person education, takes university object as parameter
void get_employment(employment &new_employer); //gets persons occupational experience
int read_and_display(char to_write[]);
int write_delimiter(char to_write[]);

/*
@author harsukh singh
@function main
@param void
@returns 0
*/

int main()
{
  char to_write[] = "resume.txt";
  name new_name;
  university new_university;
  get_name(new_name);
  get_education(new_university);
  write_name_education(to_write, new_name,new_university );
  bool response = true;
  char experience;
  cout<<"If you would like to add work experience to the resume press y"<<endl;
  cin.get(experience);
  cin.ignore(100, '\n');
  cout<<endl;
  experience = tolower(experience);
  if(experience != 'y') write_delimiter(to_write);
  while(response == true && experience == 'y'){
    employment employer;
    get_employment(employer);
    write_resume(to_write, employer);
    cout<<'\n'<<endl;
    cout <<"Would you like to add  more work experience into resume? "<<endl;
    char answer;
    cin.get(answer);
    cin.ignore(100,'\n');
    cin.clear();
    if (toupper(answer) == 'Y')
    {
      response = true;
    }
    else response = false;
  }
  if(experience == 'y'){
  write_delimiter(to_write);
  cout<<endl;
  }
  read_and_display(to_write);
  return 0; 
}

/*
@author harsukh singh
@function reads and displays file for most current resume
@param title of file to read stored as a character array
@returns 1 or 0.
*/

int read_and_display(char to_write[])
{
  int count = 0;
  int* length = new int[50]; 
  char* to_read = new char[3000];
  int i = 0;
  ifstream reader;
  reader.open(to_write, ios::in);
 /* reader.seekg(0, reader.end);
  int total_length = reader.tellg();
  reader.seekg(0, reader.beg);*/
  if(!reader) return 0;
  while(reader && !reader.eof()) //to display the most current version go to the next
  {
    *(to_read +i)  = reader.get();
    if(*(to_read+i)  == ':')
    {
      length[count] = i;
      reader.ignore();
      ++count;
      if(reader.peek() == EOF && count == 1)
      {
        cout<<"Only one resume version written."<<endl;
        reader.clear();
        reader.seekg(0, reader.beg);  // go back to beginning
        char read_line[i];
        int j = 0;
        while(!reader.eof() && reader.peek() != ':')
        {
          read_line[j] = reader.get();
          cout<<read_line[j];
          ++j;
        }
        break;
      }
      if(reader.peek() == EOF && count != 1)
      {
        cout<< "Current resume verion "<< count<<endl;
        reader.clear();
        reader.seekg(-(length[count - 1]+1), reader.end); // go back to the last  encounter of the ':' char
        char read_line[length[count-1]];
        //cout<<length[count-1]<<endl;
        int j = 0;
        while(!reader.eof() && reader.peek() != ':')
        {
          read_line[j] = reader.get();
          cout<<read_line[j];
          ++j;
        }
        break;
      }
      else i = 0;
    }
    ++i; 
    reader.clear(); 
  }
  delete[] length;
  reader.close();
  reader.clear();
  return 1;
}

/*
@author harsukh singh
@function gets information from user
@param struct object
@return void
*/

void get_name(name &new_name)
{
    cout<<"Please enter your first name."<<endl;
    cin.get(new_name.first_name, 30, '\n');
    cin.ignore(100, '\n');
    cout<<"Please enter your last name."<<endl;
    cin.get(new_name.last_name, 30, '\n');
    cin.ignore(100, '\n');
    new_name.first_name[0] = toupper(new_name.first_name[0]);
    new_name.last_name[0] = toupper(new_name.last_name[0]);
}

/*
@author harsukh singh
@function gets information from user
@param struct object
@return void
*/

void get_education(university &new_university)
{
    cout<<"Please enter your University's name."<<endl;
    cin.get(new_university.college, 127, '\n');
    cin.ignore(100, '\n');
    cout<<"Please enter your major."<<endl;
    cin.get(new_university.major, 30, '\n');
    cin.ignore(100, '\n');
    cout<<"Please enter your gpa."<<endl;
    cin>>new_university.gpa;
    cin.ignore(100, '\n');
    cin.clear();
}

/*
@author harsukh singh
@function gets information from user
@param struct object
@return void
*/

void get_employment(employment &employer)
{
    cout<<"Please enter your company name."<<endl;
    cin.get(employer.company, 127, '\n');
    cin.ignore(100, '\n');
    cout<<"Please enter your start date in the MM/DD/YYY fashion."<<endl;
    cin.get(employer.start_date, 20, '\n');
    cin.ignore(100, '\n');
    cout<<"Please enter your end date in the MM/DD/YYY fashion or enter \" current \" for currently employed."<<endl;
    cin.get(employer.end_date, 20, '\n');
    cin.ignore(100, '\n');
    cout<<"Please enter your job description limited to 1024 characters."<<endl;
    cin.get(employer.description, 20, '\n');
    cin.ignore(100, '\n');
    cin.clear();  
}

/*
@author harsukh singh
@function writes to file
@param struct object and character array
@return 1 or 0.
*/

int write_name_education(char to_write[], name &new_name, university &new_university)
{
  ofstream writer;
  writer.open(to_write, ios::app);
  if(!writer)
  {
    return 0;
  } 
  writer<<new_name.first_name<<' '<<new_name.last_name<<endl;
  writer<<new_university.college<<endl;
  writer<<new_university.major<<endl;
  writer<<new_university.gpa<<endl;; // the last characters used here specifies the 
  writer.close();
  writer.clear();
  return 1;
}

/*
@author harsukh singh
@function writes to file
@param struct object and character array.
@return 1 or 0
*/

int write_resume(char to_write[],  employment &employer)
{
  ofstream writer;
  writer.open(to_write, ios_base::app);
  if(!writer)
  {
    return 0;
  } 
  writer<<employer.company<<' '
  <<employer.start_date<< '-'<<employer.end_date<<endl;
  writer<<employer.description<<endl;
  writer.close();
  writer.clear();
  return 1;
}

/*
@author harsukh singh
@function writes to file
@param struct object and character array.
@return 1 or 0
*/

int write_delimiter(char to_write[])
{
  ofstream writer;
  writer.open(to_write, ios_base::app);
  if(!writer)
  {
    return 0;
  }
  writer<<':'<<endl;
  writer.close();
  writer.clear();
  return 1;
}
