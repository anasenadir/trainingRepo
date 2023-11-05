#include "main.h"
int _strlen(char *str)
{
        int len = 0;

        if (!str || str == "")
                return (0);

        while (str[len] != '\0')
                len++;
        return (len);
}

char **_splited_line(char *line)
{
	char **array = NULL;
	int index = 0;
	char *current;

	array = malloc(sizeof(char *));

	if (!array)
		perror("memory allocation failed"),exit(EXIT_FAILURE);
	array[index] = strtok(line, " \n\t");

	while ((current = strtok(NULL, " \n\t")) != NULL)
	{
		index++;
		array = realloc(array, (index + 1) * sizeof(char *));

		if (!array)
			perror("memory reallocation failed"), exit(EXIT_FAILURE);
		array[index] = current;
	}

	index++;
	array = realloc(array, (index + 1) * sizeof(char *));

	if (!array)
		perror("memory reallocation failed for null termination"), exit(EXIT_FAILURE);

	array[index] = NULL;

	return (array);
}
