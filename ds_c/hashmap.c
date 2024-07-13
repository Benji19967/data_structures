#include "singly_linked_list.h"
#include "stdlib.h"

// Hashmap

// Collision handling
//
// 1. Linked list for each bucket

// Hashing Function
//
// 1. For integers: value modulo <number of buckets>

// Compiling/linking with the singly_linked_list implementation
// cc -Wall hashmap.c singly_linked_list.c -o a.out

#define NUM_BUCKETS 1000
#define NUM_VALUES 100000

int hash(long value) {
  return value % NUM_BUCKETS;
}

int main() {
  Node *buckets[NUM_BUCKETS] = {NULL};

  for (int i = 0; i < NUM_VALUES; i++) {
    int random_value = rand();
    int hashed_value = hash(random_value);
    if (buckets[hashed_value] == NULL) {
      Node *head = (Node *)malloc(sizeof(Node));
      buckets[hashed_value] = head;
    }
    push(buckets[hashed_value], random_value);
  }

  print_linked_list(buckets[1]);
}
