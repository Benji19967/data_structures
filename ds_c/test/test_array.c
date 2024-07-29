#include "../unity/src/unity.h"

void setUp(void) {
  // set stuff up here
}

void tearDown(void) {
  // clean stuff up here
}

void test_create_array_of_pointers() {
  int *arr[3] = {NULL};
  int *arr2[3] = {NULL, NULL, NULL};
  TEST_ASSERT_EQUAL_INT_ARRAY(arr, arr2, 3);
  TEST_ASSERT_EACH_EQUAL_PTR_MESSAGE(NULL, arr, 3, "Not all pointers are NULL");
}

int main(void) {
  UNITY_BEGIN();

  RUN_TEST(test_create_array_of_pointers);

  UNITY_END();

  return 0;
}
