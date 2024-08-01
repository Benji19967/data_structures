#include <stdio.h>
#include <stdlib.h>

#include "../src/hashmap.h"
#include "../unity/src/unity.h"

void setUp(void) {
  // set stuff up here
}

void tearDown(void) {
  // clean stuff up here
}

void test_new_hashmap() {
  int num_buckets = 1000;
  Hashmap* map = hashmap_new(num_buckets);

  TEST_ASSERT_EQUAL_INT(0, map->num_elements);
  TEST_ASSERT_EQUAL_INT(num_buckets, map->num_buckets);
  TEST_ASSERT_EACH_EQUAL_PTR(NULL, map->buckets, num_buckets);
}

void test_hash_function() {
  int num_buckets = 1000;

  int key1 = 999;
  int hashed_key1 = hashmap_hash(key1, num_buckets);
  TEST_ASSERT_EQUAL_INT(999, hashed_key1);

  int key2 = 1000;
  int hashed_key2 = hashmap_hash(key2, num_buckets);
  TEST_ASSERT_EQUAL_INT(0, hashed_key2);
}

void test_hashmap_insert() {
  int num_buckets = 10;
  Hashmap* map = hashmap_new(num_buckets);

  hashmap_insert(map, 5, 6);
  hashmap_insert(map, 17, 18);
  hashmap_insert(map, 27, 28);

  TEST_ASSERT_EQUAL_INT(3, map->num_elements);
  TEST_ASSERT_EQUAL_INT(num_buckets, map->num_buckets);

  TEST_ASSERT_EQUAL_INT(5, map->buckets[5]->key);
  TEST_ASSERT_EQUAL_INT(6, map->buckets[5]->value);
  TEST_ASSERT_EQUAL_PTR(NULL, map->buckets[5]->next);

  TEST_ASSERT_EQUAL_INT(17, map->buckets[7]->key);
  TEST_ASSERT_EQUAL_INT(18, map->buckets[7]->value);
  TEST_ASSERT_EQUAL_INT(27, map->buckets[7]->next->key);
  TEST_ASSERT_EQUAL_INT(28, map->buckets[7]->next->value);
  TEST_ASSERT_EQUAL_PTR(NULL, map->buckets[7]->next->next);
}

void test_hashmap_find() {
  int num_buckets = 10;
  Hashmap* map = hashmap_new(num_buckets);

  hashmap_insert(map, 5, 6);
  hashmap_insert(map, 17, 18);
  hashmap_insert(map, 27, 28);

  HashmapKV* kv1 = hashmap_get(map, 5);
  HashmapKV* kv2 = hashmap_get(map, 17);
  HashmapKV* kv3 = hashmap_get(map, 27);
  HashmapKV* kvNotFound = hashmap_get(map, 99);

  TEST_ASSERT_EQUAL_INT(5, kv1->key);
  TEST_ASSERT_EQUAL_INT(6, kv1->value);
  TEST_ASSERT_EQUAL_INT(17, kv2->key);
  TEST_ASSERT_EQUAL_INT(18, kv2->value);
  TEST_ASSERT_EQUAL_INT(27, kv3->key);
  TEST_ASSERT_EQUAL_INT(28, kv3->value);
  TEST_ASSERT_EQUAL_PTR(NULL, kvNotFound);

  free(kv1);
  free(kv2);
  free(kv3);
}

int main(void) {
  UNITY_BEGIN();

  RUN_TEST(test_new_hashmap);
  RUN_TEST(test_hash_function);
  RUN_TEST(test_hashmap_insert);
  RUN_TEST(test_hashmap_find);

  UNITY_END();

  return 0;
}
