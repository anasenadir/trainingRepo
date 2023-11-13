#include "shell.h"


int main(int argc, char **argv)
{
    char *line, **command;
    int status = 0, i = 0;
    (void)argc;
    (void)argv;
    (void)i;
    while(1)
    {
        line = _getline();
        if (!line)
        {
            return (status);
        }

        command = tokenizer(line);

        if (!command)
            continue;
        
        execute(command);
        
        free(line);
    }

    return (0);
}
