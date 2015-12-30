//@author harsukh singh
#include "program4_cs162.h"
using namespace std;
//@author harsukh singh
//main function
int main()
{
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
    char get_attendance = 'y';
    while(get_attendance == 'y')
    {
	int lecture;
	int lab;
	cout<<"Please enter the lecture number you want to attendance for."<<endl;
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
    char display;
    cout<<"If you would like to display the entire attendance, press 'y'. If you would like to display a specific students attendance please press 'd' "<<endl;
    cin.get(display);
    cin.ignore(100, '\n');
    if(display == 'y')
    {
	new_attendance.display_all();
    }
    if(display == 'd'){
	cout<<"If you would like a specific student's attendance please enter the students name."<<endl;
	char* new_name = new char[100];
	new_attendance.display_attendance(new_name);
    }
    return 0;
}
