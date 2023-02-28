#include<stdio.h>
#include<stdlib.h>

int OBF_FUNC(int a[], int n, int m) {
    int i;
    int c = 0;
    i = 0;
    for (; i < n; ) {
        if (a[i] == m) {
            c = 1;
            break;
        }
        i++;
    }
    if(c==0)
         printf("The number is not in the list\n");
    else
         printf("The number is found\n");
    return c;
}

int main(int argc, char* argv[]){
    if (argc < 12) return 1;
    int a[10],i,m,c=0;

    for(i=1;i<argc-1;i++)
        a[i-1] = argv[i][0];
    m = argv[argc-1][0];

    for(i=0;i<=argc-2;i++){
         if(a[i]==m){
             c=1;
             break;
         }
    }
    if(c==0)
         printf("The number is not in the list\n");
    else
         printf("The number is found\n");

    return 0;
}
