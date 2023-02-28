#include <stdio.h>
#include <stdlib.h>

void OBF_FUNC(char *c, char ch)
{
    int i = 0;
    int count = 0;
    for (; c[i] != '\0';)
    {
        if (ch == c[i])
            ++count;
        i++;
    }

    printf("Frequency of %c = %d", ch, count++);
}

void OBF_FUNC1(char *c, char ch)
{
    OBF_FUNC(c, ch);
    return;
}

int main(int argc, char *argv[])
{
    return 0;
}
