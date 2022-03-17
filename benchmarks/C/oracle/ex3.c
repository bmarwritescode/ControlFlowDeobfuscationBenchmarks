// NOTE: ¬ is bitwise negation?

/* multiply45(int y) */
/* { */
/*   z = y << 2; y = z + y; */
/*   z = y << 3; y = z + y; return y; */
/* } */

int multiply45Obs(int y)
{
  a=1; b=0; z=1; c=0;
  while(1) {
    if (a == 0) {
     if (b == 0) {
       y=z+y; a=~a;
       b=~b;c=~c;
       if (~c) break;
     } else {
       z=z+y; a=~a; b=~b; c=~c;
       if (~c) break;
     }
    } else if(b == 0) {
      z=y << 2;
      a=~a;
    } else {
      z=y << 3; a=~a; b=~b;
    }
  }
  return y;
}
