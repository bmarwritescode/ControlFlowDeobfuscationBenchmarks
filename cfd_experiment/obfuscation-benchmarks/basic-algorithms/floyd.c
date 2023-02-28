#include <stdio.h>
#include <stdlib.h>

void OBF_FUNC(int n) {
  int a = 0;
  int i = 1;
  for (; i <= n;)
  {
    int c = 1;
    for (; c <= i;)
    {
      printf("%d ",a);
      a++;
      c++;
    }
    printf("\n");
    i++;
  }
}
 
int main(int argc, char* argv[])
{
  return 0;
}
