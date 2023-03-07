#include<stdio.h>
#include<stdlib.h>

int OBF_FUNC(int n){
   if(n<=1)
       return 1;
   else
       return(n*OBF_FUNC(n-1));
 }

int main(int argc, char **argv) {
  return (int) OBF_FUNC(atoi(argv[1]));
}