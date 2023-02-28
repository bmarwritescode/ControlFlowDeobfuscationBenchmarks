#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void OBF_FUNC(int rows)
{
    int i;
    int j;

    i = 1;
    for(;i<=rows;)
    {
        j = 1;
        for(;j<=i;)
        {
           printf("* ");
           ++j;
        }
        printf("\n");
        ++i;
    }
}

int main(int argc, char* argv[])
{
    return 0;
}
