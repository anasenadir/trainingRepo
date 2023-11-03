#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

char **_split_str(char *line)
{
	char **array = NULL;
	char *current_str;
	int index = 0;

	array = malloc(sizeof(char*));

	if (!array)
		perror("memory allocated failed"), exit(EXIT_FAILURE);

	array[index] = strtok(line, " \n\t");
	
	while (current_str = strtok(NULL, " \n\t"))
	{
		index++;
		array = realloc(array, (index + 1) * sizeof(char *));

		if (!array)
			perror("memory reallocation failed"), exit(EXIT_FAILURE);

		array[index] = current_str;
	}
	
	index++;
	array = realloc(array, (index + 1) * sizeof(char *));
	
	if (!array)
		perror("memory reallocation failed"), exit(EXIT_FAILURE);
	array[index] = NULL;
	return (array);
}

int main(void)
{
	char *line = NULL;
	size_t length = 0, i;
	ssize_t nread;
	char **splited_string = NULL;

	write(STDOUT_FILENO, "$ ", 2);

	nread = getline(&line, &length, stdin);

	if (nread == -1)
		perror("getline"), exit(EXIT_FAILURE);

	splited_string = _split_str(line);

	for (i = 0; splited_string[i] != NULL; i++)
		printf("The value of index %ld is %s\n", i, splited_string[i]);
	free(splited_string);
	free(line);
	return (EXIT_SUCCESS);
}
