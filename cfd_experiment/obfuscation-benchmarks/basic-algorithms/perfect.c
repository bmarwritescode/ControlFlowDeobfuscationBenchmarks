#include <stdlib.h>

int OBF_FUNC(int n) {
  int i=1;
  int sum=0;
  while(i<n){
      if(n%i==0)
           sum=sum+i;
          i++;
  }
  if(sum==n)
      return 1;
  else
      return 0;
}

int main(int argc, char **argv) {
  return OBF_FUNC(atoi(argv[1]));
}
