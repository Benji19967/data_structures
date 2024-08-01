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

int main(void) {
  UNITY_BEGIN();

  RUN_TEST(test_new_hashmap);

  UNITY_END();

  return 0;
}
