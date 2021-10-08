// TODO: cat program alternative with syntax highlighting
// By Airbus5717 2021 (C)
// MIT License

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    // if program arguments less than 2
    if (argc < 2)
    {
        printf("cat [filename]\n");
        return 0;
    }

    // open file
    FILE *file = fopen(argv[1], "rb");
    if (!file)
    {
        printf("err\n");
        return 1;
    }

    // seek to end of file for calculating length
    fseek(file, 0, SEEK_END);
    if (!ftell(file))
    {
        printf("err length\n");
        fclose(file);
        return 1;
    }

    // get length
    const size_t length = ftell(file);
    // rewind to beginning
    rewind(file);

    // allocate memory for file
    char *str = malloc(length + 1);
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

    // dump string output
    printf("%s\n", str);

    // free and close
    free(str);
    fclose(file);
    return 0;
}
