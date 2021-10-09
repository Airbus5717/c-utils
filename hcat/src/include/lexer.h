#ifndef LEXER_H
#define LEXER_H

#include "common.h"
#include "lib5717.h"
#include "token.h"
#include "utils.h"
#include "vector.h"

typedef struct
{
    char *input;
    char *file_ext;
    vec(token_t) output;
    vec(string_t) keywords;
    vec(string_t) types;
    size_t file_len;
    size_t index;
    size_t length;
} lexer_t;

void lexer_init(lexer_t *lexer, char *str, size_t len);
void lexer_destroy(lexer_t *lexer);
size_t lexer_lex(lexer_t *lexer);
size_t lexer_single(lexer_t *lexer);
size_t lexer_multichar(lexer_t *lexer);
size_t lexer_lex(lexer_t *lexer);

#define current() (lexer->input[lexer->index])
#define peek() (lexer->input[lexer->index + 1])
#define past() (lexer->input[lexer->index - 1])
#define is_eof() (lexer->index >= lexer->file_len)
#define add_len() (lexer->length++)
#define length() (lexer->length)
#define next() (lexer->index++)
#define rewind_macro(n) (lexer->index -= (n))
#define keyword_match(str) strncmp(lexer->input + lexer->index, str, length()) == 0

#endif /* LEXER_H */
