#include <stdbool.h>
#include <stdio.h>

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
  printf("%d\n", -99);
  for (int i = 0; i < NUM_BUCKETS; i++) {
    printf("%d", -98);
    map->buckets[i] = NULL;
  }
}

void Hashmap_insert(Hashmap *map, int key, int value) {
  int hashed_key = hash(key);
  if (map->buckets[hashed_key] == NULL) {
    Node *head = (Node *)malloc(sizeof(Node));
    map->buckets[hashed_key] = head;
  }
  sll_push(map->buckets[hashed_key], key, value);
}

Node *Hashmap_get(Hashmap *map, int key) {
  int hashed_key = hash(key);
  Node *key_node = sll_contains_key(map->buckets[hashed_key], key);
  if (key_node != NULL) {
    return key_node;
  }
  return NULL;
}

/*
 * Return indexes of 2 elements that sum up to target, if found.
 */
Pair two_sum(int nums[], int num_elements, int target) {
  printf("%d", 0);
  // Hashmap *seen = malloc(NUM_BUCKETS * sizeof(Node *));
  Hashmap *seen;
  Hashmap_init(seen);

  printf("%d", 1);
  for (int i = 0; i < num_elements; i++) {
    int complement = target - nums[i];
    printf("%d", 2);
    Node *element = Hashmap_get(seen, complement);
    printf("%d", 3);
    if (element != NULL) {
      printf("%d", 4);
      return Pair_new(i, element->value);
      printf("%d", 5);
    }
    Hashmap_insert(seen, nums[i], i);
    printf("%d", 6);
  }
  free(seen);
  return Pair_new(-1, -1);
}

int main() {
  // TWO SUM
  printf("%d\n", sizeof(Node *));
  int nums[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  Pair result = two_sum(nums, sizeof(nums), 17);
  printf("(%d, %d)", result.value_1, result.value_2);

  // Hashmap *map;
  // Hashmap_init(map);
  //
  // for (int i = 0; i < NUM_VALUES; i++) {
  //   int random_value = rand();
  //   int hashed_value = hash(random_value);
  // }

  // sll_print(buckets[0]);
  // sll_print_one_line(buckets[0]);
}
