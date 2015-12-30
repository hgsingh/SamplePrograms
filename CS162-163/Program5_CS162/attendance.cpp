//@author harsukh singh

#include "program5_cs162.h"
using namespace std;

//@author harsukh singh
// non-default constructor
attendance::attendance(int num_students, int labs, int lectures)
{
    number_of_students = num_students;
    number_of_lectures = lectures;
    number_of_labs = labs;
    head = NULL;
}

//@author harsukh singh
// adds a student to the list, always adds at head and gets the student name
int attendance::add_student()
{
        student_node* new_student = new student_node;
	new_student -> a_student = new student(number_of_lectures, number_of_labs);
        new_student -> a_student->get_name();
        new_student -> next = NULL;
        if(head == NULL)
        {
            head = new_student;
	    return 1;
        }
        student_node* temp;
        temp = head;
        head = new_student;
        new_student -> next = temp;
	return 1;
}

//@author harsukh singh
// destructor calls remove_all function
attendance::~attendance()
{
    remove_all(head);
}

//@author harsukh singh
//remove all function, recursively deletes.. not tail optimized
int attendance::remove_all(student_node* &head)
{
   if(!head) return 0;
   remove_all(head->next);
   delete head->a_student;
   delete head;
   head = NULL;
}

//@author harsukh singh
//remove function, removes a student, wrapper for a recursive function
int attendance::remove_student(char* student_name)
{
    return remove_student(head, student_name);
}

//@author harsukh singh
//remove student, removes student based on student name using the check string funciton in the student class
int attendance::remove_student(student_node* &head, char* student_name)
{
    if(!head) return 0;
    if(head -> a_student->check_string(student_name, head -> a_student->name()) == 1)
    {
        student_node* current = head;
        if(head->next != NULL)
        {
            current = head -> next;
            delete head -> a_student;
            delete head;
            head = current;
            return 1;
        }
        delete head ->a_student;
        delete head;
        head = NULL;
        return 1;
    }

    if(head ->next-> a_student->check_string(student_name, head->next -> a_student->name()) == 1)
    {
        head->a_student->display(student_name);
        student_node* current = head->next;
        head ->next = current ->next;
        delete current -> a_student;
        delete current;
        return 1;
    }
    return remove_student(head->next, student_name);
    
}
//@author harsukh singh
//size of list function... never used.
int attendance::size_of_class(student_node* &head)
{
    if(!head) return 0;
    return 1+size_of_class(head -> next);
}

//@author harsukh singh
//attendance function, reads lab attendance given a lab
void attendance::read_lab_attendance(int lab)
{
    student_node* current = head;
    if(!head) return;
    while(current)
    {
        current -> a_student->attend_lab(lab);
        current = current -> next;
    }
}

//author harsukh singh
//attendance function, reads the attendance lecture based on lecture number
void attendance::read_lecture_attendance(int lecture)
{
    student_node* current = head;
    if(!head) return;
    while(current)
    {
        current -> a_student->attend_lecture(lecture);
        current = current -> next;
    }
}

//@author harsukh singh
//display all function, displays everything based on the list, iterates through.
void attendance::display_all()
{
    student_node* current = head;
    if(!head) return;
    while(current)
    {
        current -> a_student->display();
        current = current -> next;
    }
}

//@author harsukh singh
//display all function, displays attendance based on the character provided, iterates through.
void attendance::display_attendance(char* student_name)
{
    if(!head) return;
    student_node* current = head;
    while(current)
    {
        current -> a_student->display(student_name);
        current = current -> next;
    }
}


