//@author harsukh singh
//computer class derived from player
//4/19/2015 CS 202
#include "prog1.h"
using namespace std;

//default constructor
computer::computer()
{

}


//@author harsukh singh
//CS202 4/19/2015
//number generator based on computer hand
int computer::gen_num()
{
    //srand(time(NULL));
    //int i = 0;
    int number = (rand() % 10) + 1;
    while(check(number) == false)
    {
	//++i;
	//srand(time(NULL) + i);
        number = (rand() % 10) + 1; 
    }
    return number;
}

//default destructor
computer::~computer()
{

}
