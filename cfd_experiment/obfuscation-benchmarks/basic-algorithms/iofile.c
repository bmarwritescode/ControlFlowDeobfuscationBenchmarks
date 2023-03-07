#include <stdio.h>
#include <stdlib.h>  /* For exit() function */
#include <time.h>

void OBF_FUNC(char *str)
{
   FILE *rfile;
   FILE *wfile;
   wfile=fopen("iofile_temp_output.txt","w");
   if(wfile==NULL){
      printf("Error!");
      exit(1);
   }

   fprintf(wfile,"%s",str);
   fclose(wfile);
   // Now read the content again. Yes, I know. :)
   rfile = fopen("iofile_temp_output.txt","r");
   if(rfile==NULL){
       printf("Error!");
       exit(1);
   }
   char ch = fgetc(rfile);
   while(ch != 0xff){
      printf("%c", ch);
      ch = fgetc(rfile);
   }
   printf("\n");
   fclose(rfile);
}


int main(int argc, char* argv[])
{
   if (argc < 2)
      return 1;
   char* c=argv[1];//[25]="glrpvpkxdvhisgkmudwyknbai";

   OBF_FUNC(c);
   
   return 0;
}


