#include<stdio.h>
#include<stdlib.h>

int OBF_FUNC(int a[],int n,int m,int l,int u){

     int mid,c=0;

     if(l<=u){
          mid=(l+u)/2;
          if(m==a[mid]){
              c=1;
          }
          else if(m<a[mid]){
              return OBF_FUNC(a,n,m,l,mid-1);
          }
          else
              return OBF_FUNC(a,n,m,mid+1,u);
     }
     else
       return c;
}

int main(int argc, char* argv[]){

    if (argc < 12) return 1;
    int a[10],i,m,c,l,u;

    for (i=1;i<argc-1;i++)
        a[i-1] = argv[i][0];

    m = (int) argv[argc-1][0];//35;

    l=0,u=argc-2;
    c=OBF_FUNC(a,argc-1,m,l,u);
    if(c==0)
         printf("Number is not found.\n");
    else
         printf("Number is found.\n");

    return 0;
 }
