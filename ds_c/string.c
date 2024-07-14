#include <stdio.h>
#include <string.h>

int main() {
  char greetings[] = "Hello World!";  // terminated with '\0'
  printf("%s\n", greetings);
  printf("%c\n", greetings[0]);

  greetings[1] = 'u';
  printf("%s\n", greetings);

  char s[20] = "Hello";
  char buffer[7];
  sprintf(buffer, "-> %d", 20);
  strncat(s, buffer, 7);
  puts(s);  // print with a newline
}
