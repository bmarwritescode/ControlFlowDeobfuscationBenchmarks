#include <stdlib.h>

int OBF_FUNC(int i) {
  return i;
}

int main(int argc, char **argv) {
  return OBF_FUNC(atoi(argv[1]));
}
