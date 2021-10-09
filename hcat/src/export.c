#include "include/export.h"
#include "include/token.h"

void print_color(const char *color, const char *val, bool bold)
{
    if (bold)
        printf("%s%s%s%s", BOLD, color, val, RESET);
    else
        printf("%s%s%s", color, val, RESET);
}

void dump_colored_output(lexer_t *lexer)
{
    for_each(lexer->output, tkn_t)
    {
        // printf("token: (%s) with text \"%s\"\n", describe_token_type(tkn_t->type), tkn_t->val);
        switch (tkn_t->type)
        {
            case KEYWORD:
                print_color(LYELLOW, tkn_t->val, true);
                break;
            case TYPE:
                print_color(LBLUE, tkn_t->val, false);
                break;
            case STRING:
                print_color(LCYAN, tkn_t->val, false);
                break;
            case COMMENT:
                print_color(LGRAY, tkn_t->val, true);
                break;
            case NUMBER:
                print_color(LRED, tkn_t->val, false);
                break;
            default:
                printf("%s", tkn_t->val);
        }
    }
}
