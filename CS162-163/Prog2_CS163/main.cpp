#include "cs163_program2.h"
using namespace std;
int main()
{
  calculator current_calculator;
  char continuity;
  c_node check_node;
  int node_count = 0;
  do{
      cout<<"Please enter a calculation with the binary options consisting of + (plus), - (subtraction), * (multiplication) and / (division)"<< endl;
      cout.flush(); //flushing output buffer
      char* string = new char[256]; //look at the first 
      int state = 0;
      cin>>ws;
      while(state == 0)
      {
	if( cin.fail() || cin.peek() == '\n'){ 
	  state =  0;
	  cin.ignore();
	  cin.clear();
	  cout<<"Please choose a valid computation."<<endl;
	} 
	else{
	  cin.get(string, 256, '\n');
	  cin.ignore(100, '\n'); 
	  state = 1;
	}
      }
      current_calculator.populate(string, node_count); //populate stuff
      delete[] string;
      int option;
      cout<<"To display last operation, press 1."<<endl;
      cout<<"To display full history, press 2."<<endl;
      cout<<"To undo an operation, press 3."<<endl;
      cout<<"To print the current total press 4."<<endl;
      cin>>option;
      cin.ignore(100, '\n');
      cin.clear();
      if(option == 1)
      {
	current_calculator.last_operation(check_node);
      }
      if(option == 2)
      {
	current_calculator.view_history();
      }
      if(option == 3)
      {
	int number_of_times;
	cout<<"To undo the last operation press, 0 or give me a number."<<endl;
	cin>>number_of_times;
	cin.ignore(100, '\n');
	cin.clear();
	if(number_of_times ==0)
	{
	  current_calculator.last_operation(check_node);
	  current_calculator.undo(check_node);
	}
	if(number_of_times > 0)
	{
	  current_calculator.undo(number_of_times);
	}
	else{
	  cout<<"Exit"<<endl;
	}
      }
      if(option == 4)
      {
	current_calculator.calculate(node_count);
      }
      cout<< "To keep adding computations press y."<<endl;
      cin.get(continuity);
      cin.ignore(100, '\n');
      continuity = tolower(continuity);
    }while(continuity == 'y');

    current_calculator.view_history();
  //cout<<string<<endl;
    


  return 0;
}
