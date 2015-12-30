#include "stdio.h"

unsigned int array_toint(char* to_read);

int main(int argc, char** argv)
{
    char s[8];
    unsigned int num;
    while(scanf("%s", s) == 1)
    {
        printf("%s\n", s);
        num = array_toint(s); 
        printf("%u\n", num);
    }
    return 0;

}

unsigned int array_toint(char* to_read)
{
    if(!to_read) return 0;
    int num = strlen(to_read);
    int i;
    for(i = 0; i<num; ++i)
    {
        to_read[i] = tolower(to_read[i]);
    }
    return (unsigned) (int) strtol(to_read, NULL, 16);
}


