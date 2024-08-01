#include "../src/singly_linked_list.h"
#include "../unity/src/unity.h"

void setUp(void) {
  // set stuff up here
}

void tearDown(void) {
  // clean stuff up here
}

void test_new_node() {
  Node *node = sll_new_node();

  TEST_ASSERT_EQUAL_INT(0, node->key);
  TEST_ASSERT_EQUAL_INT(0, node->value);
  TEST_ASSERT_EQUAL_PTR(NULL, node->next);
}

void test_new_node_stack() {
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

// Works, BUT: need to be somewhat careful with this.
// The nodes will not exist anymore once this function returns.
// I.e. you could not return `head` and then pass it to another function to
// print the linked list.
// ALSO: you could run out of stack space for large lists or when running on
// low-memory devices
void test_push_node_stack() {
  Node head = sll_new_node_stack();
  Node new_node = sll_new_node_stack();
  new_node.key = 1;
  new_node.value = 1;

  sll_push_node(&head, &new_node);

  TEST_ASSERT_EQUAL_INT(0, head.key);
  TEST_ASSERT_EQUAL_INT(0, head.value);

  TEST_ASSERT_EQUAL_INT(1, head.next->key);
  TEST_ASSERT_EQUAL_INT(1, head.next->value);
  TEST_ASSERT_EQUAL_PTR(NULL, head.next->next);
  TEST_ASSERT_EQUAL_PTR(&new_node, head.next);
}

void test_append_after_node() {
  Node *head = sll_new_node();
  Node *new_node_1 = sll_new_node();
  Node *new_node_2 = sll_new_node();
  new_node_1->value = 1;
  new_node_1->key = 1;
  new_node_2->value = 2;
  new_node_2->key = 2;

  sll_push_node(head, new_node_1);
  sll_append_after_node(head, new_node_2);

  TEST_ASSERT_EQUAL_INT(0, head->key);
  TEST_ASSERT_EQUAL_INT(0, head->value);

  TEST_ASSERT_EQUAL_INT(2, head->next->key);
  TEST_ASSERT_EQUAL_INT(2, head->next->value);
  TEST_ASSERT_EQUAL_INT(1, head->next->next->key);
  TEST_ASSERT_EQUAL_INT(1, head->next->next->value);
  TEST_ASSERT_EQUAL_PTR(new_node_2, head->next);
  TEST_ASSERT_EQUAL_PTR(new_node_1, head->next->next);
  TEST_ASSERT_EQUAL_PTR(NULL, head->next->next->next);
}

void test_delete_head_alone() {
  Node *head = sll_new_node();

  Node *new_head = sll_delete_node(head, head);

  TEST_ASSERT_EQUAL_PTR(NULL, new_head);
}

void test_delete_head() {
  Node *head = sll_new_node();
  Node *new_node_1 = sll_new_node();
  new_node_1->value = 1;
  new_node_1->key = 1;

  sll_push_node(head, new_node_1);
  Node *new_head = sll_delete_node(head, head);

  TEST_ASSERT_EQUAL_PTR(new_node_1, new_head);
}

void test_delete_last_node() {
  Node *head = sll_new_node();
  Node *new_node_1 = sll_new_node();
  Node *new_node_2 = sll_new_node();
  new_node_1->value = 1;
  new_node_1->key = 1;
  new_node_2->value = 2;
  new_node_2->key = 2;

  sll_push_node(head, new_node_1);
  sll_push_node(head, new_node_2);
  Node *new_head = sll_delete_node(head, new_node_2);

  TEST_ASSERT_EQUAL_INT(0, head->key);
  TEST_ASSERT_EQUAL_INT(0, head->value);

  TEST_ASSERT_EQUAL_INT(1, head->next->key);
  TEST_ASSERT_EQUAL_INT(1, head->next->value);
  TEST_ASSERT_EQUAL_PTR(NULL, head->next->next);
  TEST_ASSERT_EQUAL_PTR(head, new_head);
}

void test_delete_middle_node() {
  Node *head = sll_new_node();
  Node *new_node_1 = sll_new_node();
  Node *new_node_2 = sll_new_node();
  new_node_1->value = 1;
  new_node_1->key = 1;
  new_node_2->value = 2;
  new_node_2->key = 2;

  sll_push_node(head, new_node_1);
  sll_push_node(head, new_node_2);
  Node *new_head = sll_delete_node(head, new_node_1);

  TEST_ASSERT_EQUAL_INT(0, head->key);
  TEST_ASSERT_EQUAL_INT(0, head->value);

  TEST_ASSERT_EQUAL_INT(2, head->next->key);
  TEST_ASSERT_EQUAL_INT(2, head->next->value);
  TEST_ASSERT_EQUAL_PTR(NULL, head->next->next);
  TEST_ASSERT_EQUAL_PTR(head, new_head);
}

void test_find_by_key() {
  Node *head = sll_new_node();
  Node *new_node_1 = sll_new_node();
  Node *new_node_2 = sll_new_node();
  new_node_1->value = 1;
  new_node_1->key = 1;
  new_node_2->value = 2;
  new_node_2->key = 2;

  sll_push_node(head, new_node_1);
  sll_push_node(head, new_node_2);

  Node *node0 = sll_find_by_key(head, 0);
  TEST_ASSERT_EQUAL_PTR(head, node0);

  Node *node1 = sll_find_by_key(head, 1);
  TEST_ASSERT_EQUAL_PTR(new_node_1, node1);

  Node *node2 = sll_find_by_key(head, 2);
  TEST_ASSERT_EQUAL_PTR(new_node_2, node2);

  Node *node3 = sll_find_by_key(head, 3);
  TEST_ASSERT_EQUAL_PTR(NULL, node3);
}

int main(void) {
  UNITY_BEGIN();

  RUN_TEST(test_new_node);
  RUN_TEST(test_new_node_stack);
  RUN_TEST(test_push_node);
  RUN_TEST(test_push_node_stack);
  RUN_TEST(test_append_after_node);
  RUN_TEST(test_delete_head_alone);
  RUN_TEST(test_delete_head);
  RUN_TEST(test_delete_last_node);
  RUN_TEST(test_delete_middle_node);
  RUN_TEST(test_find_by_key);

  UNITY_END();

  return 0;
}
