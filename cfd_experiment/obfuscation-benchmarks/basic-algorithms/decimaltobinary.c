#include<stdio.h>
#include<stdlib.h>

void OBF_FUNC(int n) {
    int binaryNumber[100];
    int i = 1;
    int j;

    long int quotient;

    long int decimal = n;
    quotient = decimal;
    while (quotient != 0) {
        binaryNumber[i] = quotient % 2;
        quotient = quotient / 2;
        i++;
    }

    printf("Equivalent binary value of decimal number %d: \n", decimal);

    j = i -1;
    for( ;j> 0;) {
        printf("%d",binaryNumber[j]);
        j--;
    }
}

int main(int argc, char* argv[]){

    return 0;

}

