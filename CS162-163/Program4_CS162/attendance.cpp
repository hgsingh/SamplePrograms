//@author harsukh singh
#include "program4_cs162.h"
using namespace std;

//@author harsukh singh
//non-default constructor
attendance::attendance(int num_students, int labs, int lectures)
{
    students_array = new student*[num_students];
    
    for(int i = 0; i<num_students; ++i)
    {
        students_array[i] = new student(labs, lectures);
	students_array[i] -> get_name();
    }
    number_of_students = num_students;
}
//default constructor
attendance::attendance(){}

//@author harsukh singh
//destructor
attendance::~attendance()
{
    for(int i = 0; i< number_of_students; ++i)
    {
	delete students_array[i]
    }
    delete[] students_array;
}

//@author harsukh singh
//reads labs attendance from user
void attendance::read_lab_attendance(int lab)
{
    for(int i = 0; i<number_of_students; ++i)
    {
        students_array[i]->attend_lab(lab);
    }
}

//@author harsukh singh
//reads lecture attendance from user
void attendance::read_lecture_attendance(int lecture)
{
    for(int i = 0; i<number_of_students; ++i)
    {
        students_array[i]->attend_lecture(lecture);
    }
}

//@author harsukh singh
//displays attendance information for everyone in class
void attendance:: display_all()
{
    for(int i = 0; i<number_of_students;++i)
    {
        students_array[i]->display();
    }
}

//@author harsukh singh
//displays attendance information for a specific student
void attendance::display_attendance(char* student_name)
{
    int j = 0;
    for(int i = 0; i<number_of_students && j != 1; ++i)
    {
       j =  students_array[i]->display(student_name);
    } 
}


