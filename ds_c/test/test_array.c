#include "../unity/src/unity.h"

void setUp(void) {
  // set stuff up here
}

void tearDown(void) {
  // clean stuff up here
}

void test_add() {
  int output = 10 + 20;
  TEST_ASSERT_EQUAL(30, output);
}

void test_subtract() {
  int output = 10 - 20;
  TEST_ASSERT_EQUAL(-8, output);
}

int main(void) {
  UNITY_BEGIN();

  RUN_TEST(test_add);
  RUN_TEST(test_subtract);

  UNITY_END();

  return 0;
}
