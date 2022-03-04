/* genString(int input) */
/* { */
/*   if(input == 0) return "EHLO"; */
/*   else if (input == 1) return "RCPT TO"; */
/*   else if (input == 2) return "MAIL FROM"; */
/*   else if (input == 3) return "DATA"; */
/*   else return NULL; */
/* } */

genStringObs(int input)
{
  a1=1, a2=0; b1=1, b2=0; c1=0; c2=0;
  if (input == 0)
    { a1 = 0; a2 = 0; b1=0; b2 = 0; }
  else if (input == 1)
    { c1=0; c2 = 1; }
  else if (input == 2)
    { a1 =1; a2 = 0; c1=1; c2=1; }
  else if (input == 3)
    { b1 = 0; b2 = 0; c1=1; c2=1; }
  else return NULL;
  c = 2*c1 + c2;
  if(c == 1) { return rot13("EPCG GB, 7"); }
  else
    if (c == 2) {
      if (input * (input-1) % 2 == 0)
        return rot13("EPCG GB", 7);
      else
        return rot13("RUYB", 4);
      }
  else {
      if (b1 ⊕ b2) return rot13("ZNVY SEBZ",9)
                     else if ((a1 ⊕ a2) = (b1 ⊕ b2))
                       return rot13("RUYB", 4);
      else return rot13("QNGN", 4);
  }
}

rot13(char *buf, int sz)
{
  char *buf1 = malloc((sz+1) * sizeof(char));
  char a;
  while (a =~ *buf)
    {
      *buf1 = (~a-1/(~((a | 32))/13*2-11)*13);
      buf++; buf1++;
    }
  return buf1;
}
