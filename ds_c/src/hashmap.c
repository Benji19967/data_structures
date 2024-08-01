#include "hashmap.h"

#include <stdbool.h>
#include <stdio.h>
#include <time.h>

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
//
void hashmap_print(Hashmap *map, int num_buckets) {
  for (int i = 0; i < num_buckets; i++) {
    if (map->buckets[i] != NULL) {
      printf("%d: ", i);
      sll_print_one_line(map->buckets[i]);
    }
  }
}

Hashmap *hashmap_new(int num_buckets) {
  Hashmap *map = malloc(num_buckets * sizeof(Node *));
  map->num_elements = 0;
  map->num_buckets = num_buckets;
  for (int i = 0; i < num_buckets; i++) {
    map->buckets[i] = NULL;
  }
  return map;
}

int hashmap_hash(int key, int num_buckets) {
  return key % num_buckets;
}

Node *hashmap_insert(Hashmap *map, int key, int value) {
  int hashed_key = hashmap_hash(key, map->num_buckets);
  Node *node = sll_new_node_kv(key, value);
  if (map->buckets[hashed_key] == NULL) {
    map->buckets[hashed_key] = node;
  } else {
    sll_push_node(map->buckets[hashed_key], node);
  }
  map->num_elements++;
  return node;
}

HashmapKV *hashmap_find(Hashmap *map, int key) {
  int hashed_key = hashmap_hash(key, map->num_buckets);
  Node *node = sll_find_by_key(map->buckets[hashed_key], key);
  if (node != NULL) {
    HashmapKV *kv = malloc(sizeof(HashmapKV));
    kv->key = node->key;
    kv->value = node->value;
    return kv;
  }
  return NULL;
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
