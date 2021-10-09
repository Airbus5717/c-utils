#ifndef EXPORT_H
#define EXPORT_H

#include "lexer.h"

void print_color(const char *color, const char *val, bool bold);
void dump_colored_output(lexer_t *lexer);

#endif /* EXPORT_H */
