/*600 word algorithm starts here...
 * 
 * The purpose of this program was to design an attendance application that keeps track of a roster of students using a linked list. The two classes designed for this application were the student class and the attendance class. The attendance class uses creates a roster of students based on a linked list of class objects of (students) from the user input. The algorithms for functions in the attendance class are as given,
 * 	Algorithm for constructor function:
 * 		i) Sets head to NULL
 *		ii)Get the number of labs, students and lectures in the class
 *	Algorithm for adding students:
 * 		i) Create a new student object and the sub objects needed as specified by the header file
 * 		ii) Get the students name.
 * 		iii) Check head to see if it is NULL if it is, set head to new node object
 * 		iv) If not use a temp pointer to hold the list and add at head set next pointer to temp pointer. 
 * 	Algorithm for the remove function:
 * 		i) If head is NULL return false.
 * 		ii) If head node matches using the check string and head next is NULL then delete node.
 * 		iii) If head next is not NULL and the check string is true then proceed to delete node by using temporaray 
 * pointers to hold the node. 
 * Note: The destructor works the same way except that the everything is deleted and check string is not used. 
 * 	Algorithm for read lab and lecture attendance functions:
 * 		i) Iterate through the list and call the student read functions.
 * 	Algorithm for display function:
 * 		i) Iterate through the array list call the display functions
 * The attendance class mainly serves as a wrapper class that encapsulates the functionality of another student class or component of the student class, so most of the functions are iterators. The class is useful for providing a level of abstraction from the implementation of the student class and components; they also simplify the use of the student class by reducing the number interface points involved thus most of them are iterative functions; frequently. The attendance class also serves the purpose of creating and mainting the linked list ADT which holds the student objects. 
 * 
 * The non-default constructor for the student class, takes in the number of lectures and labs and initializes the dynamically allocated arrays to a '0' value. The destructor deletes these arrays. 
 * 	Algorithm for check_string(args):
This function takes the arguments provided, removes spaces from the the guess array and the compares string. In the iteration the function also checks if the word belongs to the phrase, which if it doesn't the user gets a false flag.  
    1. The function takes both arrays iterates through them and lower cases each letter to match the guess word to the array. 
    2. Next the function uses two local variable pointers that are pointing at the respective arrays.
    3. One variable pointer points to the first character of the guess word and the other one points to the nth index of the phrase.
    4. During iteration when the nth index and the first character of the guess word match, the temporary pointer and the iterate through both arrays until the string length of the guess word array is iterated and then returns a match. 
    5. If the word is not in the phrase the function returns a zero. 
	Algorithm for attend functions:
	  i) initializes a flag for success or failure.
	  ii) check the lab number
	  iii) if lab number is not within desired parameter return false flag
	  iv) if it is then get the choice flag
	  v) input 1 for present or 0 for not present.
    Both of the attend labs and lectures functions serve as the user inputs, even in the wrapper functions. Each of these functions are called together in the main function, however it is generalized enough that a programmer can change them at will to serve for either lecture or lab separately. The get name function and name functions are used for comparison purposes, the get name function turns the '0' value name array to the students name with the ending delimiter character. The name function returns the pointer to the array that can be used with the check string function. 
    
    Similarly with the display functions which follow a similar algorithm. For the display function for a specific student which takes a character array. If the check string function returns a true value then the function proceeds to display the array or otherwise returns a false flag. If it returns 1 then the attendance arrays are checked for 1 or 0, 1 being the attended boolean flag and output strings based on the flag. 
 *  
 */


// @author harsukh singh
// @version 1 3/9/2015


#include <iostream>
#include <cstring>
#include <cctype>
// @author harsukh singh
// student class with functions
class student
{
    public:
        student(int num_lectures, int num_labs); //non-default constructor
	student();
        ~student();
        int attend_lab(int lab_number); //gets attendance for lab
        int attend_lecture(int lecture_number);//gets attendance for lecture
        void get_name();
	//Only displays the information if the student name matches
        int display(char* student_check);
        int check_string(char* guess, char* check); //string compares
        //displays the attendance information, including the name
        void display();
        char* name();
    private:
        char* student_name;
        int* labs;
        int* lectures;
        int lectures_to_attend;
        int labs_to_attend;
};

//@author harsukh singh
//nodes for linear linked list
struct student_node
{
    student* a_student;
    student_node* next;
};

// @author harsukh singh
// attendance class with functions
class attendance
{
    public:
	attendance();
        attendance(int num_students, int labs, int lectures);
        ~attendance();
        void read_lab_attendance(int lab); //wrapper for reading attendance
        void read_lecture_attendance(int lecture); //wrapper for reading attendance
        int add_student();
        int remove_student(char* student_name); //wrapper for removing student
	int remove_student(student_node* &head, char* student_name); //removing student recursively
        int remove_all(student_node* &head); //removing all called in destructor
        int size_of_class(student_node* &head); //returns size of class never used.
        void display_attendance(char* student_name); //displays attendance of a given student
        void display_all(); //displays all attendance
    private:
        student_node* head;
        int number_of_students;
	int number_of_lectures;
	int number_of_labs;
};


















