//*************************************/
/*Assignment 1 by Harsukh Singh
 * This program is to decrypt a given file based on swapping bytes and btis
 * The file is read into an array and then decrypted in the array
 * Version 1 5/1/2015
 ***************************************/
#include <stdio.h> //input and output library
#include <stdlib.h> //used for malloc 

//function definitions declared here
void swap_every_four(unsigned char* , int size);
void exclusive_or(unsigned char* , int size, unsigned char key);
void swap_bits(unsigned char*, int size);
void swap(unsigned char * a, unsigned char * b);

//main function
/*@author harsukh singh
 *@function main function reads the file into an array and uses the function declaration to read the decrypted contents of the array
 *@params void
 *@return exit as int 0
 */
int main(int argc, unsigned char** argv)
{
    FILE* input_file;
    unsigned char* input_array;
    input_file = fopen(argv[1], "r"); //declare read mode
    if(!input_file) //check if file exists
    {
        printf("This file does not exist");
        fclose(input_file);
        return 0;
    }
    if(input_file) //reads the name of the file
    {
        printf("file received \n");
        printf("file name is %s \n",argv[1]);
    }
    fseek(input_file, 0, SEEK_END); //finds the length of the file
    int size = ftell(input_file);
    fseek(input_file, 0, SEEK_SET);
    printf("size of file is %d\n", size);
    input_array = malloc(size); // malloc the size of the bytes
    fread(input_array, 1, size, input_file);
    if(input_array == NULL) //nothing read in by the file
    {
        printf("nothing to read\n");
        return 0;
    }
    else{
        printf("contents stored in file are %s \n", input_array);
    }
    swap_every_four(input_array, size); //first stage
    swap_bits(input_array, size);//second stage
    exclusive_or(input_array, size, 'o');//third stage
    printf("decrypted contents stored in file are %s \n", input_array); //read out the file
    free(input_array);
    fclose(input_file);
    return 0;
}

/*
 * @author harsukh singh
 * @function swaps values based on addresses of the pointer
 * @params the pointer to the array of pointers which point to the chars
 * @return void
 */
void swap(unsigned char * a, unsigned char * b)
{
    unsigned char temp = *a;
    *a = *b;
    *b = temp;
}

/*
 * @author harsukh singh
 * @function swaps swaps every four of the array
 * @params array and size of the array
 * @return void
 */
void swap_every_four(unsigned char* array, int size)
{
    if(!array) return;
    int i;
    for(i = 0; i<size; ++i)
    {
        if((i + 1) % 4 == 0) //found another 4 bytes
        {
             swap(&array[i-2], &array[i]);
        }
    }
}

/*
 * @author harsukh singh
 * @function exlusive or certain chars with the key
 * @params array and size of the array and the key to XOR with
 * @return void
 */
void exclusive_or(unsigned char* array, int size, unsigned char key)
{
    if(!array) return;
    int i;
    for(i = 0; i<size; ++i)
    {
        if((i + 1) % 4 == 0)
        {
            array[i-2] =  array[i-2] ^ key;
            array[i] = array[i] ^ key;
        }
    }
}

/*
 * @author harsukh singh
 * @function swap bits function
 * @params array and size of the array 
 * @return void
 */
void swap_bits(unsigned char* array, int size) //swap bits b7 and b3, swap bits b6 and b2
{
    if(!array) return;
    int i;
    for(i = 0; i<size; ++i)
    {
        //printf("%c \n", array[i]);
        unsigned char a = array[i];
        unsigned char b = array[i];
        unsigned char d = array[i];
        a = a << 4;
        b = b >> 4;
        unsigned char c = a|b;
        c = c & 0x33;
        d = d & 0xCC;
        array[i] = (unsigned char) c | d;
        //printf("%c \n", array[i]);
    }
}
