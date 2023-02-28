#include <stdio.h>
#include <stdlib.h>

int OBF_FUNC(char a[], char b[])
{
   int first[26] = {0};
   int second[26] = {0};
   int c = 0;
 
   while (a[c] != '\0')
   {
      first[a[c]-'a']++;
      c++;
   }
 
   c = 0;
 
   while (b[c] != '\0')
   {
      second[b[c]-'a']++;
      c++;
   }
   
   c = 0;
   while (c < 26)
   {
      if (first[c] != second[c])
         return 0;
      c++;
   }
 
   return 1;
}
 
int main(int argc, char* argv[])
{
   // Check the number of passed arguments
   if(argc < 3) {
      return 1;
   }
      
   char* a = argv[1];
   char* b = argv[2];
   int flag;
 
   flag = OBF_FUNC(a, b);
 
   if (flag == 1)
      printf("\"%s\" and \"%s\" are anagrams.\n", a, b);
   else
      printf("\"%s\" and \"%s\" are not anagrams.\n", a, b);
 
   return 0;
}
