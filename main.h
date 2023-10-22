#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

/**
* struct listint_s - singly linked list
* @n: integer
* Description: singly linked list node structure
*/
typedef struct listint_s
{
    int n;
    struct listint_s *next; 
} listint_t;

int _putchar(char c);

#endif
