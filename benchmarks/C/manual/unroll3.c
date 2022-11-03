#include <stdlib.h>
#include <stdbool.h>

int OBF_FUNC(int i) {
  if (i <= 0) {
    return -1;
  }

  int m = i;
  while (m > 1) {
    if (m > 1) {
      bool isPrime = true;
      int j = 2;
      while (j < m && isPrime) {
        if (j < m && isPrime) {
          int k = 2;
          while (k < m && isPrime) {
            if (k < m && isPrime) {
              if (m == j*k) {
                isPrime = false;
              }
              k++;
            }
            if (k < m && isPrime) {
              if (m == j*k) {
                isPrime = false;
              }
              k++;
            }
            if (k < m && isPrime) {
              if (m == j*k) {
                isPrime = false;
              }
              k++;
            }
          }
          j++;
        }
        if (j < m && isPrime) {
          int k = 2;
          while (k < m && isPrime) {
            if (k < m && isPrime) {
              if (m == j*k) {
                isPrime = false;
              }
              k++;
            }
            if (k < m && isPrime) {
              if (m == j*k) {
                isPrime = false;
              }
              k++;
            }
            if (k < m && isPrime) {
              if (m == j*k) {
                isPrime = false;
              }
              k++;
            }
          }
          j++;
        }
        if (j < m && isPrime) {
          int k = 2;
          while (k < m && isPrime) {
            if (k < m && isPrime) {
              if (m == j*k) {
                isPrime = false;
              }
              k++;
            }
            if (k < m && isPrime) {
              if (m == j*k) {
                isPrime = false;
              }
              k++;
            }
            if (k < m && isPrime) {
              if (m == j*k) {
                isPrime = false;
              }
              k++;
            }
          }
          j++;
        }
      }
      if (isPrime) {
        return m;
      }
      m--;
    }
    if (m > 1) {
      bool isPrime = true;
      int j = 2;
      while (j < m && isPrime) {
        if (j < m && isPrime) {
          int k = 2;
          while (k < m && isPrime) {
            if (k < m && isPrime) {
              if (m == j*k) {
                isPrime = false;
              }
              k++;
            }
            if (k < m && isPrime) {
              if (m == j*k) {
                isPrime = false;
              }
              k++;
            }
            if (k < m && isPrime) {
              if (m == j*k) {
                isPrime = false;
              }
              k++;
            }
          }
          j++;
        }
        if (j < m && isPrime) {
          int k = 2;
          while (k < m && isPrime) {
            if (k < m && isPrime) {
              if (m == j*k) {
                isPrime = false;
              }
              k++;
            }
            if (k < m && isPrime) {
              if (m == j*k) {
                isPrime = false;
              }
              k++;
            }
            if (k < m && isPrime) {
              if (m == j*k) {
                isPrime = false;
              }
              k++;
            }
          }
          j++;
        }
        if (j < m && isPrime) {
          int k = 2;
          while (k < m && isPrime) {
            if (k < m && isPrime) {
              if (m == j*k) {
                isPrime = false;
              }
              k++;
            }
            if (k < m && isPrime) {
              if (m == j*k) {
                isPrime = false;
              }
              k++;
            }
            if (k < m && isPrime) {
              if (m == j*k) {
                isPrime = false;
              }
              k++;
            }
          }
          j++;
        }
      }
      if (isPrime) {
        return m;
      }
      m--;
    }
    if (m > 1) {
      bool isPrime = true;
      int j = 2;
      while (j < m && isPrime) {
        if (j < m && isPrime) {
          int k = 2;
          while (k < m && isPrime) {
            if (k < m && isPrime) {
              if (m == j*k) {
                isPrime = false;
              }
              k++;
            }
            if (k < m && isPrime) {
              if (m == j*k) {
                isPrime = false;
              }
              k++;
            }
            if (k < m && isPrime) {
              if (m == j*k) {
                isPrime = false;
              }
              k++;
            }
          }
          j++;
        }
        if (j < m && isPrime) {
          int k = 2;
          while (k < m && isPrime) {
            if (k < m && isPrime) {
              if (m == j*k) {
                isPrime = false;
              }
              k++;
            }
            if (k < m && isPrime) {
              if (m == j*k) {
                isPrime = false;
              }
              k++;
            }
            if (k < m && isPrime) {
              if (m == j*k) {
                isPrime = false;
              }
              k++;
            }
          }
          j++;
        }
        if (j < m && isPrime) {
          int k = 2;
          while (k < m && isPrime) {
            if (k < m && isPrime) {
              if (m == j*k) {
                isPrime = false;
              }
              k++;
            }
            if (k < m && isPrime) {
              if (m == j*k) {
                isPrime = false;
              }
              k++;
            }
            if (k < m && isPrime) {
              if (m == j*k) {
                isPrime = false;
              }
              k++;
            }
          }
          j++;
        }
      }
      if (isPrime) {
        return m;
      }
      m--;
    }
  }

  return -1;
}

int main(int argc, char **argv) {
  return OBF_FUNC(atoi(argv[1]));
}
