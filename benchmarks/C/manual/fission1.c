#include <stdlib.h>

int OBF_FUNC(int i) {
  int sum = 0;
  int k = 0;
  while (k <= i) {
    sum += k;
    k++;
    if (k <= i/2) {
      break;
    }
  }
  while (k <= i) {
    sum += k;
    k++;
  }
  return sum;
}

int main(int argc, char **argv) {
  return OBF_FUNC(atoi(argv[1]));
}
