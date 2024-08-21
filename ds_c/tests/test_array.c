#include <stdlib.h>

#include "../src/array.h"
#include "../unity/src/unity.h"

void setUp(void) {
  // set stuff up here
}

void tearDown(void) {
  // clean stuff up here
}

void test_declare_array_of_integers() {
  int arr[3];
  int expected[3] = {0, 0, 0};

  TEST_ASSERT_EQUAL_INT_ARRAY(expected, arr, 3);
}

void test_declare_array_of_integers_init_one_value() {
  int arr[3] = {5};
  int expected[3] = {5, 0, 0};

  TEST_ASSERT_EQUAL_INT_ARRAY(expected, arr, 3);
}

void test_create_array_of_integers() {
  int arr[3] = {5, 5, 5};
  int expected[3] = {5, 5, 5};

  TEST_ASSERT_EQUAL_INT_ARRAY(expected, arr, 3);
}

void test_array_designated_inits() {
  int arr[6] = {[4] = 29, [2] = 15};
  int expected[6] = {0, 0, 15, 0, 29, 0};

  TEST_ASSERT_EQUAL_INT_ARRAY(expected, arr, 6);
}

void test_array_designated_inits_range() {
  // GNU only
  int arr[] = {[1 ... 4] = 37, [7 ... 11] = 43};
  int expected[] = {0, 37, 37, 37, 37, 0, 0, 43, 43, 43, 43, 43};

  TEST_ASSERT_EQUAL_INT_ARRAY(expected, arr, 12);
}

void test_create_array_of_pointers_null() {
  int *arr[3] = {NULL};
  int *arr2[3] = {NULL, NULL, NULL};

  TEST_ASSERT_EQUAL_INT_ARRAY(arr, arr2, 3);
  TEST_ASSERT_EACH_EQUAL_PTR_MESSAGE(NULL, arr, 3, "Not all pointers are NULL");
}

void test_create_2d_array_stack() {
  int arr[2][2] = {{1, 2}, {3, 4}};

  TEST_ASSERT_EQUAL_INT(1, arr[0][0]);
  TEST_ASSERT_EQUAL_INT(2, arr[0][1]);
  TEST_ASSERT_EQUAL_INT(3, arr[1][0]);
  TEST_ASSERT_EQUAL_INT(4, arr[1][1]);
}

void test_create_2d_array_heap() {
  int M = 2;
  int N = 3;
  int(*arr)[N] = malloc(sizeof(int[M][N]));

  arr[0][0] = 1;
  arr[0][1] = 2;
  arr[0][2] = 3;
  arr[1][0] = 4;
  arr[1][1] = 5;
  arr[1][2] = 6;

  TEST_ASSERT_EQUAL_INT(1, arr[0][0]);
  TEST_ASSERT_EQUAL_INT(2, arr[0][1]);
  TEST_ASSERT_EQUAL_INT(3, arr[0][2]);
  TEST_ASSERT_EQUAL_INT(4, arr[1][0]);
  TEST_ASSERT_EQUAL_INT(5, arr[1][1]);
  TEST_ASSERT_EQUAL_INT(6, arr[1][2]);

  free(arr);
}

void test_create_2d_array_from_function() {
  int M = 2;
  int N = 5;
  int **arr = array_create_2d(M, N);

  arr[0][0] = 1;
  arr[0][1] = 2;
  arr[0][2] = 3;
  arr[0][3] = 4;
  arr[0][4] = 5;
  arr[1][0] = 6;
  arr[1][1] = 7;
  arr[1][2] = 8;

  TEST_ASSERT_EQUAL_INT(1, arr[0][0]);
  TEST_ASSERT_EQUAL_INT(2, arr[0][1]);
  TEST_ASSERT_EQUAL_INT(3, arr[0][2]);
  TEST_ASSERT_EQUAL_INT(4, arr[0][3]);
  TEST_ASSERT_EQUAL_INT(5, arr[0][4]);
  TEST_ASSERT_EQUAL_INT(6, arr[1][0]);
  TEST_ASSERT_EQUAL_INT(7, arr[1][1]);
  TEST_ASSERT_EQUAL_INT(8, arr[1][2]);

  array_delete_2d(arr, M, N);
}

void test_copy_2d_array() {
  int M = 2;
  int N = 5;
  int **src = array_create_2d(M, N);

  src[0][0] = 1;
  src[0][1] = 2;
  src[0][2] = 3;
  src[0][3] = 4;
  src[0][4] = 5;
  src[1][0] = 6;
  src[1][1] = 7;
  src[1][2] = 8;

  int **dst = array_copy_2d(src, M, N);

  TEST_ASSERT_EQUAL_INT(1, dst[0][0]);
  TEST_ASSERT_EQUAL_INT(2, dst[0][1]);
  TEST_ASSERT_EQUAL_INT(3, dst[0][2]);
  TEST_ASSERT_EQUAL_INT(4, dst[0][3]);
  TEST_ASSERT_EQUAL_INT(5, dst[0][4]);
  TEST_ASSERT_EQUAL_INT(6, dst[1][0]);
  TEST_ASSERT_EQUAL_INT(7, dst[1][1]);
  TEST_ASSERT_EQUAL_INT(8, dst[1][2]);

  array_delete_2d(src, M, N);
  array_delete_2d(dst, M, N);
}

void test_init_array_2d() {
  int M = 2;
  int N = 5;
  int arr[M][N];

  array_init_2d((int *)arr, M, N, 0);

  for (int i = 0; i < M; i++) {
    for (int j = 0; j < N; j++) {
      TEST_ASSERT_EQUAL_INT(0, arr[i][j]);
    }
  }
}

void test_array_equal_2d() {
  int M = 2;
  int N = 5;

  int **arr1 = array_create_2d(M, N);

  arr1[0][0] = 1;
  arr1[0][1] = 2;
  arr1[0][2] = 3;
  arr1[0][3] = 4;
  arr1[0][4] = 5;
  arr1[1][0] = 6;
  arr1[1][1] = 7;
  arr1[1][2] = 8;
  arr1[1][3] = 9;
  arr1[1][4] = 10;

  int **arr2 = array_copy_2d(arr1, M, N);

  TEST_ASSERT_EQUAL_INT(1, array_is_equal_2d(arr1, arr2, M, N));

  arr2[0][4] = 21;
  TEST_ASSERT_EQUAL_INT(0, array_is_equal_2d(arr1, arr2, M, N));
}

int main(void) {
  UNITY_BEGIN();

  RUN_TEST(test_declare_array_of_integers);
  RUN_TEST(test_declare_array_of_integers_init_one_value);
  RUN_TEST(test_create_array_of_integers);
  RUN_TEST(test_array_designated_inits);
  RUN_TEST(test_array_designated_inits_range);
  RUN_TEST(test_create_array_of_pointers_null);
  RUN_TEST(test_create_2d_array_stack);
  RUN_TEST(test_create_2d_array_heap);
  RUN_TEST(test_create_2d_array_from_function);
  RUN_TEST(test_copy_2d_array);
  RUN_TEST(test_init_array_2d);
  RUN_TEST(test_array_equal_2d);

  UNITY_END();

  return 0;
}
