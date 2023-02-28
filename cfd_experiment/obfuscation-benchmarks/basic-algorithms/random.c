#include <stdio.h>
#include <stdlib.h>

void OBF_FUNC(int x) {
  int c;
  int n;
  
  printf("%d random numbers in [1,100]\n", x);
  c = 1;
  for (; c <= x;) {
    n = rand() % 100 + 1;
    printf("%d\n", n);
    c++;
  }
}
 
int main(int argc, char* argv[]) {
      OBF_FUNC(atoi(argv[1]));
  return 0;
}
