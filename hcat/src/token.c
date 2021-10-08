#include "include/token.h"

const char *describe_token_type(const token_type_t tkn)
{
    switch (tkn)
    {
        case ID:
            return "ID";
        case NUMBER:
            return "NUMBER";
        case KEYWORD:
            return "KEYWORD";
        case TYPE:
            return "TYPE";
        case STRING:
            return "STRING";
        case CHAR:
            return "CHAR";
        case SPACE:
            return "SPACE";
        case OTHER:
            return "OTHER";
        default:
            return "???";
    }
}

void tokens_free(vec(token_t) tkns)
{
    for_each(tkns, tkn_t)
    {
        free(tkn_t->val);
    }
    free_vec(tkns);
}
