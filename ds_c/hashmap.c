#include <stdbool.h>

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

Pair Pair_new(int value_1, int value_2) {
  Pair pair;
  pair.value_1 = value_1;
  pair.value_2 = value_2;
  return pair;
}

typedef struct Hashmap {
  Node *buckets[NUM_BUCKETS];
} Hashmap;

void Hashmap_init(Hashmap *map) {
  for (int i = 0; i < NUM_BUCKETS; i++) {
    map->buckets[i] = NULL;
  }
}

void Hashmap_insert(Hashmap *map, int key, int value) {
  int hashed_key = hash(key);
  if (map->buckets[hashed_key] == NULL) {
    Node *head = (Node *)malloc(sizeof(Node));
    map->buckets[hashed_key] = head;
  }
  sll_push(map->buckets[hashed_key], value);
}

int Hashmap_contains(Hashmap *map, int key) {
  int hashed_key = hash(key);
  bool contains_key = sll_contains(map->buckets[hashed_key], key);
  if (contains_key) {
  }
}

// int Hashmap_get(Hashmap *map, int key) {
//   int hashed_key = hash(key);
// }

Pair two_sum(int nums[], int num_elements, int target) {
  Pair result;
  Hashmap *seen;
  for (int i = 0; i < num_elements; i++) {
    int complement = target - nums[i];
    int element = Hashmap_contains(seen, complement);
    if (value) {
      return Pair_new(i, element.index);
    }
    Hashmap_insert(seen, nums[i]);
  }
  return Pair_new(NULL, NULL);
}

int main() {
  Hashmap *map;
  Hashmap_init(map);

  for (int i = 0; i < NUM_VALUES; i++) {
    int random_value = rand();
    int hashed_value = hash(random_value);
  }

  // sll_print(buckets[0]);
  sll_print_one_line(buckets[0]);
}
