#include <stdlib.h>
#include<stdlib.h>

int OBF_FUNC(int x) {
  int n;
  int n1;
  int rem;
  int num=0;
  n = x;
  n1=n;
  while(n1!=0)
  {
      rem=n1%10;
      num+=rem*rem*rem;
      n1/=10;
  }
  if(num==n)
    return 1;
  else
    return 0;
}

int main(int argc, char **argv) {
  return OBF_FUNC(atoi(argv[1]));
}
