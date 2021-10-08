#ifndef COMMON_H
#define COMMON_H

//! do not import local header files from this project
//! only include external library headers or define globals

#include <assert.h>
#include <ctype.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define RED "\x1b[31m"
#define GREEN "\x1b[32m"
#define YELLOW "\x1b[33m"
#define BLUE "\x1b[34m"
#define PINK "\x1b[35m"
#define CYAN "\x1b[36m"
#define RESET "\x1b[0m"

#define BOLD "\x1b[1m"
#define FAINT "\x1b[2m"

#define BLACK "\x1b[30m"
#define WHITE "\x1b[37m"
#define DEFAULT "\x1b[39m"
#define LGRAY "\x1b[90m"
#define LRED "\x1b[91m"
#define LGREEN "\x1b[92m"
#define LYELLOW "\x1b[93m"
#define LBLUE "\x1b[94m"
#define LMAGENTA "\x1b[95m"
#define LCYAN "\x1b[96m"
#define LWHITE "\x1b[97m"
#endif
