#include <stdlib.h>

int OBF_FUNC(int i) {
  int sum = 0;
  int k = 0;
  while (k <= i) {
    if (k <= i) {
      sum += k;
      k++;
    }
    if (k <= i) {
      sum += k;
      k++;
    }
    if (k <= i) {
      sum += k;
      k++;
    }
    if (k <= i) {
      sum += k;
      k++;
    }
    if (k <= i) {
      sum += k;
      k++;
    }
  }
  return sum;
}

int main(int argc, char **argv) {
  return OBF_FUNC(atoi(argv[1]));
}
