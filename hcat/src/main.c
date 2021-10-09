// cat program alternative with syntax highlighting
// By Airbus5717 2021 (C)
// MIT License

#include "include/main.h"
#include "include/export.h"
#include "include/lexer.h"

int main(int argc, char **argv)
{
    // if program arguments less than 2
    if (argc < 2)
    {
        printf("cat [filename]\n");
        return 0;
    }
    size_t i, j = 0;
    for (i = 0; argv[1][i] != '\0'; i++)
        if (argv[1][i] == '.') j = i;
    // open file
    FILE *file = fopen(argv[1], "rb");
    if (!file)
    {
        printf("No such file or directory. [%s]\n", argv[1]);
        return 1;
    }

    // seek to end of file for calculating length
    fseek(file, 0, SEEK_END);
    // if (!ftell(file))
    // {
    //     printf("File is empty\n");
    //     fclose(file);
    //     return 1;
    // }

    // get length
    const size_t length = ftell(file);
    // rewind to beginning
    rewind(file);

    // allocate memory for file
    char *str = malloc(length + 1);
    if (!str)
    {
        printf("allocation failure\n");
        fclose(file);
        return 1;
    }

    // put file in memory
    if (fread(str, sizeof(char), length, file) != length)
    {
        printf("error reading file\n");
        free(str);
        fclose(file);
        return 1;
    }
    // add null-terminating char
    str[length] = '\0';

    lexer_t lexer;
    lexer_init(&lexer, str, length);
    lexer.file_ext = j == 0 ? NULL : &argv[1][j + 1];
    int exit = lexer_lex(&lexer);

    // dump string output
    dump_colored_output(&lexer);
    // free and close
    lexer_destroy(&lexer);
    fclose(file);
    return exit;
}
