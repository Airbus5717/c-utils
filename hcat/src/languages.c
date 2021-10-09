#include "include/languages.h"
#include "include/token.h"

token_type_t get_token_type_multichar(lexer_t *lexer, lang_t lang)
{
    switch (lang)
    {
        case C:
            return clang(lexer);
        default:
            return ID;
    }
}

token_type_t clang(lexer_t *lexer)
{
    switch (lexer->length)
    {
        case 2:
            if (keyword_match("if"))
                return KEYWORD;
            else if (keyword_match("do"))
                return KEYWORD;
            break;
        case 3:
            if (keyword_match("asm"))
                return KEYWORD;
            else if (keyword_match("for"))
                return KEYWORD;
            // types
            else if (keyword_match("int"))
                return TYPE;
            break;
        case 4:
            if (keyword_match("auto"))
                return KEYWORD;
            else if (keyword_match("case"))
                return KEYWORD;
            else if (keyword_match("else"))
                return KEYWORD;
            else if (keyword_match("enum"))
                return KEYWORD;
            else if (keyword_match("goto"))
                return KEYWORD;
            // types
            else if (keyword_match("long"))
                return TYPE;
            else if (keyword_match("char"))
                return TYPE;
            else if (keyword_match("bool"))
                return TYPE;
            else if (keyword_match("true"))
                return TYPE;
            else if (keyword_match("void"))
                return TYPE;
            break;
        case 5:
            if (keyword_match("break"))
                return KEYWORD;
            else if (keyword_match("const"))
                return KEYWORD;
            else if (keyword_match("union"))
                return KEYWORD;
            else if (keyword_match("while"))
                return KEYWORD;
            // types
            else if (keyword_match("false"))
                return TYPE;
            else if (keyword_match("short"))
                return TYPE;
            else if (keyword_match("float"))
                return TYPE;
            break;
        case 6:
            if (keyword_match("struct"))
                return KEYWORD;
            else if (keyword_match("return"))
                return KEYWORD;
            else if (keyword_match("sizeof"))
                return KEYWORD;
            else if (keyword_match("switch"))
                return KEYWORD;
            else if (keyword_match("static"))
                return KEYWORD;
            else if (keyword_match("extern"))
                return KEYWORD;
            else if (keyword_match("define"))
                return KEYWORD;
            // types
            else if (keyword_match("signed"))
                return TYPE;
            else if (keyword_match("double"))
                return TYPE;
            else if (keyword_match("size_t"))
                return TYPE;
            break;
        case 7:
            if (keyword_match("default"))
                return KEYWORD;
            else if (keyword_match("include"))
                return KEYWORD;
            else if (keyword_match("typedef"))
                return KEYWORD;
            break;
        case 8:
            if (keyword_match("continue"))
                return KEYWORD;
            else if (keyword_match("register"))
                return KEYWORD;
            else if (keyword_match("volatile"))
                return KEYWORD;
            // types
            else if (keyword_match("unsigned"))
                return TYPE;
            break;
        default:
            return ID;
    }
    return ID;
}
