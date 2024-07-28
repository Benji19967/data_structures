// TODO: Move this to a different location / repo (maybe `algorithms`)

#include <stdio.h>
#include <stdlib.h>  // malloc and free, atoi

#include "hashmap.h"

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

/*
 * Return indexes of 2 elements that sum up to target, if found.
 */
Pair two_sum(int nums[], int num_elements, int target) {
  // TODO: Is this correct (the right amount to allocate)?
  Hashmap *seen = malloc(NUM_BUCKETS * sizeof(Node *));
  // Hashmap *seen; // Explain why this leads to a segfault.
  Hashmap_init(seen);

  for (int i = 0; i < num_elements; i++) {
    int complement = target - nums[i];
    Node *element = Hashmap_get(seen, complement);
    if (element != NULL) {
      return Pair_new(i, element->value);
    }
    Hashmap_insert(seen, nums[i], i);
  }
  free(seen);
  return Pair_new(-1, -1);
}

int main(int argc, char *argv[]) {
  // TWO SUM
  int nums[argc];
  int target = atoi(argv[1]);

  // argv[0] is the program name
  for (int i = 2; i < argc; i++) {
    nums[i - 2] = atoi(argv[i]);
  }

  int num_elements = sizeof(nums) / sizeof(nums[0]);
  Pair result = two_sum(nums, num_elements, target);
  if (result.value_1 == -1) {
    printf("No solution found\n");
    return 0;
  }
  int idx_1 = result.value_1;
  int idx_2 = result.value_2;
  printf("Target: %d\n", target);
  printf("Values: (%d, %d)\n", nums[idx_1], nums[idx_2]);
  printf("Indexes: (%d, %d)\n", idx_1, idx_2);
}
