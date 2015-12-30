#include <stdio.h>

#define N 15
/*
 * 
 */
int array_max(int a[], int n);
int main()
{
  int data[N] = {7,8,9,23,55, 67,88, 9789,54, 545,34, 2, 133, 6, 7};
  int max = array_max(data, N);
  printf("max = %i", max);
  return 0;
}

int array_max(int a[], int n)
{
  int tail_max, max;
  printf("val = %2i , head = %2i \n", a[0], n); 
  //base case
  if(n==1)
  {
    max = a[0];
  }
  else 
  {
    tail_max = array_max(&a[1], n-1);
    if(a[0]> tail_max)
    {
      max = a[0];
    }
    else{
      max = tail_max;
     }
  }
  printf("head =%2i n=%2i returning = %2i \n",n,a[0],max);
  return max; 
}
