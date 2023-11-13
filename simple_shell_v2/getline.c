#include "shell.h"

char *_getline(void)
{
    char *line = NULL;
    size_t len = 0;
    ssize_t nread;

    write(STDOUT_FILENO, "$ ", 2);

    if ((nread = getline(&line, &len, stdin)) == -1)
    {
        return (NULL);
    }

    return (line);
}
