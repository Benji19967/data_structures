#include <string.h>

#include "../unity/src/unity.h"

void setUp(void) {
  // set stuff up here
}

void tearDown(void) {
  // clean stuff up here
}

typedef struct Person {
  int age;
  char *name;
} Person;

typedef struct Person2 {
  int age;
  char name[10];
} Person2;

void test_struct_create() {
  Person p;
  TEST_ASSERT_EQUAL(0, p.age);
  TEST_ASSERT_EQUAL(NULL, p.name);
}

void test_struct_create_2() {
  Person2 p2;
  TEST_ASSERT_NOT_EQUAL_INT(0, p2.age);  // random int on the stack
  TEST_ASSERT_NOT_EQUAL(NULL, p2.name);  // random address on the stack
}

void test_struct_assign() {
  Person p;
  p.age = 10;
  p.name = "Johnny";
  TEST_ASSERT_EQUAL(10, p.age);
  TEST_ASSERT_EQUAL("Johnny", p.name);
}

void test_struct_assign_2() {
  Person2 p2;
  p2.age = 12;
  strcpy(p2.name, "Sandy");
  TEST_ASSERT_EQUAL(12, p2.age);
  TEST_ASSERT_EQUAL_STRING("Sandy", p2.name);
}

int main(void) {
  UNITY_BEGIN();

  RUN_TEST(test_struct_create);
  RUN_TEST(test_struct_create_2);
  RUN_TEST(test_struct_assign);
  RUN_TEST(test_struct_assign_2);

  UNITY_END();

  return 0;
}
