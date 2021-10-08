#ifndef TOKEN_H
#define TOKEN_H

#include "vector.h"

typedef enum
{
    ID,
    KEYWORD,
    NUMBER,
    TYPE,
    CHAR,
    STRING,
    SPACE, // newline and tab etc. also included
    OTHER,
} token_type_t;

typedef struct
{
    char *val;
    token_type_t type;
} token_t;

decl_vec(token_t);
const char *describe_token_type(const token_type_t tkn);
void tokens_free(vec(token_t) tkns);

#endif /* TOKEN_H */
