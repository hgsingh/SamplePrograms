#include "stdio.h"

int main(int argc, char** argv)
{
    unsigned int  num;
    int count;
    while(scanf("%x", &num) == 1 || scanf("0x%x", &num) == 1)
    {
        printf("%u\n", num);
        ++count;
    }
    printf("%d", count);
    return 0;
}
