#include<stdio.h>
#include<stdlib.h>

void OBF_FUNC(int x[10],int first,int last){
    int pivot;
    int j;
    int temp;
    int i;

     if(first<last){
         pivot=first;
         i=first;
         j=last;

         while(i<j){
             while(x[i]<=x[pivot]&&i<last)
                 i++;
             while(x[j]>x[pivot])
                 j--;
             if(i<j){
                 temp=x[i];
                  x[i]=x[j];
                  x[j]=temp;
             }
         }

         temp=x[pivot];
         x[pivot]=x[j];
         x[j]=temp;
         OBF_FUNC(x,first,j-1);
         OBF_FUNC(x,j+1,last);

    }
}

int main(int argc, char* argv[]){
  if (argc < 11)
    return 1;
  int x[10];
  int i;

  i=1;
  for (;i<argc;) {
    x[i-1] = argv[i][0];
    i++;
  }

  OBF_FUNC(x,0,argc-2);

  printf("Sorted elements: ");
  i=0;
  for(;i<argc-2;) {
    printf(" %d",x[i]);
    i++;
  }
  return 0;
}
