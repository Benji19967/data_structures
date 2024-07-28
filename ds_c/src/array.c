#include <stdio.h>

#define N 10

void print_array(int arr[], int arr_length) {
  for (int i = 0; i < arr_length; i++) {
    printf("%d: %d\n", i, arr[i]);
  }
}

// int main() {
//   int arr[N] = {0};
//   int arr_length = sizeof(arr) / sizeof(arr[0]);
//
//   print_array(arr, arr_length);
// }
