#include<stdio.h>
#include<stdlib.h>

void OBF_FUNC(int n){
    int i=0;
    int j;
    int digit;
    char * word[1000];

    while (n) {
        digit = n % 10;
        n = n / 10;

        switch (digit) {
            case 0:
                word[i++] = "zero";
                break;
            case 1:
                word[i++] = "one";
                break;
            case 2:
                word[i++] = "two";
                break;
            case 3:
                word[i++] = "three";
                break;
            case 4:
                word[i++] = "four";
                break;
            case 5:
                word[i++] = "five";
                break;
            case 6:
                word[i++] = "six";
                break;
            case 7:
                word[i++] = "seven";
                break;
            case 8:
                word[i++] = "eight";
                break;
            case 9:
                word[i++] = "nine";
                break;
        }
    }

    j=i-1;
    for(;j>=0;){
         printf("%s ",word[j]);
         j--;
    }
    printf("\n");
}


int main(int argc, char* argv[]){

    return 0;

}
