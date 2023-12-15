#include "monty.h"
void cleanup_and_exit(char *message, stack_t **stack_op)
{
    if (!message)
        message = " ";
    fprintf(stderr, "L%d: %s\n", g_data.line_number, message);
    free(g_data.line);
	free_stack(*stack_op);
    fclose(g_data.file);
    exit(EXIT_FAILURE);
}


/**
* free_stack - frees a doubly linked list
* @head: head of the stack
*/
void free_stack(stack_t *op_stack)
{
	stack_t *aux;

	aux = op_stack;
	while (op_stack)
	{
		aux = op_stack->next;
		free(op_stack);
		op_stack = aux;
	}
}
