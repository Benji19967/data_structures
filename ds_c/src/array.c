#include "array.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void array_print(int arr[], int arr_length) {
  for (int i = 0; i < arr_length; i++) {
    printf("%d: %d\n", i, arr[i]);
  }
}

void array_print_2d(int** arr, int m, int n) {
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      printf("%d ", arr[i][j]);
    }
    printf("\n");
  }
}

int** array_create_2d(int m, int n) {
  int** arr = malloc(m * sizeof(int*));
  for (int i = 0; i < m; i++) {
    arr[i] = malloc(n * sizeof(int));
  }

  return arr;
}

int** array_copy_2d(int** src, int m, int n) {
  int** dst = malloc(m * sizeof(int*));
  for (int i = 0; i < m; i++) {
    dst[i] = malloc(n * sizeof(int));
    memcpy(dst[i], src[i], n * sizeof(int));
  }

  return dst;
}

void array_delete_2d(int** arr, int m, int n) {
  for (int i = 0; i < m; i++) {
    free(arr[i]);
  }
  free(arr);
}
