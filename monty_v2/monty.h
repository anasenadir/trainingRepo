#ifndef MONTY_C
#define MONTY_C

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
    int n;
    struct stack_s *prev;
    struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
    char *opcode;
    void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;


typedef struct gd
{
    FILE *file;
    char *line;
    char *data;
    unsigned int line_number;
} global_data;
extern global_data g_data;

// execute
void execute(stack_t **op_stack, char *content);

// helpers
void cleanup_and_exit(char *message, stack_t **stack_op);
void free_stack(stack_t *op_stack);
// opcode_interpreters
void push(stack_t **stack_op, unsigned int linenumber);
void pall(stack_t **stack_op, unsigned int linenumber);
void pint(stack_t **stack, unsigned int linenumber);
#endif
