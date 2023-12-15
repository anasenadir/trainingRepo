#include "monty.h"

global_data g_data = {NULL,NULL, NULL, 0};

int main(int argc, char **argv)
{
    FILE *fd;
    stack_t *op_stack;
    char *file_name, *content;
    size_t line_size = 0, read_byte = 1;

    op_stack = NULL;

    if (argc != 2)
    {
        fprintf(stderr,"USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }
    file_name = argv[1];

    fd = fopen(file_name, "r");
    g_data.file = fd;

    if (g_data.file == NULL)
    {
        fprintf(stderr,"Error: Can't open file %s\n", file_name);
        exit(EXIT_FAILURE);
    }

    // while ((read_byte = getline(&content, &line_size, g_data.file)))
    // {
    //     // printf("%s", g_data.line);
    //     g_data.line_number += 1;
    //     g_data.line = content;
    //     if (read_byte > 0)
    //         execute(&op_stack, content);
    //     free(content);
    //     content = NULL;
    //     // free(g_data.line);
    // }

    while (read_byte)
    {
        content = NULL;
        read_byte = getline(&content, &line_size, g_data.file);
        g_data.line = content;
        g_data.line_number += 1;
        if (read_byte > 0)
        {
            execute(&op_stack, content);
        }
        free(content);
    }
    // free(g_data.line);
    free_stack(op_stack);
    fclose(g_data.file);
    return (0);
}
