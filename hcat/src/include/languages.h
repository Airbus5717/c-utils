#ifndef LANGUAGES_H
#define LANGUAGES_H

#include "common.h"
#include "lexer.h"
#include "token.h"

typedef enum
{
    C,
    PYTHON,
} lang_t;

token_type_t get_token_type_multichar(lexer_t *lexer, lang_t lang);
token_type_t clang(lexer_t *lexer);

#endif
