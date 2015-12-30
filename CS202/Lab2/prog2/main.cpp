/*******************
 *@author harsukh singh 
 *@file main function
 *******************/


#include "classes.h"
using namespace std;


//@author harsukh singh
//main function begins here makes a bst_node object and inserts to tree
//@args 0
//@return 0
int main()
{
    int credit_sum = 0;
    int num_terms = 0;  // make varaibles here
    float gpa_sum = 0;
    required list;
    list.make_list();
    binary_tree new_tree;
    cout<<"This program will track your progress through to the CS Program."<<endl;
    char get_term = 'y';
    while(get_term =='y') //pass data here
    {
	char term[7];
	char term_check[7];
	bool check_string = false;
	int school_year;
	while(check_string == false){
	  cout<<"Please enter the school term."<<endl;
	  cin.get(term, 7, '\n');
	  cin.ignore(100, '\n');
	  int i = 0;
	  while(term[i] != '\0')
	  {
	      if(term[i] != ' ')
	      {
		  term_check[i] = tolower(term[i]);
	      }
	      ++i;
	  }
	  term_check[i] = '\0';
	  if((strcmp("winter", term_check) == 0) || (strcmp("fall", term_check) == 0) || (strcmp("spring", term_check) == 0) || (strcmp("summer", term_check) == 0))
	  {
	      check_string = true;
	  }
	  else{
		cout<<"You can only choose fall, winter, spring, summer as terms of the school year"<<endl;
	  }
	}
	char response = 'y';
	cout<<"Please enter the school year."<<endl;
	cin>>school_year;
	cin.ignore(100, '\n');
	cin.clear(); 
	bst_node* new_term = new bst_node(term_check, 0, 0.0, 0, school_year);
	while(response == 'y')
	{
	    //call update values after making the term object
	    char class_name[35];
	    float grade = 0;
	    int credits = 0;
	    char type;
	    cout<<"Please enter the name of a course you're taking. Limit the input to 35 characters"<<endl;
	    cin.get(class_name, 35, '\n');
	    cin.ignore(100, '\n');
	    cout<<"Please enter the grade that you received in this course. Limit it to a 1 to 100 scale"<<endl;
	    cin>>grade;
	    cout<<"Please enter the credit value of the course."<<endl;
	    cin>>credits;
	    cout<<"If this is a science elective press or a non core class press 'n'."<<endl;
	    cout<<"If this is a core computer science class please press 'c'."<<endl;
	    cout<<"If this is a general elective please press 'g'."<<endl;
	    cin>>type;
	    cin.ignore(100, '\n');
	    if(type == 'n' || type == 'g' || type == 'c'){
		new_term->insert_class(class_name, grade, credits, type);
	    }
	    list.remove_class(class_name,grade);
	    if(list.is_empty())
	    {
		cout<<"All core and non-core course requirements comleted"<<endl;
	    }
	    cout<<"If you would like to enter another course press 'y'"<<endl;
	    cin>>response;
	    cin.ignore(100, '\n');
	}
	new_term->update_values(); //update private member functions based on user data entered
	credit_sum = new_term->get_credits() + credit_sum;
	++num_terms;
	gpa_sum = gpa_sum + new_term->get_gpa();
	if(credit_sum == 90) cout<<"credit requirements complete"<<endl;
	new_tree.insert(new_term);
	cout<<"remaining requirements"<<endl;
	list.display();
	cout<<"If you would like to enter more terms please press 'y'"<<endl;
	cin>>get_term;
	cin.ignore(100, '\n');
    }
    //new_term->display(); //display here
    new_tree.display_all();
    float ave = gpa_sum/num_terms;
    cout<<"Average gpa is "<<ave<<endl;
    //new_tree.remove("spring", 1993); //test remove
    return 0;
}
