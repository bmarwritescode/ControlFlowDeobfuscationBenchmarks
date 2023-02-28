#include<stdio.h>
#include<stdlib.h>

void OBF_FUNC(int a[], int n) {
  int big=a[0];
  int small=a[0];
  int i=1;
  for(;i<n;){
      if(big<a[i]) {
        big=a[i];
      }
      i++;
  }
  printf("Largest element: %d\n",big);
 
  
  i=1;
  for(;i<n;){
      if(small>a[i]) {
        small=a[i];
      }
      i++;
  }
  printf("Smallest element: %d\n",small);
}

int main(int argc, char* argv[]){
  return 0;
}
