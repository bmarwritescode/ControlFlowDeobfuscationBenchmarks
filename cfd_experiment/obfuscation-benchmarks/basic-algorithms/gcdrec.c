#include<stdio.h>
#include<stdlib.h>

int OBF_FUNC(int x,int y){
     while(x!=y){
          if(x>y)
              return OBF_FUNC(x-y,y);
          else
             return OBF_FUNC(x,y-x);
     }
     return x;
}

int main(int argc, char **argv) {
  return OBF_FUNC(atoi(argv[1]), atoi(argv[2]));
}


