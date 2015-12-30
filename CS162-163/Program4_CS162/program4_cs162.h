/*600 word algorithm starts here...
 * 
 * The purpose of this program was to design an attendance application that keeps track of a roster of students using dynamically allocated arrays. The two classes designed for this application were the student class and the attendance class. The attendance class uses creates a roster of students based on a dynamically allocated array of class objects from the user input. The algorithms for functions in the attendance class are as given,
 * 	Algorithm for constructor function:
 * 		i) Dynamically allocate memory containing the student class based on default constructor, these are pointers to pointers.
 *		ii)Dynamically allocate memory for each pointer based non default constructor
 *		iii) Get the students name. 
 * 	Algorithm for read lab and lecture attendance functions:
 * 		i) Iterate through the array and call the student read functions.
 * 	Algorithm for display function:
 * 		i) Iterate through the array and call the display functions
 * The attendance class mainly serves as a wrapper class that encapsulates the functionality of another student class or component of the student class, so most of the functions are iterators. The class is useful for providing a level of abstraction from the implementation of the student class and components; they also simplify the use of the student class by reducing the number interface points involved thus most of them are iterative functions; frequently.
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
 * 
 * 
 * 
 */


// @author harsukh singh
// @version 1 3/5/2015

#include <iostream>
#include <cstring>
#include <cctype>
// @author harsukh singh
// student class with functions

class student
{
    public:
        student(int num_lectures, int num_labs);
	student();
        ~student();
        int attend_lab(int lab_number);
        int attend_lecture(int lecture_number);
        void get_name();
	//Only displays the information if the student name matches
        int display(char* student_check);
        int check_string(char* guess, char* check);
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
// @author harsukh singh
// attendance class with functions

class attendance
{
    public:
	attendance();
        attendance(int num_students, int labs, int lectures);
        ~attendance();
        void read_lab_attendance(int lab);
        void read_lecture_attendance(int lecture);
        void display_attendance(char* student_name);
        void display_all();
    private:
        student** students_array;
        int number_of_students;
};
