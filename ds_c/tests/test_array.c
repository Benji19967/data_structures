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
}

void test_create_2d_array_from_function() {
  int **arr = create_2d_array(2, 3);

  TEST_ASSERT_EQUAL_INT(1, arr[0][0]);
  TEST_ASSERT_EQUAL_INT(2, arr[0][1]);
  TEST_ASSERT_EQUAL_INT(3, arr[0][2]);
  TEST_ASSERT_EQUAL_INT(4, arr[1][0]);
  TEST_ASSERT_EQUAL_INT(5, arr[1][1]);
  TEST_ASSERT_EQUAL_INT(6, arr[1][2]);
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

  UNITY_END();

  return 0;
}
