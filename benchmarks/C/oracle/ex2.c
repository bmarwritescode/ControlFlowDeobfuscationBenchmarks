// NOTE: I don't know what the operator is, nor the implementation of IPaddress
/* interchange(IPaddress* src, IPadress* dest) */
/*   { */
/*     *dest = *src ⊕ *dest; */
/*     *src = *src ⊕ *dest; */
/*     *dest = *src ⊕ *dest; */
/*     return; */
/*   } */

interchangeObs(IPaddress* src, IPadress* dest)
{
  *src = *src ⊕ *dest;
  if (*src == *src ⊕ *dest) { *src = *src ⊕ *dest;
    if (*src == *src ⊕ *dest) { *dest = *src ⊕ *dest;
      if (*dest == *src ⊕ *dest) { *src = *dest ⊕ *src;
        return;
      } else {
        *src = *src ⊕ *dest; *dest = *src ⊕ *dest;
        return;
      }
    } else {
      *src = *src ⊕ *dest;
    }
    *dest = *src ⊕ *dest; *src = *src ⊕ *dest;
    return;
  }
