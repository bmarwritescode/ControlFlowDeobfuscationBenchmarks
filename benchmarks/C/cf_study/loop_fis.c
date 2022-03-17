/* void foo(int[] arr, int len) { */
/*   for (int i=1; i < len; i++) { */
/*     printf("%d\n", arr[i]); */
/*   } */
/* } */

void foo(int[] arr, int len) {
  for (int i=1; i < len/2; i++) {
    printf("%d\n", arr[i]);
  }
  for (int i=len/2; i < len; i++) {
    printf("%d\n", arr[i]);
  }
}
