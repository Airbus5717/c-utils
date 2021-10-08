#include "include/utils.h"

// duplicate source code
char *utils_strndup(char *start, const size_t length)
{
    char *buffer = malloc(length + 1);
    memcpy(buffer, start, length);
    buffer[length] = '\0';
    return buffer;
}
