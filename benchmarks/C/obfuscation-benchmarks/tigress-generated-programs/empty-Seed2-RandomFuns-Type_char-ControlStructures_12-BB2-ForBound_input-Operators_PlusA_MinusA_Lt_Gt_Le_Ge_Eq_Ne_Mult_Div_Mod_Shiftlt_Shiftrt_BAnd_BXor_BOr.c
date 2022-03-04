/* Generated by CIL v. 1.7.0 */
/* print_CIL_Input is false */

struct _IO_FILE;
struct timeval;
extern float strtof(char const   *str , char const   *endptr ) ;
extern void signal(int sig , void *func ) ;
typedef struct _IO_FILE FILE;
extern int atoi(char const   *s ) ;
extern double strtod(char const   *str , char const   *endptr ) ;
extern int fclose(void *stream ) ;
extern void *fopen(char const   *filename , char const   *mode ) ;
extern void abort() ;
extern void exit(int status ) ;
extern int raise(int sig ) ;
extern int fprintf(struct _IO_FILE *stream , char const   *format  , ...) ;
extern int strcmp(char const   *a , char const   *b ) ;
extern int rand() ;
extern unsigned long strtoul(char const   *str , char const   *endptr , int base ) ;
void RandomFunc(unsigned char input[1] , unsigned char output[1] ) ;
extern int strncmp(char const   *s1 , char const   *s2 , unsigned long maxlen ) ;
extern int gettimeofday(struct timeval *tv , void *tz  , ...) ;
extern int printf(char const   *format  , ...) ;
int main(int argc , char *argv[] ) ;
void megaInit(void) ;
extern unsigned long strlen(char const   *s ) ;
extern long strtol(char const   *str , char const   *endptr , int base ) ;
extern unsigned long strnlen(char const   *s , unsigned long maxlen ) ;
extern void *memcpy(void *s1 , void const   *s2 , unsigned long size ) ;
struct timeval {
   long tv_sec ;
   long tv_usec ;
};
extern void *malloc(unsigned long size ) ;
extern int scanf(char const   *format  , ...) ;
void megaInit(void) 
{ 


  {

}
}
int main(int argc , char *argv[] ) 
{ 
  unsigned char input[1] ;
  unsigned char output[1] ;
  int randomFuns_i5 ;
  unsigned char randomFuns_value6 ;
  int randomFuns_main_i7 ;

  {
  megaInit();
  if (argc != 2) {
    printf("Call this program with %i arguments\n", 1);
    exit(-1);
  } else {

  }
  randomFuns_i5 = 0;
  while (randomFuns_i5 < 1) {
    randomFuns_value6 = (unsigned char )strtoul(argv[randomFuns_i5 + 1], 0, 10);
    input[randomFuns_i5] = randomFuns_value6;
    randomFuns_i5 ++;
  }
  RandomFunc(input, output);
  if (output[0] == (unsigned char)42) {
    printf("You win!\n");
  } else {

  }
  randomFuns_main_i7 = 0;
  while (randomFuns_main_i7 < 1) {
    printf("%u\n", output[randomFuns_main_i7]);
    randomFuns_main_i7 ++;
  }
}
}
void RandomFunc(unsigned char input[1] , unsigned char output[1] ) 
{ 
  unsigned char state[1] ;
  unsigned char local1 ;

  {
  state[0UL] = input[0UL] + (unsigned char)219;
  local1 = 0UL;
  while (local1 < input[1UL]) {
    if (state[0UL] == local1) {
      if (state[0UL] < local1) {
        state[local1] = state[0UL] + state[local1];
        state[0UL] |= (state[local1] & (unsigned char)31) << 4UL;
      } else {
        state[local1] |= (state[local1] & (unsigned char)15) << 2UL;
        state[0UL] |= ((state[local1] | state[0UL]) & (unsigned char)63) << 4UL;
      }
    } else {
      state[0UL] <<= ((state[0UL] >> (unsigned char)2) & (unsigned char)7) | 1UL;
      state[0UL] = (state[local1] >> (((state[0UL] >> (unsigned char)1) & (unsigned char)15) | 1UL)) | (state[local1] << (8 - (((state[0UL] >> (unsigned char)1) & (unsigned char)15) | 1UL)));
    }
    local1 ++;
  }
  output[0UL] = (state[0UL] - 774950844UL) + (360314520UL >> (unsigned char)253);
}
}
