public void foo(int[] arr) {
    for (int i=1; i < arr.length; i++) {
        System.out.println(arr[i]);
    }
}

public void foo(int[] arr) {
    for (int i=1; i < arr.length/2; i++) {
        System.out.println(arr[i]);
    }
    for (int i=arr.length/2; i < arr.length; i++) {
        System.out.println(arr[i]);
    }
}
