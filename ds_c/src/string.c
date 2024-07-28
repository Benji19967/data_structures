#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * Notes on flushing (when printing to stdout):
 * https://stackoverflow.com/questions/1716296/why-does-printf-not-flush-after-the-call-unless-a-newline-is-in-the-format-strin
 *
 * 1. The `stdout` stream is line buffered by default
 *
 */

// int main() {
//   /*
//    * Section 1
//    */
//
//   char greetings[] = "Hello World!";  // terminated with '\0'
//   printf("%s\n", greetings);
//   printf("%c\n", greetings[0]);
//
//   greetings[1] = 'u';
//   printf("%s\n", greetings);
//
//   /*
//    * Section 2
//    *
//    * sprintf: need to know buffer size in advance
//    *
//    */
//   // When converted to char[], takes up 3 bytes: '1', '1', '1'
//   int value_1 = 111;
//
//   char *buffer_1 = malloc(7);  // '-', '>', ' ', '1', '1', '1', '\0'
//
//   // A terminating null character is automatically appended after the
//   content.
//   // On success, the total number of characters written is returned.
//   // This count does not include the additional null-character automatically
//   // appended at the end of the string.
//   size_t nbytes_1 = sprintf(buffer_1, "-> %d", value_1) + 1;  // +1 for the
//   '\0' printf("nbytes_sprintf: %ld\n", nbytes_1);
//
//   /*
//    * Section 3
//    *
//    * snprintf: can calculate the size needed for the buffer
//    *
//    */
//   // When converted to char[], takes up 4 bytes: '2', '2', '2', '2'
//   int value_2 = 2222;
//
//   // Return: the number of characters that would have been written if n had
//   been
//   // sufficiently large, not counting the terminating null character.
//   size_t nbytes_2 = snprintf(NULL, 0, "-> %d", value_2) + 1;  // +1 for the
//   '\0' printf("nbytes_snprintf: %ld\n", nbytes_2);
//
//   char *buffer_2 = malloc(nbytes_2);
//   snprintf(buffer_2, nbytes_2, "-> %d", value_2);
//
//   /*
//    * Section 4
//    *
//    * strncat: use only for concatenating string (where no format needed)
//    *
//    */
//   char *s = malloc(nbytes_1 + nbytes_2);
//   strncat(s, buffer_1, nbytes_1);
//   strncat(s, buffer_2, nbytes_2);
//
//   puts(s);  // print with a newline
//
//   free(buffer_1);
//   free(buffer_2);
//   free(s);
// }
