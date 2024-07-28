#include <stdio.h>
#include <string.h>

// `struct` vs `typedef struct`
// Talks about `tag namespace` vs `ordinary identifier namespace`
// https://stackoverflow.com/questions/612328/difference-between-struct-and-typedef-struct-in-c

// Not using `typedef`, by Linus Torvalds
// https://www.kernel.org/doc/html/latest/process/coding-style.html#typedefs

struct Person {
  int age;
  char name[20];
};

struct Dog {
  int weight;
  char *name;
};

typedef struct Giraffe {
  int height;
  char *name;
} Giraffe;

// int main() {
//   // Person
//   struct Person p1;
//
//   p1.age = 22;
//
//   // does not work: can only assing to string on initialization
//   // p1.name = "Oceane"
//
//   strcpy(p1.name, "Oceane");
//   printf("Age: %d, Name: %s\n", p1.age, p1.name);
//
//   // Dog
//   struct Dog d1;
//
//   d1.weight = 45;
//   d1.name = "Doggo";  // assignment to pointer possible
//   printf("Weight: %d, Name: %s\n", d1.weight, d1.name);
//
//   // Giraffe
//   Giraffe g1;  // no need to use `struct` because of `typedef`
//
//   g1.height = 6;
//   g1.name = "Clara";  // assignment to pointer possible
//   printf("Height: %d, Name: %s\n", g1.height, g1.name);
// }
