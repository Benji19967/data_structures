#include "hashmap.h"

#include <stdbool.h>
#include <stdio.h>
#include <time.h>

#include "stdlib.h"

/*
 * Collision handling
 * -> Linked list for each bucket
 *
 * Hashing Function
 * -> For integers: value modulo <number of buckets>
 */

/*
 * Create new Hashmap.
 */
Hashmap *hashmap_new(int num_buckets) {
  Hashmap *map = malloc(num_buckets * sizeof(Node *));
  map->num_elements = 0;
  map->num_buckets = num_buckets;
  for (int i = 0; i < num_buckets; i++) {
    map->buckets[i] = NULL;
  }
  return map;
}

/*
 * Insert key-value pair in Hashmap
 *
 * TODO: Typically, if a key that already exists in the Hashmap gets inserted,
 * the newer value should be used. This is not the case here.
 */
void hashmap_insert(Hashmap *map, int key, int value) {
  int hashed_key = hashmap_hash(key, map->num_buckets);
  Node *node = sll_new_node_kv(key, value);
  if (map->buckets[hashed_key] == NULL) {
    map->buckets[hashed_key] = node;
  } else {
    sll_push_node(map->buckets[hashed_key], node);
  }
  map->num_elements++;
}

/*
 * Given a key, get a key-value pair from Hashmap.
 *
 * If key is not present, return NULL.
 */
HashmapKV *hashmap_get(Hashmap *map, int key) {
  int hashed_key = hashmap_hash(key, map->num_buckets);
  Node *node = sll_find_by_key(map->buckets[hashed_key], key);
  if (node != NULL) {
    // If you don't malloc, `kv` gets reused and overwritten on every call to
    // `hashmap_find`
    HashmapKV *kv = malloc(sizeof(HashmapKV));
    kv->key = node->key;
    kv->value = node->value;
    return kv;
  }
  return NULL;
}

int hashmap_hash(int key, int num_buckets) {
  return key % num_buckets;
}

void hashmap_print(Hashmap *map, int num_buckets) {
  for (int i = 0; i < num_buckets; i++) {
    if (map->buckets[i] != NULL) {
      printf("%d: ", i);
      sll_print_one_line(map->buckets[i]);
    }
  }
}
