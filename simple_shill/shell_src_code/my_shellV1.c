#include "main.h"

int main(void)
{
	char *line = NULL;
	size_t length = 0;
	ssize_t nread;
	pid_t child_pid;
	int index = 0;
	linked_paths *paths_head = generate_linked_paths_list();

	while (1)
	{
		write(STDOUT_FILENO, "$ ", 2);

		nread = getline(&line, &length, stdin);

		if (nread == -1)
			perror("getline"),exit(EXIT_FAILURE);
		
		if (strcmp(line, "exit\n") == 0)
		{
			freeLinkedList(*paths_head);
			printf("Goodbay\n");
			break;
		}

		char **command = _splited_line(line);
		
		child_pid = fork();
		
		if (child_pid == -1)
		{
			free2DArrays(command);
			freeLinkedList(paths_head);
			
			perror("fork");
			exit(EXIT_FAILURE);
		}

		if (child_pid == 0)
		{
			execute(command, paths_head, index);
		}
		else
		{
			wait(NULL);
		}
		
		free2DArrays(command);
		freeLinkedList(paths_head);
		index++;
	}
	free(line);
	return (EXIT_SUCCESS); 

}
