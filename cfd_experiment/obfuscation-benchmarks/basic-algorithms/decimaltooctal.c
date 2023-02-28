#include<stdio.h>
#include<stdlib.h>

void OBF_FUNC(int n) {
  int octalNumber[100];
  int i = 1;
  int j;

  long int remainder;
  long int quotient;

  quotient = n;
  while(quotient!=0){
      octalNumber[i++]= quotient % 8;
      quotient = quotient / 8;
  }

  printf("Equivalent octal value of decimal number %d: \n",n);
  j = i -1;
  for(;j> 0;) {
    printf("%d",octalNumber[j]);
    j--;
  }
      
}

int main(int argc, char* argv[]){
  return 0;
}
