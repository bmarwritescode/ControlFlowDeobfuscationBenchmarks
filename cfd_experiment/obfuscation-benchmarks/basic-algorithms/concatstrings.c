#include<stdio.h>
#include<stdlib.h>

void OBF_FUNC(char str1[],char str2[]){
    int i=0;
    int j=0;
   
   
    while(str1[i]!='\0'){
         i++;
    }

    while(str2[j]!='\0'){
         str1[i] = str2[j];   
         i++;
         j++;
    }

    str1[i] = '\0';
    printf("String after concatenation: %s\n",str1);
}

int main(int argc, char* argv[]){
    if (argc < 2) {
        return 1;
    }
    int compare;

    char* str1 = argv[1];
    char* str2 = argv[2];
    OBF_FUNC(str1,str2);

    return 0;
}


