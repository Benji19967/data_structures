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

void test_create_array_of_pointers_null() {
  int *arr[3] = {NULL};
  int *arr2[3] = {NULL, NULL, NULL};
  TEST_ASSERT_EQUAL_INT_ARRAY(arr, arr2, 3);
  TEST_ASSERT_EACH_EQUAL_PTR_MESSAGE(NULL, arr, 3, "Not all pointers are NULL");
}

int main(void) {
  UNITY_BEGIN();

  RUN_TEST(test_declare_array_of_integers);
  RUN_TEST(test_declare_array_of_integers_init_one_value);
  RUN_TEST(test_create_array_of_integers);
  RUN_TEST(test_array_designated_inits);
  RUN_TEST(test_create_array_of_pointers_null);

  UNITY_END();

  return 0;
}
