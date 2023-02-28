#include<stdio.h>
#include<stdlib.h>

void OBF_FUNC(int n) {
    char hexadecimalNumber[100];
    int i = 1;
    int j;
    int temp;

    long int remainder;
    long int quotient;

    quotient = n;
    while(quotient!=0){
         temp = quotient % 16;

      //To convert integer into character
      if( temp < 10)
           temp =temp + 48;
      else
         temp = temp + 55;

      hexadecimalNumber[i++]= temp;
      quotient = quotient / 16;
  }

    printf("Equivalent hexadecimal value of decimal number %d: \n",n);
    j = i -1;
    for(;j> 0;) {
      printf("%c",hexadecimalNumber[j]);
      j--;
    }
        
    return;
}

int main(int argc, char* argv[]){
    return 0;
}
