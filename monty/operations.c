#include "monty.h"

extern char * file_data;

void push(stack_t **stack_op, unsigned int linenumber)
{
    char *line;
    int num;
    unsigned int i = 0;
    char **file_copy = get_file_cpy();
    stack_t *new_item;
    
    if (!file_copy)
        return;
    
    new_item = malloc(sizeof(stack_t));
    if (!new_item)
        return;
    
    // line = strtok(file_data, "\n");
    // while (line)
    // {
    //     if (i == linenumber - 1)
    //     {
    //         strtok(line, " \t");
    //         num = atoi(strtok(NULL, " \t"));
    //         break;
    //     }
    //     i++;
    //     line = strtok(NULL, "\n");
    // }

    line = file_copy[linenumber];
    strtok(line, " \t");
    num = atoi(strtok(NULL, " \t"));

    new_item->n = num;
    new_item->prev = NULL;
    new_item->next = NULL;

    if (!(*stack_op))
    {
        *stack_op = new_item;
        return;
    }
    (*stack_op)->next = new_item;
    new_item->prev = (*stack_op);
    (*stack_op) = new_item;
    
}

void pall(stack_t **stack_op, unsigned int linenumber)
{
    stack_t *tmp = *stack_op;

    while (tmp)
    {
        printf("%d\n", tmp->n);
        tmp = tmp->prev;
    }
    printf("==================\n");
}

void pint(stack_t **stack, unsigned int linenumber)
{
    if (!*stack)
        return;
    printf("%d\n", (*stack)->n);
}
void pop(stack_t **stack_op, unsigned int linenumber)
{
    stack_t *tmp, *prev;
    if (!*stack_op)
    {
        fprintf(stderr, "L<line_number>: can't pop an empty stack");
        exit(EXIT_FAILURE);
    }

    tmp = (*stack_op);
    if ((*stack_op)->prev)
    {
        (*stack_op)->prev->next = NULL;
        *stack_op = (*stack_op)->prev;
    }
    
    free(tmp);
    
}
