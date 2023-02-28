#include<stdio.h>
#include<stdlib.h>

// Seq(?[P], Seq(While(SourceGuard(i >= 0), Seq(?[P], Seq(While(SourceGuard(j <= i), Seq(If(SourceGuard(a[j] > a[j + 1]), ?[P]), ?[P])), ?[P]))), Seq(?[P], Seq(While(SourceGuard(i < n), ?[P]), ?[P]))))
int* OBF_FUNC(int a[],int n){
  int temp;
  int i = n-2;

  while (i >= 0) {

    int j = 0;
    while (j <= i) {

      if (a[j] > a[j+1]) {
        temp = a[j];
        a[j] = a[j+1];
        a[j+1] = temp;
      }
      j++;
    }
    i--;
  }

  i = 0;
  while (i < n) {
    printf("%d ",a[i]);
    i++;
  }

  return a;
}
int main(int argc, char* argv[]){

  // int temp,i,j,a[10];

  // for(i=1;i<argc;i++){
  //     a[i-1] = argv[i][0];
  // }
  
  // OBF_FUNC(a,argc-1);

  return 0;
}


