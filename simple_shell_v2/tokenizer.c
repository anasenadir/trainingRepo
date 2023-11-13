#include "shell.h"


char **tokenizer(char *line)
{
    char *token = NULL, *temp = NULL; 
    char **command = NULL;
    int i = 0, cpt = 0;

    if (!line)
        return (NULL);

    temp = strdup(line);
    if (!temp) {
        perror("Memory allocation error");
        free(line);
        return NULL;
    }

    token = strtok(temp, DELIMITER);
    if (token == NULL)
    {
        free(temp);
        free(line);
        return (NULL);
    }
    

    while (token)
    {
        cpt++;
        token = strtok(NULL, DELIMITER);
    }
    free(temp), temp = NULL;

    command = malloc(sizeof(char *) * (cpt + 1));
    if (!command)
    {
        free(line), line = NULL;
        return (NULL);
    }

    token = strtok(line, DELIMITER);
    while (token)
    {
        command[i] = token;
        token = strtok(NULL, DELIMITER);
        i++;
    }

    command[i] = NULL;
    return (command);
}

