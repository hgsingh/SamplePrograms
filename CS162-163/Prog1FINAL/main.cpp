
#include <iostream>
#include "cs163_program1.h"
using namespace std;
int main()
{
  char exit;
  int i = 0;
  do{
  char powers[] = "powers.dat"; //file name
  char heros[] = "heroes.dat";
  char super_power[33];
  char situation[33*6];
  Hero_Match new_hero; //object class instantiation
  int choice = new_hero.prompt();
  new_hero.load_heros(powers, heros); // calling function for test
  if(choice == 1){
    new_hero.display();
  }
  if(choice == 2)
  {
    cout<<"Please enter a super power"<<endl;
    cin.get(super_power, 33, '\n');
    cin.ignore(100, '\n');
    int success = new_hero.display(super_power);
    if(success == 0)
    {
      cout<<"This power cannot be found"<<endl;
    }
  }
  if(choice == 3)
  {
    cout<<"Please enter the situation"<<endl;
    cin.get(super_power, 33, '\n');
    cin.ignore(100, '\n');
    char* result = new_hero.find(situation);
    if(result == NULL)
    {
      cout<<"No matched situation."<<endl;
    }
    cout<<result;
    delete[] result;
  }
  if(choice == 4)
  {
    for(int j = 0; j<33; j++)
    {
     super_power[j] =  1; 
    }
    cout<< "Please enter the power to remove."<<endl;
    cin.get(super_power, 33, '\n');
    cin.ignore(100, '\n');
    int success = new_hero.remove_power(super_power);
    new_hero.display();
  }
  if(choice ==5)
  {
    int success = new_hero.add_hero();
    new_hero.display();
  }
  if(i>=1)
  {
   cout<<"To exit press q other wise press anything to continue"<<endl;
   cin.get(exit);
   cin.ignore(100, '\n');
   tolower(exit);
  }
  ++i; // run more than once
  }while(exit != 'q');
  return 0;
}