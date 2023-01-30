#include <stdlib.h>

int OBF_FUNC(int n) {
   int a = 1;
   int b = 1;
   int i;
   for (i = 3; i <= n; i++) {
      int c = a + b;
      a = b;
      b = c;
   };
   return b;
}

int main(int argc, char **argv) {
  return OBF_FUNC(atoi(argv[1]));
}

