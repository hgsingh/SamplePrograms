/*******************
 *@author harsukh singh 
 *@file contains function prototypes for term object and node object
 * *****************/

#include <iostream>
#include <cstring>
#include <cctype>
#include <cmath>
/*******************
 *@author harsukh singh 
 *@class term object that contains data associated with a school term with associated setter and getters 
 * *****************/

class term
{
    public:
	term();//default contructor
        term(char* current_term, int courses, float term_gpa, int credits_to_add, int school_year);//contructor
	term(const term  & term_to_copy);
	~term(); //destructor
        float get_gpa(); //setter and getters defined for all functions below
        int get_num_courses();
        int get_year();
        int get_credits();
        void set_credits(int credits_to_add);
        void set_year(int school_year);
        void set_num_courses(int courses);
        void set_gpa(float term_gpa);
	void set_term(char* current_term);
	char* get_term();
    protected: //data members for term
        float gpa;
        int num_courses;
        int year;
	char* school_term;
        int credits;
};
/*
 * This object is not being used and is ported into the gen class 
*******************
 *@author harsukh singh 
 *@class node object for LLL
 * *****************

class node
{
    protected:
        node* next; // next data member
    public:
        node(); //default constructor
        node(node * next_ptr); //next constructor
        ~node(); //destructor
        node* &get_next(); //getter for next
        void set_next(node* next_ptr); //setter for next
};
*/
