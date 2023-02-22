#include<stdio.h>
#include<stdlib.h>

void OBF_FUNC(int a[],int n){
  int temp,i,j;
  for(i=n-2;i>=0;i--){
      for(j=0;j<=i;j++){
           if(a[j]>a[j+1]){
               temp=a[j];
              a[j]=a[j+1];
              a[j+1]=temp;
           }
      }
  }
}
int main(int argc, char* argv[]){

  int temp,i,j,a[10];

  for(i=1;i<argc;i++){
      a[i-1] = argv[i][0];
  }
  
  OBF_FUNC(a,argc-1);

  for(i=0;i<argc-1;i++)
      printf(" %d",a[i]);

  return 0;
}


