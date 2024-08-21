#include <stdbool.h>

void array_print(int arr[], int arr_length);
void array_print_2d(int** arr, int m, int n);
int** array_create_2d(int m, int n);
void array_init_2d(int* arr, int m, int n, int initial_value);
int** array_copy_2d(int** src, int m, int n);
void array_delete_2d(int** arr, int m, int n);
bool array_is_equal_2d(int** arr1, int** arr2, int m, int n);
