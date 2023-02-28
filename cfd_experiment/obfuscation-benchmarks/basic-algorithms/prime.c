/* C program to check whether a number is prime or not. */

#include <stdlib.h>

int OBF_FUNC(int n)
{
  int i=2;
  int flag=0;
  while(i<=n/2)
  {
      if(n%i==0)
      {
          flag=1;
          break;
      }
      i++;
  }
  if (flag==0)
      return 1;
  else
      return 0;
}

int main(int argc, char **argv) {
  return OBF_FUNC(atoi(argv[1]));
}
