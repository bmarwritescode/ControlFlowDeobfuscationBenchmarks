#include<stdio.h>
#include<stdlib.h>

void OBF_FUNC(char* str) {
   int i=0;
   printf("%c",str[0]);
   while(str[i]!='\0'){
       if(str[i]==' '){
         i++;
            printf("%c",str[i]);
       }
       i++;
   }
   printf("\n");
}

int main(int argc, char* argv[]){
   OBF_FUNC("Hello World");
   return 0;
}
