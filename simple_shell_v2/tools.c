#include "shell.h"

void free_2D_array(char **command)
{
    int i = 0;

    while (command[i])
    {
        free(command[i]);
        i++;
    }
    free(command);
}
