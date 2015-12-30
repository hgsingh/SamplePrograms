/*
600 word algorithm starts here...

This program is used for building resumes...?
*/
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
int write_resume(char to_write[], employment* &employer); //writes things file named to_write
int write_name_education(char to_write[], name &new_name, university &new_university); //writes name to file
void get_name(name &new_name); //gets persons name, takes a name object as parameter
void get_education(university &new_university); //gets person education, takes university object as parameter
void get_employment(employment* &new_employer); //gets persons occupational experience
int read_and_display(char to_writer[]);
bool more();
int write_delimiter(char to_write[]);
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
    employment *employer = new employment;
    get_employment(employer);
    write_resume(to_write, employer);
    delete employer;
    cout<<'\n'<<endl;
    bool response = more();
  }
  if(experience == 'y'){
  write_delimiter(to_write);
  cout<<endl;
  }
  read_and_display(to_write);
  return 0; 
}
int read_and_display(char to_write[])
{
  int count = 0;
  int* length = new int[50]; 
  char* to_read = new char[300];
  int i = 0;
  ifstream reader;
  reader.open(to_write, ios::in);
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
        reader.seekg(0, reader.beg);  // go back to beginning
        char read_line[i];
        int j = 0;
        while(!reader.eof())
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
        int to_go = length[count-1];
        cout<<to_go<<endl;
        reader.seekg(-to_go, ios::cur); // go back to the last  encounter of the ':' char
        char read_line[to_go];
        int j = 0;
        while(!reader.eof())
        {
          read_line[j] = reader.get();
          cout<<read_line[j];
          ++j;
        }
        char temp = reader.peek();
        cout<<temp<<endl;
        break;
      }
      else i = 0;
    }
    ++i;  
  }
  delete[] length;
  reader.close();
  reader.clear();
}
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
void get_employment(employment* &employer)
{
    cout<<"Please enter your company name."<<endl;
    cin.get(employer->company, 127, '\n');
    cin.ignore(100, '\n');
    cout<<"Please enter your start date in the MM/DD/YYY fashion."<<endl;
    cin.get(employer->start_date, 20, '\n');
    cout<<"Please enter your end date in the MM/DD/YYY fashion or enter \" current \" for currently employed."<<endl;
    cin.get(employer->end_date, 20, '\n');
    cin.ignore(100, '\n');
    cout<<"Please enter your job description limited to 1024 characters."<<endl;
    cin.get(employer->description, 20, '\n');
    cin.ignore(100, '\n');
    cin.clear();  
}
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
int write_resume(char to_write[],  employment* &employer)
{
  ofstream writer;
  writer.open(to_write, ios_base::app);
  if(!writer)
  {
    return 0;
  } 
  writer<<employer->company<<' '
  <<employer->start_date<< '-'<<employer->end_date<<endl;
  writer<<employer->description<<endl;
  writer.close();
  writer.clear();
  return 1;
}
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
bool more()
{
    char response;
    cout <<"Would you like to more information into resume? ";
    cin.get(response);
    cin.ignore(100,'\n');
    cin.clear();
    if (toupper(response) == 'Y')
    {
      return true;
    }
    return false;
}
