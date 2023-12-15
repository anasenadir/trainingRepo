#include "monty.h"


char **file_data;


int main(int argc, char **argv)
{
    int file_d;
    char *file_name;
    stack_t *op_stack;
    instruction_t *instruction;
    (void) op_stack;
    (void)instruction;

    if (argc != 2)
    {
        fprintf(stderr,"USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }
    file_name = argv[1];

    file_d = open(file_name, O_RDONLY);

    if (file_d == -1)
    {
        fprintf(stderr,"Error: Can't open file %s\n", file_name);
        exit(EXIT_FAILURE);
    }

    op_stack = NULL;
    readfile(file_d);
    resolve(&op_stack);
    return (0);
}




