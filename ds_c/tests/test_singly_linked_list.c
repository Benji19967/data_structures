#include "../src/singly_linked_list.h"
#include "../unity/src/unity.h"

void setUp(void) {
  // set stuff up here
}

void tearDown(void) {
  // clean stuff up here
}

void test_create_node() {
  Node *node = sll_new_node();
  TEST_ASSERT_EQUAL_INT(0, node->key);
  TEST_ASSERT_EQUAL_INT(0, node->value);
  TEST_ASSERT_EQUAL_PTR(NULL, node->next);
}

int main(void) {
  UNITY_BEGIN();

  RUN_TEST(test_create_node);

  UNITY_END();

  return 0;
}
