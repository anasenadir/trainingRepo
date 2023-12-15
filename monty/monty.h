#ifndef MONTHY_H
#define MONTHY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <limits.h>
#include <fcntl.h>

#define min(x, y) (((x) < (y)) ? (x) : (y))
#define MAX_LINE_SIZE 100
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



/*
*/
// operations
void push(stack_t **stack, unsigned int linenumber); 
void pall(stack_t **stack, unsigned int linenumber); 
void pop(stack_t **stack, unsigned int linenumber); 
void pint(stack_t **stack, unsigned int linenumber);

// helper
void (*get_right_func(char *opcode))(stack_t **stack, unsigned int line_number);
char **get_file_cpy();
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void resolve(stack_t **op_stack);

// file_handler
void readfile(int file_d);
#endif
