/* C program to check whether a number is palindrome or not */

#include <stdlib.h>

int OBF_FUNC(int n)
{
  int reverse=0;
  int rem;
  int temp;
  temp=n;
  while(temp!=0)
  {
     rem=temp%10;
     reverse=reverse*10+rem;
     temp/=10;
  }
  if(reverse==n)
      return 1;
  else
      return 0;
}

int main(int argc, char **argv) {
  return OBF_FUNC(atoi(argv[1]));
}
