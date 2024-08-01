#include "hashmap.h"

#include <stdbool.h>
#include <stdio.h>

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

// int hash(long value) {
//   return value % NUM_BUCKETS;
// }

Hashmap *hashmap_new(int num_buckets) {
  Hashmap *map = malloc(num_buckets * sizeof(Node *));
  map->num_elements = 0;
  map->num_buckets = num_buckets;
  for (int i = 0; i < num_buckets; i++) {
    map->buckets[i] = NULL;
  }
  return map;
}

// void Hashmap_init(Hashmap *map) {
//   for (int i = 0; i < NUM_BUCKETS; i++) {
//     map->buckets[i] = NULL;
//   }
// }
//
// void Hashmap_insert(Hashmap *map, int key, int value) {
//   int hashed_key = hash(key);
//   if (map->buckets[hashed_key] == NULL) {
//     Node *head = (Node *)malloc(sizeof(Node));
//     map->buckets[hashed_key] = head;
//   }
//   sll_push(map->buckets[hashed_key], key, value);
// }
//
// Node *Hashmap_get(Hashmap *map, int key) {
//   int hashed_key = hash(key);
//   Node *key_node = sll_contains_key(map->buckets[hashed_key], key);
//   if (key_node != NULL) {
//     return key_node;
//   }
//   return NULL;
// }

// int main() {
//   sll_print(buckets[0]);
//   sll_print_one_line(buckets[0]);
// }
