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
#define NUM_VALUES 1000

int hash(long value) {
  return value % NUM_BUCKETS;
}

typedef struct Pair {
  int value_1;
  int value_2;
} Pair;

// Pair two_sum(int nums[], int num_elements, int target) {
//   Pair result;
//   Hashmap *seen;
//   for (int i = 0; i < num_elements; i++) {
//     int complement = target - nums[i];
//     int element = Hashmap_contains(seen, complement);
//     if (value) {
//       return Pair_new(i, element.index);
//     }
//     Hashmap_insert(seen, nums[i]);
//   }
//   return Pair_new(NULL, NULL);
// }

int main() {
  Node *buckets[NUM_BUCKETS] = {NULL};

  for (int i = 0; i < NUM_VALUES; i++) {
    int random_value = rand();
    int hashed_value = hash(random_value);
    if (buckets[hashed_value] == NULL) {
      Node *head = (Node *)malloc(sizeof(Node));
      buckets[hashed_value] = head;
    }
    sll_push(buckets[hashed_value], random_value);
  }

  // sll_print(buckets[0]);
  sll_print_one_line(buckets[0]);
}
