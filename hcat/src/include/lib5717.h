#ifndef LIB5717
#define LIB5717

#include <ctype.h>
#include <limits.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ROTATE STD LIBRARY
// section[0]: stdio
// section[1]: string
// section[2]: stdlib

// std typedefs

//
//     section[0]: stdio
//

//
//    section[1]: string
//
// [requires free][may return NULL]creates a string on heap [O(n)]
char *string(char *str);
// convert string to upper case [O(n)]
void to_upper_case(char *str);
// convert to lower case [O(n)]
void to_lower_case(char *str);
// [requires free][may return NULL] add 2 strings into one string
char *concat_str(const char *str1, const char *str2);
// [requires free][may return NULL] remove last char_count among of chars from a string
// returns a new string
char *remove_last_chars(const char *str, const size_t char_count);
// [may return NULL] modified version of remove_last_chars without
// returning a new string
char *shorten_str(char *str, const size_t char_count);

size_t get_num_of_digits(size_t n);
#endif /* end of LIB5717  */
