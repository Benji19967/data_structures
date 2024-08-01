#include "singly_linked_list.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>  // `malloc` and `free`
#include <string.h>
#include <time.h>

// `foo->x` is syntactic sugar for (*foo).x

int num_digits(unsigned int num) {
  int num_digits = 1;

  while (num > 9) {
    num_digits++;
    num /= 10;
  }

  return num_digits;
}

void sll_print(Node *curr) {
  while (curr->next != NULL) {
    printf("(Key / Value): (%d / %d), Next (Key / Value): (%d / %d)\n",
           curr->key, curr->value, curr->next->key, curr->next->value);
    curr = curr->next;
  }
  printf("Value: %d\n", curr->value);
}

void append_node_to_string(char *s, Node *curr, bool last) {
  size_t nbytes = num_digits(curr->key) + num_digits(curr->value) + 5;
  char *buffer = malloc(nbytes);
  if (last) {
    sprintf(buffer, "%d/%d", curr->key, curr->value);
  } else {
    sprintf(buffer, "%d/%d -> ", curr->key, curr->value);
  }
  strncat(s, buffer, nbytes);
  free(buffer);
}

void sll_print_one_line(Node *curr) {
  // TODO: Maybe start with little memory and increase it exponentially when
  // more is needed
  char *s = malloc(1000);

  while (curr->next != NULL) {
    append_node_to_string(s, curr, false);
    curr = curr->next;
  }
  append_node_to_string(s, curr, true);
  puts(s);

  free(s);
}

void sll_push(Node *head, int key, int val) {
  Node *new_node = (Node *)malloc(sizeof(Node));
  new_node->key = key;
  new_node->value = val;
  new_node->next = NULL;

  Node *curr = head;
  while (curr->next != NULL) {
    curr = curr->next;
  }
  curr->next = new_node;
}

Node *sll_contains_key(Node *head, int key) {
  if (head == NULL) {
    return NULL;
  }
  if (head->key == key) {
    return head;
  }
  Node *curr = head;
  while (curr->next != NULL) {
    curr = curr->next;
    if (curr->key == key) {
      return curr;
    }
  }
  return NULL;
}

/*
Peek at the last element of the linked list
*/
Node *sll_peek(Node *head) {
  Node *curr = head;
  while (curr->next != NULL) {
    curr = curr->next;
  }
  return curr;
}

/*
 * Create new node
 */
Node *sll_new_node() {
  Node *node = malloc(sizeof(Node));

  node->key = 0;
  node->value = 0;
  node->next = NULL;

  return node;
}

/*
 * Create new node with initial kv values
 */
Node *sll_new_node_kv(int key, int value) {
  Node *node = malloc(sizeof(Node));

  node->key = key;
  node->value = value;
  node->next = NULL;

  return node;
}

/*
 * Create new node on the stack
 */
Node sll_new_node_stack() {
  Node node;

  node.key = 0;
  node.value = 0;
  node.next = NULL;

  return node;
}

/*
 * Push node at the end of the linked list
 */
void sll_push_node(Node *head, Node *node) {
  Node *curr = head;
  while (curr->next != NULL) {
    curr = curr->next;
  }
  curr->next = node;
}

/*
 * This causes a segmentation fault when trying to iterate the linked list after
 * this function has returned. `node` is passed by value to the function, and
 * hence copied. When the function returns, `node` is destroyed as part of the
 * stack frame of the function. Also, `head` is a copy of the passed head node,
 * hence `head->next`, where `head` is the node that is passed to the function,
 * is never set.
 */
void sll_push_node_stack(Node head, Node node) {
  // This would ultimately cause a SEGMENTATION FAULT

  // Node curr = head;
  // while (curr.next != NULL) {
  //   curr = *curr.next;
  // }
  // curr.next = &node;
}

/*
 * Append after node.
 */
void sll_append_after_node(Node *to_append_to, Node *node) {
  Node *following = to_append_to->next;
  to_append_to->next = node;
  node->next = following;
}

/*
 * Delete node.
 *
 * Returns pointer to (new) head, as the head could be the node that gets
 * deleted.
 */
Node *sll_delete_node(Node *head, Node *node_to_delete) {
  if (head == node_to_delete) {
    Node *new_head = head->next;
    free(head);
    return new_head;
  }

  Node *prev = head;
  Node *curr = head;
  while (curr != node_to_delete && curr != NULL) {
    curr = curr->next;
    if (curr == node_to_delete) {
      prev->next = curr->next;
      free(node_to_delete);
      return head;
    }
    prev = curr;
  }
  // node_to_delete not found
  return head;
}

/*
 * Find node by key.
 */
Node *sll_find_by_key(Node *head, int key) {
  Node *curr = head;
  while (curr != NULL) {
    if (curr->key == key) {
      return curr;
    }
    curr = curr->next;
  }
  return NULL;
}

// int main() {
//   Node *head = NULL;
//   Node *prev = (Node *)malloc(sizeof(Node));
//   prev->value = -1;
//   prev->next = NULL;
//   head = prev;
//
//   for (int i = 0; i < 10; i++) {
//     Node *curr = (Node *)malloc(sizeof(Node));
//     curr->value = i;
//     curr->next = NULL;
//     prev->next = curr;
//     prev = curr;
//   }
//
//   push(head, 10);
//
//   print_linked_list(head);
//   printf("Peek: %d\n", peek(head));
// }
