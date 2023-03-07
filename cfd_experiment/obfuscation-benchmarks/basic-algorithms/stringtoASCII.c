#include<stdio.h>
#include<stdlib.h>

void OBF_FUNC(char str[]) {
    int i=0;

    printf("ASCII values of each characters of given string: ");
    while(str[i] != '\0' && str[i] != 0xff) {
        printf("%d ",str[i++]);
    }

    printf("\n");
}

int main(int argc, char* argv[]){
    return 0;
}
