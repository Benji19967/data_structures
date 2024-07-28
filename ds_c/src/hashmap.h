#include "singly_linked_list.h"

#define NUM_BUCKETS 1000

typedef struct Hashmap {
  Node *buckets[NUM_BUCKETS];
} Hashmap;

void Hashmap_init(Hashmap *map);
void Hashmap_insert(Hashmap *map, int key, int value);
Node *Hashmap_get(Hashmap *map, int key);
