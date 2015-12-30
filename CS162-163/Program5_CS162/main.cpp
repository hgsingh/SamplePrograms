//@author harsukh singh

#include "program5_cs162.h"
using namespace std;

//@author harsukh singh
//main function
int main()
{   //get variables here
    int lectures;
    int labs;
    int number_of_students;
    cout<<"Please enter the number of students attending your class."<<endl;\
    cin>>number_of_students;
    cin.ignore(100, '\n');
    cin.clear();
    cout<<"Please enter the number of lectures in your class."<<endl;
    cin>>lectures;
    cin.ignore(100, '\n');
    cin.clear();
    cout<<"Please enter the number of labs in your class."<<endl;
    cin>>labs;
    cin.ignore(100, '\n');
    cin.clear();
    attendance new_attendance(number_of_students, labs, lectures);
    int j = 0;
    //loop to add students
    while(j < number_of_students){
	new_attendance.add_student();
	++j;
    }
    char get_attendance = 'y';
    //loop to get attendance
    while(get_attendance == 'y')
    {
	int lecture;
	int lab;
	cout<<"Please enter the lecture number you want the attendance for."<<endl;
	cin>>lecture;
	cin.ignore(100, '\n');
	cin.clear();
	new_attendance.read_lecture_attendance(lecture);
	cout<<"Please enter the lab number you want attendance for."<<endl;
	cin>>lab;
	cin.ignore(100, '\n');
	cin.clear();
	new_attendance.read_lab_attendance(lab);
	cout<<"If you would like to get the attendance for another lab and lecture press 'y'"<<endl;
	cin.get(get_attendance);
	cin.ignore(100, '\n');
    }
    //loop to display attendance
    char display;
    cout<<"If you would like to display the entire attendance, press 'y'. If you would like to display a specific students attendance please press 'd' "<<endl;
    cin.get(display);
    cin.ignore(100, '\n');
    while(display == 'd' || display == 'y'){
	if(display == 'y')
	{
	    new_attendance.display_all();
	}
	if(display == 'd'){
	    cout<<"If you would like a specific student's attendance please enter the students name."<<endl;
	    char* new_name = new char[100];
	    cin.get(new_name, 100, '\n');
	    cin.ignore();
	    new_attendance.display_attendance(new_name);
	    delete[] new_name;
	}
	cout<<"If you would like to display the entire attendance, press 'y'. If you would like to display a specific students attendance please press 'd' "<<endl;
	cin.get(display);
	cin.ignore(100, '\n');
    }
    char remove;
    cout<<"If you would like to remove a student from the roster please press 'y'."<<endl;
    cin.get(remove);
    cin.ignore(100, '\n');  
    //loop to remove
    while(remove == 'y')
    {
	cout<<"If you would like to remove a specific student from the roster please enter the students name."<<endl;
	char* new_name = new char[100];
	cin.get(new_name, 100, '\n');
	cin.ignore();
	new_attendance.remove_student(new_name);
	cout<<"If you would like to remove a student from the roster please press 'y'."<<endl;
	cin.get(remove);
	cin.ignore(100, '\n');  
	new_attendance.display_all();
    }
    return 0;
}
