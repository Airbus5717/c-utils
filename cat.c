// cat program
// By Airbus5717 2021 (C)
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        printf("cat [filename]\n");
        return 1;
    }
    FILE *file = fopen(argv[1], "rb");
    if (!file)
    {
        printf("err\n");
        return 1;
    }

    fseek(file, 0, SEEK_END);
    if (!ftell(file))
    {
        printf("err length\n");
        fclose(file);
        return 1;
    }
    const size_t length = ftell(file);

    rewind(file);

    char *str = malloc(length + 1);
    if (fread(str, sizeof(char), length, file) != length)
    {
        printf("error reading file\n");
        free(str);
        fclose(file);
        return 1;
    }

    str[length] = '\0';

    printf("%s\n", str);

    free(str);
    fclose(file);
    return 0;
}
