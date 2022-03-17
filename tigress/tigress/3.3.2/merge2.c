#include "tigress.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fac(int n) {
  int s=1;
  int i;
  for (i=2; i<=n; i++) {
    s *= i;
  }
  printf("fac(%i)=%i\n",n,s);
}

int main (int argc, char** argv) {
  fac(1);
  fib(1);
  fac(5);
  fib(5);
  fac(10);
  fib(10);
  return 0;
}
