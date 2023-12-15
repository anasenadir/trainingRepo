#include "monty.h"

void (*get_associated_func(char *opcode))(stack_t **stack, unsigned int line_number)
{
    int index;
    instruction_t insractions[] = {
        {"pall", pall},
        {"push", push},
        // {"pop", pop},
        {"pint", pint},
        {NULL, NULL}
    };

    index = 0;
    while (insractions[index].opcode && opcode)
    {
        if (strcmp(insractions[index].opcode, opcode) == 0)
        {
            return (insractions[index].f);
        }
        index++;
    }
    return (NULL);
}
void execute(stack_t **op_stack, char *content)
{
    void (*ptr_func)(stack_t **, unsigned int);
    char *opcode;

    opcode = strtok(content, " \n\t");
    g_data.data = strtok(NULL, " \n\t");

    printf("opcode: %s\n", opcode);
    // printf("%s\n", opcode);
    ptr_func = get_associated_func(opcode);

    // if (ptr_func == NULL && opcode)
    //     cleanup_and_exit("opcode not found", op_stack);
    // printf("opcode: pass\n");
    // ptr_func(op_stack, g_data.line_number);


    if (ptr_func)
    {
        ptr_func(op_stack, g_data.line_number);
        return;
    }

    if (ptr_func == NULL && opcode)
        cleanup_and_exit("opcode not found", op_stack);
    return;
}
