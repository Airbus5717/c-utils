#include "include/lexer.h"
#include "include/utils.h"
#include <stdlib.h>

void lexer_init(lexer_t *lexer, char *str, size_t len)
{
    lexer->index = 0;
    lexer->file_len = len;
    lexer->input = str;
    lexer->output = new_vec(token_t);
}

size_t lexer_lex(lexer_t *lexer)
{
    for (lexer->index = 0; lexer->index < lexer->file_len; next())
    {
        if (lexer_single(lexer) == EXIT_FAILURE) return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

void lexer_tkn(lexer_t *lexer, token_type_t type)
{
    const token_t tkn = {utils_strndup(lexer->input + lexer->index, length()), type};
    lexer->index += lexer->length - 1;
    vec_push(lexer->output, tkn);
}

size_t lexer_single(lexer_t *lexer)
{
    const char c = current();
    length() = 1;
    size_t save_index = lexer->index;
    if (isspace(c))
    {
        lexer_tkn(lexer, SPACE);
        return EXIT_SUCCESS;
    }
    else if (isdigit(c))
    {
        next();
        bool reached_float_dot = false;
        while (isdigit(current()) || current() == '.')
        {
            if (current() == '.')
            {
                if (reached_float_dot) break;
                reached_float_dot = true;
            }
            next();
            add_len();
        }
        lexer->index = save_index;
        lexer_tkn(lexer, NUMBER);
        return EXIT_SUCCESS;
    }
    else if (c == '"')
    {
        next();
        while (current() != '"' && !is_eof())
        {
            if (current() == '\0')
            {
                return EXIT_FAILURE;
            }
            if (current() == '\\' && peek() == '"')
            {
                next();
                add_len();
            }
            next();
            add_len();
        }
        add_len();
        lexer->index = save_index;
        lexer_tkn(lexer, STRING);
        return EXIT_SUCCESS;
    }
    else if (c == '\'')
    {
        next();
        while (current() != '\'' && !is_eof())
        {
            if (isspace(current()) && peek() != '\'')
            {
                return EXIT_FAILURE;
            }
            if (current() == '\0')
            {
                return EXIT_FAILURE;
            }

            if (length() == 2 && past() == '\\' && current() != '\\')
            {
                add_len();
                break;
            }
            if (length() > 1 && past() != '\\' && (peek() == '\'' || peek() == '\\'))
            {
                return EXIT_FAILURE;
            }
            next();
            add_len();
        }
        add_len();
        lexer->index = save_index;
        lexer_tkn(lexer, CHAR);
        return EXIT_SUCCESS;
    }
    else if (isalpha(c))
    {
        return lexer_multichar(lexer);
        return EXIT_SUCCESS;
    }
    else
    {
        lexer_tkn(lexer, OTHER);
        return EXIT_SUCCESS;
    }
}

size_t lexer_multichar(lexer_t *lexer)
{
    size_t save_index = lexer->index ;
    next();

    length() = 1;
    while ((isalnum(current()) || current() == '_') && !is_eof())
    {
        (lexer->index++);
        (lexer->length)++;
    }
    token_type_t tkn_type = ID;
    lexer->index = save_index;
    lexer_tkn(lexer, tkn_type);
    return EXIT_SUCCESS;
}

void lexer_destroy(lexer_t *lexer)
{
    free_vec(lexer->output);
    lexer->output = NULL;
}
