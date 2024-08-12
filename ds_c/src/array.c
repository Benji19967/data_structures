#include "array.h"

#include <stdio.h>
#include <stdlib.h>

void print_array(int arr[], int arr_length) {
  for (int i = 0; i < arr_length; i++) {
    printf("%d: %d\n", i, arr[i]);
  }
}

int** create_2d_array(int m, int n) {
  int M = 2;
  int N = 3;
  int** arr = malloc(M * sizeof(int*));
  for (int i = 0; i < M; i++) {
    arr[i] = malloc(N);
  }

  arr[0][0] = 1;
  arr[0][1] = 2;
  arr[0][2] = 3;
  arr[1][0] = 4;
  arr[1][1] = 5;
  arr[1][2] = 6;

  return arr;
}
