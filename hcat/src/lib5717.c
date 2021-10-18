#include "include/lib5717.h"

// ROTATE STD LIBRARY
// section[0]: stdio
// section[1]: string

//
// section[0] (stdio)
//
void print(const char *str)
{
    printf("%s", (str ? str : "null"));
}

void println(const char *str)
{
    puts((str ? str : "null"));
}

//
// section[1] (string)
//
char *string(char *str)
{
    size_t len = strlen(str);
    char *res = malloc(len + 1);
    memcpy(res, str, len);
    res[len] = '\0';
    return res;
}

void to_upper_case(char *str)
{
    if (str) // str != NULL
    {
        size_t len = strlen(str);
        for (size_t i = 0; i < len; i++)
            str[i] = toupper(str[i]);
    }
}

void to_lower_case(char *str)
{
    if (str) // str != NULL
    {
        size_t len = strlen(str);
        for (size_t i = 0; i < len; i++)
            str[i] = tolower(str[i]);
    }
}

char *concat_str(const char *str1, const char *str2)
{
    if (str1 && str2) // str1 and str2 != NULL
    {
        size_t len1 = strlen(str1);
        size_t len2 = strlen(str2);
        char *res = malloc(len1 + len2 + 1);
        if (!res) return NULL;
        memcpy(res, str1, len1);
        memcpy(res + len1, str2, len2);
        res[len1 + len2] = '\0';
        return res;
    }
    return NULL;
}

char *remove_last_chars(const char *str, const size_t char_count)
{
    if (str) // str != NULL
    {
        size_t len = strlen(str);
        if (len == 0) return NULL;
        char *res = malloc(len + 1);
        if (!res) return NULL;
        memcpy(res, str, len - char_count);
        res[len - char_count] = '\0';
        return res;
    }
    return NULL;
}

char *shorten_str(char *str, const size_t char_count)
{
    if (str) // str != NULL
    {
        size_t len = strlen(str);
        if (len == 0) return NULL;
        size_t new_len = char_count > len ? 0 : len - char_count;
        str[new_len] = '\0';
        return str + new_len;
    }
    return NULL;
}

size_t get_num_of_digits(size_t n)
{
    if (n < 10) return 1;
    if (n < 100) return 2;
    if (n < 1000) return 3;
    if (n < 10000) return 4;
    if (n < 100000) return 5;
    if (n < 1000000) return 6;
    if (n < 10000000) return 7;
    if (n < 100000000) return 8;
    if (n < 1000000000) return 9;
    /*      2147483647 is 2^31-1 - add more ifs as needed
       and adjust this final return as well. */
    return 10;
}
