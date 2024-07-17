#include "singly_linked_list.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>  // `malloc` and `free`
#include <string.h>

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
