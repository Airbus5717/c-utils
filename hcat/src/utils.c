#include "include/utils.h"
#include "include/vector.h"

// duplicate source code
char *utils_strndup(char *start, const size_t length)
{
    char *buffer = malloc(length + 1);
    memcpy(buffer, start, length);
    buffer[length] = '\0';
    return buffer;
}

void push_string_vec(vec(string_t) str_vec, char *str, const size_t length)
{
    const string_t str1 = {utils_strndup(str, length), length};
    vec_push(str_vec, str1);
}

void free_string_vec(vec(string_t) str_vec)
{
    for_each(str_vec, str)
    {
        free_vec(str->ptr);
    }
}
