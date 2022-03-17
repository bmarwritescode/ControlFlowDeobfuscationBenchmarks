// int foo(int x, int m, int[] arr) {
//     if (arr[m] == x) return m+1;
// }

int foo(int x, int m, int[] arr) {
  bool bool;
  int redop = 1;
  if (arr[m] == x && ! bool) {
    if (bool) {
      /* deadcode */
      return 0;
    }
    return (m+1) * redop ;
  }
}
