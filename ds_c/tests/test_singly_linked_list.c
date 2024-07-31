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

void test_create_node_stack() {
  Node node = sll_new_node_stack();

  TEST_ASSERT_EQUAL_INT(0, node.key);
  TEST_ASSERT_EQUAL_INT(0, node.value);
  TEST_ASSERT_EQUAL_PTR(NULL, node.next);
}

void test_push_node() {
  Node *head = sll_new_node();
  Node *new_node = sll_new_node();
  new_node->value = 1;
  new_node->key = 1;

  sll_push_node(head, new_node);

  TEST_ASSERT_EQUAL_INT(0, head->key);
  TEST_ASSERT_EQUAL_INT(0, head->value);

  TEST_ASSERT_EQUAL_INT(1, head->next->key);
  TEST_ASSERT_EQUAL_INT(1, head->next->value);
  TEST_ASSERT_EQUAL_PTR(NULL, head->next->next);
  TEST_ASSERT_EQUAL_PTR(new_node, head->next);
}

void test_push_node_stack() {
  Node head = sll_new_node_stack();
  Node new_node = sll_new_node_stack();
  new_node.value = 1;
  new_node.key = 1;

  sll_push_node(&head, &new_node);

  TEST_ASSERT_EQUAL_INT(0, head.key);
  TEST_ASSERT_EQUAL_INT(0, head.value);

  TEST_ASSERT_EQUAL_INT(1, head.next->key);
  TEST_ASSERT_EQUAL_INT(1, head.next->value);
  TEST_ASSERT_EQUAL_PTR(NULL, head.next->next);
  TEST_ASSERT_EQUAL_PTR(&new_node, head.next);
}

int main(void) {
  UNITY_BEGIN();

  RUN_TEST(test_create_node);
  RUN_TEST(test_create_node_stack);
  RUN_TEST(test_push_node);
  RUN_TEST(test_push_node_stack);

  UNITY_END();

  return 0;
}
