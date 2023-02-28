#include<stdio.h>
#include<stdlib.h>

void OBF_FUNC(int a[], int n) {
  int i = 0;
  int temp;
  for(;i<n;){
    int j = i + 1;
      for(;j<n;){
           if(a[i]>a[j]){
               temp=a[i];
              a[i]=a[j];
              a[j]=temp;
           }
           j++;
      }
      i++;
  }

  printf("After sorting is: ");
  i=0;
  for(;i<n;) {
      printf(" %d",a[i]);
      i++;
  }

  printf("\n");
}

int main(int argc, char* argv[]){
 
  return 0;
}
