#include "include/languages.h"
#include "include/token.h"
#include "include/utils.h"
#include "include/vector.h"

void lexer_init(lexer_t *lexer, char *str, size_t len)
{
    lexer->index = 0;
    lexer->file_len = len;
    lexer->input = str;
    lexer->output = new_vec(token_t);
    // lexer->keywords = new_vec(string_t);
    // lexer->types = new_vec(string_t);
}

// void lexer_get_words(lexer_t *lexer)
// {
//     char this_word[50];
//     lexer->file_ext = "c";
//     char *f_name = concat_str("./syntax/", lexer->file_ext);
//     char *f_name2 = concat_str(f_name, "/keywords");
//     char *f_name3 = concat_str(f_name, "/types");
//     FILE *keyfile = fopen(f_name2, "r");
//     FILE *typefile = fopen(f_name3, "r");
//     if (!keyfile && !typefile)
//     {
//         free(f_name);
//         free(f_name2);
//         free(f_name3);
//         return;
//     }
//     while (fscanf(keyfile, "%49s", this_word) == 1)
//     {
//         size_t len = strlen(this_word);
//         const string_t str = (string_t){utils_strndup(this_word, len), len};
//         vec_push(lexer->keywords, str);
//     }

//     while (fscanf(typefile, "%49s", this_word) == 1)
//     {
//         size_t len = strlen(this_word);
//         const string_t str = (string_t){utils_strndup(this_word, len), len};
//         vec_push(lexer->types, str);
//     }

//     fclose(keyfile);
//     fclose(typefile);
//     free(f_name);
//     free(f_name2);
// }

size_t lexer_lex(lexer_t *lexer)
{
    // lexer_get_words(lexer);
    for (lexer->index = 0; lexer->index < lexer->file_len; next())
    {
        if (lexer_single(lexer) == EXIT_FAILURE) return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

void lexer_tkn(lexer_t *lexer, token_type_t type)
{
    const token_t tkn = (token_t){utils_strndup(lexer->input + lexer->index, length()), type};
    lexer->index += (lexer->length) - 1;
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
    else if (c == '/' && peek() == '/')
    {
        while (current() != '\n' && !is_eof())
        {
            next();
            add_len();
        }
        length() -= 1;
        lexer->index = save_index;
        lexer_tkn(lexer, COMMENT);
        return EXIT_SUCCESS;
    }
    else if (c == '/' && peek() == '*')
    {
        bool end_comment = false;
        while (!is_eof() && current() != '\0' && !end_comment)
        {
            if ((past() == '*' && current() == '/')) end_comment = true;
            next();
            add_len();
        }
        lexer->index = save_index;
        lexer_tkn(lexer, COMMENT);
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
    size_t save_index = lexer->index;
    next();

    length() = 1;
    while ((isalnum(current()) || current() == '_') && !is_eof())
    {
        (lexer->index++);
        (lexer->length)++;
    }
    token_type_t tkn_type = ID;
    lexer->index = save_index;
    if (lexer->file_ext)
    {
        switch (strlen(lexer->file_ext))
        {
            case 1:
                if (strcmp(lexer->file_ext, "c") == 0)
                    tkn_type = get_token_type_multichar(lexer, C);
                break;
            case 2:
                if (strcmp(lexer->file_ext, "py") == 0)
                    tkn_type = get_token_type_multichar(lexer, PYTHON);
                break;
            default:
                break;
        }
    }
    lexer_tkn(lexer, tkn_type);
    return EXIT_SUCCESS;
}

void lexer_destroy(lexer_t *lexer)
{
    for_each(lexer->output, tkn_t)
    {
        free(tkn_t->val);
    }
    // free_string_vec(lexer->keywords);
    // free_string_vec(lexer->types);
    free(lexer->input);
    lexer->output = NULL;
    lexer->keywords = NULL;
    lexer->types = NULL;
    lexer->input = NULL;
}
