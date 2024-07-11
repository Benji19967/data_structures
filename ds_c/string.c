#include <stdio.h>

int main() {
  char greetings[] = "Hello World!";  // terminated with '\0'
  printf("%s\n", greetings);
  printf("%c\n", greetings[0]);

  greetings[1] = 'u';
  printf("%s\n", greetings);
}
