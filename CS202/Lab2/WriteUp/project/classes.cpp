/********************
 *@author harsukh singh CS 202 Assignment 2
 *@file classes.cpp contain the implementation of the classes heirarchy and the required class 
 *static casting is used regularly in the required cast
 * ******************/

#include "classes.h"
using namespace std;


/********************
 *@author harsukh singh CS 202 Assignment 2
 *@function constructor default for gen class
 *@args void
 *@return void
 * ******************/
gen_class::gen_class():next(0)
{
    grade = 0;
    course_name = NULL;
    credits = 0;
}

/********************
 *@author harsukh singh CS 202 Assignment 2
 *@function constructor for gen class
 *@args data associated with a class
 *@return void
 * ******************/
gen_class::gen_class(char* current_course, float course_grade, int course_credits):next(0)
{
    course_name = new char[strlen(current_course) + 1];
    strcpy(course_name, current_course);
    grade = course_grade;
    credits = course_credits;
}


/********************
 *@author harsukh singh CS 202 Assignment 2
 *@function copy constructor for gen class
 *@args data associated with a class
 *@return void
 * ******************/
gen_class::gen_class(const gen_class &node_to_copy):next(0)
{
    if(!node_to_copy.course_name){}
    else{
        course_name = new char[strlen(node_to_copy.course_name) + 1];
        strcpy(course_name, node_to_copy.course_name);
        grade = node_to_copy.grade;
        credits = node_to_copy.credits;
    }
}


/*******************
 *@author harsukh singh 
 *@function setter function for next pointer
 *@args next pointer
 *@return void
 * *****************/
void gen_class::set_next(gen_class* next_ptr)
{
    next = next_ptr;
}

/*******************
 *@author harsukh singh 
 *@function getter for next pointer
 *@args void
 *@return returns next
 * *****************/

gen_class* &gen_class::get_next()
{
    return next;
}


/********************
 *@author harsukh singh CS 202 Assignment 2
 *@function copy constructor for non core class
 *@args data associated with a class
 *@return void
 * ******************/
non_core::non_core(const non_core  &node_to_copy):gen_class(node_to_copy)
{
  
}


/********************
 *@author harsukh singh CS 202 Assignment 2
 *@function copy constructor for core class
 *@args data associated with a class
 *@return void
 * ******************/
core::core(const core  &node_to_copy):gen_class(node_to_copy)
{
}


/********************
 *@author harsukh singh CS 202 Assignment 2
 *@function core constructor
 *@args void
 *@return void
 * ******************/
core::core()
{
}

/********************
 *@author harsukh singh CS 202 Assignment 2
 *@function core construcotr
 *@args data associated with a university class
 *@return void
 * ******************/
core::core(char* current_course, float course_grade, int course_credits): gen_class(current_course, course_grade, course_credits)
{
}


/********************
 *@author harsukh singh CS 202 Assignment 2
 *@function non_core constructor
 *@args void
 *@return void
 * ******************/
non_core::non_core()
{
}


/********************
 *@author harsukh singh CS 202 Assignment 2
 *@function  non_core constructor
 *@args data associated with a university class
 *@return void
 * ******************/
non_core::non_core(char* current_course, float course_grade, int course_credits): gen_class(current_course, course_grade, course_credits)
{
}


/********************
 *@author harsukh singh CS 202 Assignment 2
 *@function destructor for gen_clas
 *@args void
 *@return void
 * ******************/
gen_class::~gen_class()
{
    delete[] course_name;
}


/********************
 *@author harsukh singh CS 202 Assignment 2
 *@function core destructor 
 *@args void
 *@return void
 * ******************/
core::~core(){}

/********************
 *@author harsukh singh CS 202 Assignment 2
 *@function non_core destructor
 *@args void
 *@return void
 * ******************/
non_core::~non_core(){}


/********************
 *@author harsukh singh CS 202 Assignment 2
 *@function display function for gen class
 *@args void
 *@return void
 * ******************/
void gen_class::display()
{
    cout<<"General class."<<endl;
    cout<<course_name<<endl;
    cout<<"The grade for this course is, "<<grade<<endl;
    cout<<"The credit load for this course is, "<<credits<<endl;
}


/********************
 *@author harsukh singh CS 202 Assignment 2
 *@function display function for core class
 *@args void
 *@return void
 * ******************/
void core::display()
{
    cout<<"Core class"<<endl;
    cout<<course_name<<endl;
    cout<<"The grade for this course is, "<<grade<<endl;
    cout<<"The credit load for this course is, "<<credits<<endl;
}


/********************
 *@author harsukh singh CS 202 Assignment 2
 *@function display function for non core class
 *@args void
 *@return void
 * ******************/
void non_core::display()
{
    cout<<"Non core class"<<endl;
    cout<<course_name<<endl;
    cout<<"The grade for this course is, "<<grade<<endl;
    cout<<"The credit load for this course is, "<<credits<<endl;
}


/********************
 *@author harsukh singh CS 202 Assignment 2
 *@function getter for the number of credits in the course
 *@args void
 *@return int credits
 * ******************/
int gen_class::get_credits()
{
    return credits;
}


/********************
 *@author harsukh singh CS 202 Assignment 2
 *@function setter function for the number of credits
 *@args int course credits
 *@return void
 * ******************/
void gen_class::set_credits(int course_credits)
{
    credits = course_credits;
}


/********************
 *@author harsukh singh CS 202 Assignment 2
 *@function setter function for the grade
 *@args course grade as floating point val
 *@return void
 * ******************/
void gen_class::set_grade(float course_grade)
{
    grade = course_grade;
}


/********************
 *@author harsukh singh CS 202 Assignment 2
 *@function returns the grade of the course
 *@args void
 *@return floating point val of the grade
 * ******************/
float gen_class::get_grade()
{
    return grade;
}


/********************
 *@author harsukh singh CS 202 Assignment 2
 *@function course char array setter
 *@args char* course name to set
 *@return void
 * ******************/
void gen_class::set_course_name(char* current_course)
{
    if(!current_course)
        return;
    if(course_name)
        delete[] course_name;
    course_name = new char[strlen(current_course) + 1];
    strcpy(course_name, current_course);
}


/********************
 *@author harsukh singh CS 202 Assignment 2
 *@function returns the course name as char*
 *@args void
 *@return returns the char* to the array
 * ******************/
char* gen_class::get_course()
{
    return course_name;
}


/*
 * @author harsukh singh
 * @function check string function takes a guess word and compares it against the check
 * @param a guess word and a word to check against
 * @return 1 or 0
 */
int gen_class::check_string(char* guess, char* check) //compares the guess word to the known check word 
{
    char* comp1;
    char* comp2;
    int success = 0;
    int length = 0;
    char* temp_guess = new char[((unsigned) strlen(guess) + 1)];
    char* temp_check = new char[((unsigned) strlen(check) + 1)];
    unsigned int i;
    for(i = 0; i<(unsigned) strlen(guess); ++i)
    {
        if(guess[i] != ' ')
        {
            temp_guess[length] = guess[i];
            ++length;
        }
    }
    temp_guess[length] = '\0';
    length = 0;
    unsigned int j;
    for(j = 0; j<(unsigned) strlen(check); ++j){
        
        if(check[j] != ' ')
        {
            temp_check[length] = check[j];
            ++length;
        }
    }
    temp_check[length] = '\0';
    length = 0;
    unsigned int k;
    if((unsigned) strlen(temp_guess) != (unsigned) strlen(temp_check)) return success;
    if(temp_check[0] == temp_guess[0])
    { 
        int count = 0;
        comp1 = &temp_check[0];
        comp2 = &temp_guess[0];
        while(*comp1 == *comp2)
        {
            comp1 = comp1 +1;
            comp2 = comp2 +1;
            count = count + 1;
            if(count == ( unsigned) strlen(temp_guess)){
                success = 1;
                delete[] temp_guess;
                delete[] temp_check;
                return success;
            } 
        } 
    }
    delete[] temp_guess;
    delete[] temp_check;
    return success;
}


/********************
 *@author harsukh singh CS 202 Assignment 2
 *@function required constructor makes a list of all requriements
 *@args void
 *@return void
 * ******************/
required::required():a_class(0)
{
}


/********************
 *@author harsukh singh CS 202 Assignment 2
 *@function destructor 
 *@args void
 *@return void
 * ******************/
required::~required()
{
    remove_all(a_class);
}


/********************
 *@author harsukh singh CS 202 Assignment 2
 *@function inserts only required classes to get into program into the list
 *@args void  
 *@return void
 * ******************/
void required::make_list()
{
    insert_class(a_class,"MTH 251\0", 4, 'n');
    insert_class(a_class,"CS 250\0", 4, 'c');
    insert_class(a_class, "CS 251\0", 4, 'c');
    insert_class(a_class,"CS 202\0", 4, 'c');
    insert_class(a_class, "CS 201\0", 4, 'c');
    insert_class(a_class, "CS 163\0", 4, 'c');
    insert_class(a_class, "CS 162\0", 4, 'c');
    insert_class(a_class, "MTH 252\0", 4, 'n');
    insert_class(a_class, "COMM 220\0", 4, 'n');
    insert_class(a_class, "WR 121\0", 4, 'n');
    insert_class(a_class, "Science \0", 5, 'n');
    insert_class(a_class, "Science\0", 5, 'n');
    insert_class(a_class, "Science\0", 5, 'n');
}


/********************
 *@author harsukh singh CS 202 Assignment 2
 *@function inserts into the list based on class data
 *@args data associated with a university class and the type of class n or c
 *@return success or false
 * ******************/
int required::insert_class(gen_class* &a_class, char* course_name, int credits, char type)
{
    if(!a_class)
    {
        if(type == 'n')
        {
            a_class = new non_core(course_name, 70.0, credits);
            return 1;
        }
        if(type == 'c')
        {
            a_class = new core(course_name, 73.0, credits);
            return 1;
        }
        else{
            return 0;
        }
    }
    return insert_class((gen_class *&)a_class->get_next(), course_name, credits, type);
}


/********************
 *@author harsukh singh CS 202 Assignment 2
 *@function removes clas based on course name
 *@args class head and course name
 *@return 1 or 0 based on success
 * ******************/
int required::remove_class(gen_class* &a_class, char* course_name)
{
    if(!a_class) return 0;
    if(!course_name) return 0;
    if(a_class->check_string(course_name, a_class->get_course()) == 1)
    {
        gen_class* temp = a_class;
        a_class = (gen_class*)a_class->get_next();
        delete temp;
        return 1;
    }
    return remove_class((gen_class* &)a_class->get_next(), course_name);
}


/********************
 *@author harsukh singh CS 202 Assignment 2
 *@function remove all function for destructor
 *@args head
 *@return 1 or 0 based on success
 * ******************/
int required::remove_all(gen_class* &a_class)
{
    if(!a_class) return 0;
    remove_all((gen_class* &)a_class->get_next());
    delete a_class;
    return 1;
}


/********************
 *@author harsukh singh CS 202 Assignment 2
 *@function removes clas based on course name
 *@args class head and course name
 *@return 1 or 0 based on success
 * ******************/
int required::remove_class(char* course_name)
{
    return remove_class(a_class, course_name);
}


/********************
 *@author harsukh singh CS 202 Assignment 2
 *@function display list
 *@args class head 
 *@return void
 * ******************/
void required::display(gen_class * &a_class)
{
    if(!a_class) return;
   // cout<<a_class->get_course()<<endl;
    //cout<<a_class->get_credits()<<endl;
    a_class->display();
    display((gen_class*&)a_class->get_next()); 
    return;
}


/********************
 *@author harsukh singh CS 202 Assignment 2
 *@function display wrapper
 *@args void
 *@return void
 * ******************/
void required::display()
{
    display(a_class);
}


/********************
 *@author harsukh singh CS 202 Assignment 2
 *@function checks if list is empty
 *@args void
 *@return 1 or 0 based on success
 * ******************/
bool required::is_empty()
{
    if(!a_class) return true;
    return false;
}
