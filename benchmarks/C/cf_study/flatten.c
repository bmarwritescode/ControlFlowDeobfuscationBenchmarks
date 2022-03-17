// void foo() {
//     int arr[5] = {2, 3, 4, 10, 40};
//     for (int i=0; i < 5 ; i++) {
//         printf("%d\n",arr[i]);
//     }
// }

void foo() {
  int var =2;
  while (var != 0) {
    switch (var) {
    case 1:
      for (int i =0; i < 5 ; i++) {
        printf("%d\n",arr[i]);
      }
      var = 0;
      break;
    case 2:
      int arr[5] = {2, 3, 4, 10, 40};
      var = 1;
      break;
    default : break;
    }
  }
}
