#include <stdlib.h>

int OBF_FUNC(int n) {
  int r;
  int reverse=0;
  while(n){
       r=n%10;
       reverse=reverse*10+r;
       n=n/10;
  }
  return reverse;
}

int main(int argc, char **argv) {
  return OBF_FUNC(atoi(argv[1]));
}
