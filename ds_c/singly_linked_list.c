#include <stdio.h>
#include <stdlib.h>  // `malloc` and `free`

// `foo->x` is syntactic sugar for (*foo).x

typedef struct Node {
  int value;
  struct Node *next;
} Node;

void print_linked_list(Node *curr) {
  while (curr->next != NULL) {
    printf("Value: %d, Next value: %d\n", curr->value, curr->next->value);
    curr = curr->next;
  }
  printf("Value: %d\n", curr->value);
}

int main() {
  Node *head = NULL;
  Node *prev = (Node *)malloc(sizeof(Node));
  prev->value = -1;
  prev->next = NULL;
  head = prev;

  for (int i = 0; i < 10; i++) {
    Node *curr = (Node *)malloc(sizeof(Node));
    curr->value = i;
    curr->next = NULL;
    prev->next = curr;
    prev = curr;
  }

  print_linked_list(head);
}
