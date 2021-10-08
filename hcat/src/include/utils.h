#ifndef UTILS_H
#define UTILS_H

#include "common.h"
#include "token.h"
#include "vector.h"

typedef struct
{
    char *ptr;
    size_t size;
} string_t;

decl_vec(string_t);

char *utils_strndup(char *start, const size_t length);
void init_string_vec(vec(string_t) str_vec);
void push_string_vec(vec(string_t) str_vec, char *str, const size_t length);
void free_string_vec(vec(string_t) str_vec);
#endif
