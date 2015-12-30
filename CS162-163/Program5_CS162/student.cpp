//author harsukh singh
#include "program5_cs162.h"
using namespace std;

//author harsukh singh
//non-default constructor
student::student(int num_lectures, int num_labs)
{
    student_name = new char[100];
    labs = new int[num_labs];
    lectures = new int[num_lectures];
    for(int i = 0; i<num_labs;++i)
    {
        labs[i] = 0;
    }
    for(int i = 0; i<num_lectures;++i)
    {
        lectures[i] = 0;
    }
    for(int i = 0; i<100; ++i)
    {
        student_name[i] = '0';
    }
    labs_to_attend = num_labs;
    lectures_to_attend = num_lectures;
}
//@author harsukh singh
//default constructor
student::student() //default constructor
{

}

//@author harsukh singh
//destructor
student::~student()
{
    delete[] student_name;
    delete[] labs;
    delete[] lectures;
}

//@author harsukh singh
//gets name of student returns void
void student::get_name()
{
    cout<<"Please enter the student's name."<<endl;
    cin.get(student_name, 100, '\n');
    cin.ignore(100, '\n');

    while(student_name[0] == '0'){
        cout<<"Please enter the student's name."<<endl;
        cin.get(student_name, 100, '\n');
        cin.ignore(100, '\n');
    }
}

//@author harsukh singh
//function of char* type returns a pointer to array object for the student name
char* student::name()
{
    return student_name;
}

//@author harsukh singh
//asks user for a specific students attendance returns flag of success or failure
int student::attend_lab(int lab_number)
{
    int success = 0;
    if(lab_number <=  labs_to_attend  && lab_number > 0)
    {
    cout<<"Is "<<student_name<<" present for lab " <<lab_number<<"?"<<" Press 'y' for present and 'n' for not present."<<endl;
        char choice;
        cin.get(choice);
        cin.ignore(100, '\n');
        choice = tolower(choice);
        while(choice != 'y' && choice != 'n')
        {
            cout<<"Is "<<student_name<<" present for lab " <<lab_number<<"?"<<" Press 'y' for present and 'n' for not present."<<endl;
            cin.get(choice);
            cin.ignore(100, '\n');
            choice = tolower(choice);
        }
        if(choice == 'n')
        {
            labs[lab_number - 1] = 0;
            success = 1;
            return success;
        }
        else{
            labs[lab_number - 1] = 1;
            success = 1;
            return success;
        }
    }
    else
    {
        cout<<"Not a valid lab number, valid labs are from 1 to "<< labs_to_attend<<endl;
        return success;
    }
}

//@author harsukh singh
//asks user for a specific students attendance returns flag of success or failure
int student::attend_lecture(int lecture_number)
{
    int success = 0;
  
    if(lecture_number <= lectures_to_attend && lecture_number > 0)
    {
        cout<<"Is "<<student_name<<" present for lecture " <<lecture_number<<"?"<<" Press 'y' for present and 'n' for not present."<<endl;
        char choice;
        cin.get(choice);
        cin.ignore(100, '\n');
        choice = tolower(choice);
        while(choice != 'y' && choice != 'n')
        {
            cout<<"Is "<<student_name<<" present for lecture " <<lecture_number<<"?"<<" Press 'y' for present and 'n' for not present."<<endl;
            cin.get(choice);
            cin.ignore(100, '\n');
            choice = tolower(choice);
        }
        if(choice == 'n')
        {
            lectures[lecture_number - 1] = 0;
            success = 1;
            return success;
        }
        else{
            lectures[lecture_number - 1] = 1;
            success = 1;
            return success;
        }
    }
    else
    {
        cout<<"Not a valid lecture number"<<endl;
        cout<<"Valid choices are " << "1-"<<lectures_to_attend<<"."<<endl;
        return success;
    }
}

//@author harsukh singh
//display function for a student given that the character array matches
int student::display(char* student_check)
{
    int success = 0;
    if(check_string(student_name, student_check) == 1)
    {
        for(int i = 0; i<labs_to_attend;++i)
        {
            if(labs[i] == 1)
            {
                cout<<"Lab Number "<< i + 1<<" attended."<<endl;
            }
            else
            {
                cout<<"Lab Number "<< i + 1 <<" not attended."<<endl;
            }
        }
        for(int i = 0; i<lectures_to_attend;++i)
        {
            if(lectures[i] == 1)
            {
                cout<<"Lecture Number "<< i + 1 <<" attended."<<endl;
            }
            else
            {
                cout<<"Lecture Number "<< i + 1<<" not attended."<<endl;
            }
        }
        success = 1;
        return success;
    }
    else
    {
        return success;
       // cout<<"Student does not exist"<<endl;
    }
}

//@author harsukh singh
//complicated string compare function
int student::check_string(char* guess, char* check)
{
    char* comp1;
    char* comp2;
    int success = 0;
    int length = 0;
    char* temp_guess = new char[(unsigned) strlen(guess) + 1];
    char* temp_check = new char[(unsigned) strlen(check) + 1];
    for(unsigned int i = 0; i<(unsigned) strlen(guess); ++i)
    {
        if(guess[i] != ' ')
        {
            temp_guess[length] = tolower(guess[i]);
            ++length;
        }
    }
    temp_guess[length] = '\0';
    length = 0;
    for(unsigned int j = 0; j<(unsigned) strlen(check); ++j){
        
        if(check[j] != ' ')
        {
            temp_check[length] = tolower(check[j]);
            ++length;
        }
    }
    temp_check[length] = '\0';
    length = 0;
    for(unsigned int k = 0; k<(unsigned)strlen(temp_check); ++k)
    {
        if(temp_check[k] == temp_guess[0])
        { 
            int count = 0;
            comp1 = &temp_check[k];
            comp2 = &temp_guess[0];
            while(*comp1 == *comp2)
            {
                comp1 = comp1 +1;
                comp2 = comp2 +1;
                count = count + 1;
                if(count == ( unsigned) strlen(guess)){
                    success = 1;
                    delete[] temp_check;
                    delete[] temp_guess;
                    return success;
                } 
            } 
        }
    }
    delete[] temp_check;
    delete[] temp_guess;
    return success;
}

//@author harsukh singh
//display everything function
void student::display()
{
      cout<<"Displaying attendance information for "<<student_name<<"."<<endl;
      for(int i = 0; i<labs_to_attend;++i)
      {
	  if(labs[i] == 1)
	  {
	      cout<<"Lab Number "<< i + 1<<" attended."<<endl;
	  }
	  else
	  {
	      cout<<"Lab Number "<< i + 1<<" not attended."<<endl;
	  }
      }
      for(int i = 0; i<lectures_to_attend;++i)
      {
	  if(lectures[i] == 1)
	  {
	      cout<<"Lecture Number "<< i + 1<<" attended."<<endl;
	  }
	  else
	  {
	      cout<<"Lecture Number "<< i + 1<<" not attended."<<endl;
	  }
      }

}
