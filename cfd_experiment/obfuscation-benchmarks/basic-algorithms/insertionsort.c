#include<stdio.h>
#include<stdlib.h>

void OBF_FUNC(int a[],int n){
  int i;
  int j;
  int s=10;
  i=1;
  for(;i<s;){
      int temp=a[i];
      j=i-1;
      while((temp<a[j])&&(j>=0)){
      a[j+1]=a[j];
          j=j-1;
      }
      a[j+1]=temp;
      i++;
  }

  printf("After sorting: ");
  i=0;
  for(;i<s;) {
    printf(" %d", a[i]);
      i++;
  }

}


int main(int argc, char* argv[]){
  int a[10] = { 10, 9, 7, 101, 23, 44, 12, 78, 34, 23 };
  OBF_FUNC(a,10);
  return 0;
}
