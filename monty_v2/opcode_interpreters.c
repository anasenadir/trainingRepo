#include "monty.h"



int is_integer(char *num)
{
    int flag = 1, i = 0;

    for (; (num[i] != '\0') ; i++)
        if (num[i] < '0' || num[i] > '9')
            flag = -1;
    return flag;
}

void push(stack_t **stack_op, unsigned int linenumber)
{
    stack_t *new_item;
    int i = 0,flag = 0;

    if (!g_data.data)
        cleanup_and_exit("usage: push integer", stack_op);
    if (is_integer(g_data.data) == -1)
        cleanup_and_exit("usage: push integer", stack_op);

    new_item = malloc(sizeof(stack_t));
    if (!new_item)
        return;
    

    new_item->n = atoi(g_data.data);
    new_item->next = NULL;
    new_item->prev = NULL;

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
    stack_t *head = *stack_op;

    if (!head)
        return;

    while (head)
    {
        printf("%d\n", head->n);
        head = head->prev;
    }
}

void pint(stack_t **stack, unsigned int linenumber)
{
    if (!*stack)
        return;
    printf("%d\n", (*stack)->n);
}
