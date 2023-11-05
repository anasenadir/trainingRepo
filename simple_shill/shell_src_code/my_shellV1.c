#include "main.h"

int main(void)
{
	char *line = NULL;
	size_t length = 0;
	ssize_t nread;
	pid_t child_pid;
	
	linked_paths *paths_head = generate_linked_paths_list();

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
			while (paths_head)
            		{
                		char executable_path[MAX_BUF_SIZE];
                		snprintf(executable_path, sizeof(executable_path), "%s/%s", paths_head->data, command[0]);
                		if (execve(executable_path, command, NULL) == -1)
                		{
                    			perror("ERROR::");
                    			exit(EXIT_FAILURE);
                		}
                		paths_head = paths_head->next;
            		}
            		// Command not found, exit with an error status
            		exit(EXIT_FAILURE);
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
