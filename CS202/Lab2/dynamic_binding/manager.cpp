#include "manager.h"
using namespace std;


//FINISH THIS FUNCTION.
//HINT - it needs an initialization list to set up the
//managers information
manager::manager( const salaried_employee & managers_information): salaried_employee(managers_information)
 {
    cout <<"\nPlease enter the group name: ";
    group_name.read();
    cout <<"\nHow many group_members? ";
    cin >> num_employees; cin.ignore(100,'\n');
    
    //COMPLETE THIS FUNCTION - allocating the dynamic array of
    //employees in this group:
    group  = new employee*[num_employees];
    for(int i = 0; i<num_employees;++i)
    {
        group[i] = NULL;
    }

}

//Deallocate the array of employee pointers
manager::~manager()
{
    for(int i = 0; i<num_employees; ++i)
    {
        if(group[i])
            delete group[i];
    }
    delete[] group;
}


//THIS FUNCTION REQUIRES RTTI!!!
void manager::add_to_group( const employee & to_add)
{
    int i = 0;
    employee* ptr = to_add;
    while(i<num_employee)
    {
        ptr =   dyanmic_cast<const group[i]>(to_add);
    }
}

//SAMPLE
void manager::display() const
{
    cout <<"MANAGER ";
    salaried_employee::display();
    cout <<"\nGROUP NAME: ";
    group_name.display();
    for (int i = 0; i < num_employees; ++i)
      if (group[i]) group[i]->display();
}   
