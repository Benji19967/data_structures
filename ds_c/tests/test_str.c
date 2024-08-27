#include "../src/str.h"
#include "../unity/src/unity.h"

void setUp(void) {
  // set stuff up here
}

void tearDown(void) {
  // clean stuff up here
}

void test_string_n_times_char() {
  char* s = string_n_times_char(" ", 3);

  TEST_ASSERT_EQUAL_CHAR(' ', s[0]);
  TEST_ASSERT_EQUAL_CHAR(' ', s[1]);
  TEST_ASSERT_EQUAL_CHAR(' ', s[2]);
  TEST_ASSERT_EQUAL_CHAR('\0', s[3]);

  char* s1 = string_n_times_char("x", 2);

  TEST_ASSERT_EQUAL_CHAR('x', s1[0]);
  TEST_ASSERT_EQUAL_CHAR('x', s1[1]);
  TEST_ASSERT_EQUAL_CHAR('\0', s1[2]);
}

int main(void) {
  UNITY_BEGIN();

  RUN_TEST(test_string_n_times_char);

  UNITY_END();

  return 0;
}
