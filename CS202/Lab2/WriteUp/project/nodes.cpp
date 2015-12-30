/*******************
 *@author harsukh singh 
 *@file contains the term and the node class
 * *****************/
#include "node.h"

/*******************
 *@author harsukh singh 
 *@function term constructor
 *@args all the relevant stuff to contain in term
 *@return void
 * *****************/

term::term(char* current_term, int courses, float term_gpa, int credits_to_add, int school_year)
{
    if(!current_term) return;
    school_term = new char[strlen(current_term)+1];
    strcpy(school_term, current_term);
    num_courses = courses;
    gpa = term_gpa;
    credits = credits_to_add;
    year = school_year;
}

/*******************
 *@author harsukh singh 
 *@function default constructor
 *@args term information
 *@return void
 * *****************/

term::term():school_term(0), gpa(0.0), credits(0), num_courses(0), year(0)
{
}

/*******************
 *@author harsukh singh 
 *@function copy constructor
 *@args term information
 *@return void
 * *****************/

term::term(const term  & term_to_copy)
{
    school_term = new char[strlen(term_to_copy.school_term)+1];
    strcpy(school_term, term_to_copy.school_term);
    num_courses = term_to_copy.num_courses;
    gpa = term_to_copy.gpa;
    credits = term_to_copy.credits;
    year = term_to_copy.year;
}

/*******************
 *@author harsukh singh 
 *@function destructor
 *@args void
 *@return void
 * *****************/

term::~term()
{
    delete[] school_term;
}

/*******************
 *@author harsukh singh 
 *@function returns a pointer to term array
 *@args void
 *@return char*
 * *****************/

char* term::get_term()
{
    return school_term;
}

/*******************
 *@author harsukh singh 
 *@function sets the term pointer
 *@args a array passed by reference
 *@return void
 * *****************/

void term::set_term(char* current_term)
{
    if(!current_term) return;
    if(school_term)
    {
        delete[] school_term;
    }
    school_term = new char[strlen(current_term)+1];
    strcpy(school_term, current_term);
}

/*******************
 *@author harsukh singh 
 *@function sets the gpa
 *@args gpa float
 *@return float num
 * *****************/

void term::set_gpa(float term_gpa)
{
    gpa = term_gpa;
}

/*******************
 *@author harsukh singh 
 *@function sets the number of courses taken
 *@args int 
 *@return void
 * *****************/

void term::set_num_courses(int courses)
{
    num_courses = courses;
}

/*******************
 *@author harsukh singh 
 *@function sets school year
 *@args int 
 *@return void
 * *****************/

void term::set_year(int school_year)
{
    year = school_year;
}
/*******************
 *@author harsukh singh 
 *@function sets amount of credits
 *@args int
 *@return void
 * *****************/

void term::set_credits(int credits_to_add)
{
    credits = credits_to_add;
}
/*******************
 *@author harsukh singh 
 *@function returns credits taken
 *@args void
 *@return int
 * *****************/

int term::get_credits() 
{
    return credits;
}

/*******************
 *@author harsukh singh 
 *@function returns school year
 *@args void
 *@return int
 * *****************/

int term::get_year()
{
    return year;
}

/*******************
 *@author harsukh singh 
 *@function returns the number of courses being taken
 *@args void
 *@return int
 * *****************/

int term::get_num_courses()
{
    return num_courses;
}

/*******************
 *@author harsukh singh 
 *@function returns the gpa val
 *@args void
 *@return float gpa
 * *****************/

float term::get_gpa()
{
    return gpa;
}

/*******************
 *@author harsukh singh 
 *@function default constructor for node
 *@args void
 *@return void
 * *****************

node::node():next(0)
{
}

*******************
 *@author harsukh singh 
 *@function copy constructor
 *@args next pointer
 *@return void
 * *****************

node::node(node* next_ptr)
{
    next = next_ptr;
}

*******************
 *@author harsukh singh 
 *@function destuctor
 *@args void
 *@return void
 * *****************

node::~node()
{

}

*******************
 *@author harsukh singh 
 *@function getter for next pointer
 *@args void
 *@return returns next
 * *****************

node* & node::get_next()
{
    return next;
}

*******************
 *@author harsukh singh 
 *@function setter function for next pointer
 *@args next pointer
 *@return void
 * *****************

void node::set_next(node* next_ptr)
{
    next = next_ptr;
}

*/