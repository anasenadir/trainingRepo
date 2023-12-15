/*
free two dimentional arrays

*/
#include "main.h"

void free2DArrays(char **array)
{
    int i = 0;


    while (array[i])
    {
        free(array[i]);
        i++;
    }
    free(array);
}


void freeLinkedList(linked_paths *head)
{
    linked_paths *current_node = NULL;

    while(head)
    {
        current_node = head;
        head = head->next;

        free(current_node->data);
        free(current_node);
    }
}


void _perror(char *command, int index)
{
    char *command_num;

    command_num = _itoc(index);

    write(STDERR_FILENO, "sh: ", 4);
    write(STDERR_FILENO, command_num, _strlen(command_num));
    write(STDERR_FILENO, ": ", 2);
    write(STDERR_FILENO, command, _strlen(command));
    write(STDERR_FILENO, ": not found\n", 12);

    free(command_num);
}
