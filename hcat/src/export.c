#include "include/export.h"
#include "include/token.h"
#include "include/vector.h"
#include <stddef.h>
#include <stdio.h>

void print_color(const char *color, const char *val, bool bold)
{
    if (bold)
        printf("%s%s%s%s", BOLD, color, val, RESET);
    else
        printf("%s%s%s", color, val, RESET);
}

void print_newline(size_t i, size_t max)
{
    putchar('\n');
    printf("%zu", i);
    for (size_t j = 0; j < max - get_num_of_digits(i) + 1; j++)
        putc(' ', stdout);
    printf("| ");
}

void dump_colored_output(lexer_t *lexer)
{
    size_t i = 1, j = 0, space_len = get_num_of_digits(lexer->lines);
    char *spaces = malloc(space_len + 1);
    for (size_t i = 0; i < space_len; i++)
        spaces[i] = ' ';
    spaces[space_len] = 0;
    printf("1%s| ", spaces);
    size_t len = vec_len(lexer->output);
    for_each(lexer->output, tkn_t)
    {
        j++;
        // printf("token: (%s) with text \"%s\"\n", describe_token_type(tkn_t->type), tkn_t->val);
        switch (tkn_t->type)
        {
            // case ID:
            //     print_color(LCYAN, tkn_t->val, false);
            //     break;
            case KEYWORD:
                print_color(YELLOW, tkn_t->val, false);
                break;
            case TYPE:
                print_color(LGREEN, tkn_t->val, false);
                break;
            case STRING:
                print_color(LMAGENTA, tkn_t->val, false);
                break;
            case CHAR:
                print_color(LCYAN, tkn_t->val, false);
                break;
            case COMMENT:
                print_color(LGRAY, tkn_t->val, true);
                break;
            case NUMBER:
                print_color(LRED, tkn_t->val, false);
                break;
            case NEWLINE: {
                if (j < len)
                    print_newline(++i, space_len);
                else
                    printf("\n");
                break;
            }
            default:
                printf("%s", tkn_t->val);
        }
    }
    free(spaces);
}
