#include <stdio.h>
#include <stdlib.h>

void printnum(unsigned int num);
void recover();

/*************
 *@author harsukh singh
 *@function recover function points to the stack frame of the last recursive call to obtain arguments
 *@args void
 *@return void
 * ************/
void recover()
{   
    int* last_ptr = (int*) &last_ptr;
    last_ptr += 21;
    int countUp = *(last_ptr+3);
    int i = 0;
    int * ptr = last_ptr + (countUp*16); 
    i= 0;
    for(i;i<countUp + 1 ;++i)
    {
        printf("foo called with args\n");
        printf("a: ");
        printnum(*ptr);
        putchar('\n');
        printf("b: ");
        printnum(*(ptr+1));
        putchar('\n');
        printf("c :");
        printnum(*(ptr+2));
        putchar('\n');
        ptr-=16;
    }
}

/*************
 *@author harsukh singh
 *@function printnum prints the passed unsigned int as hex number
 *@args unsigned int to be converted
 *@return void
 * ************/
void printnum(unsigned int num)
{
    char array[8];
    int i = 0;
    while(num != 0)
    {
        int check = num % 16;
        num = num/16;
        if(check == 15)
        {
            array[i] = 'f';
        }
        else if(check == 14)
        {
            array[i] = 'e';
        }
        else if(check == 13)
        {
            array[i] = 'd';
        }
        else if(check == 12)
        {
            array[i] = 'c';
        }
        else if(check == 11)
        {
            array[i] = 'b';
        }
        else if(check == 10)
        {
            array[i] = 'a';
        }
        else if(check == 9)
        {
            array[i] = '9';
        }
        else if(check == 8)
        {
            array[i] = '8';
        }
        else if(check == 7)
        {
            array[i] = '7';
        }
        else if(check == 6)
        {
            array[i] = '6';
        }
        else if(check == 5)
        {
            array[i] = '5';
        }
        else if(check == 4)
        {
            array[i] = '4';
        }
        else if(check == 3)
        {
            array[i] = '3';
        }
        else if(check == 2)
        {
            array[i] = '2';
        }
        else if(check == 1)
        {
            array[i] = '1';
        }
        else if(check == 0)
        {
            array[i] = '0';
        }
        ++i;
    }
    --i;
    while(i >=0)
    {
        putchar(array[i]);
        --i;
    }
}

