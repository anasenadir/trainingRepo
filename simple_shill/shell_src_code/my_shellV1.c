#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>


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
int main(void)
{
	char *line = NULL;
	size_t length = 0;
	ssize_t nread;
	pid_t child_pid;

	while (1)
	{
		write(STDOUT_FILENO, "$ ", 2);

		nread = getline(&line, &length, stdin);

		if (nread == -1)
			perror("getline"),exit(EXIT_FAILURE);
		
		if (strcmp(line, "exit\n") == 0)
		{
			printf("Goodbay\n");
			break;
		}

		char **command = _splited_line(line);
		
		child_pid = fork();
		
		if (child_pid == -1)
			perror("fork"), exit(EXIT_FAILURE);

		if (child_pid == 0)
		{
			if (execve(command[0], command, NULL) == -1)
				perror("ERROR::"),exit(EXIT_FAILURE);
		}
		else
		{
			wait(NULL);
		}
		free(command);

	}
	free(line);
	return (EXIT_SUCCESS); 

}
