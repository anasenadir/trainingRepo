#include "main.h"



void execute(char **command, linked_paths *paths_head, int command_number)
{
    struct stat st;

    // if the user gives the full path of the command
    if (_str_exist(command[0], '/'))
    {
        if (execve(command[0], command, NULL) == -1)
        {
            perror("execve");
            exit(EXIT_FAILURE);
        }
        return;
    }


    while (paths_head)
    {

        char *executable_path;

        executable_path = malloc(_strlen(paths_head->data) + _strlen(command[0]) + 2);

        if (!executable_path)
        {
            // printf("\n=====1\n");
            freeLinkedList(paths_head);
            free2DArrays(command);
            perror("memory allocation failed (executable_path)\n");
            exit(EXIT_FAILURE);
        }

        strcpy(executable_path, paths_head->data);
        strcat(executable_path, "/");
        strcat(executable_path, command[0]);

        if (stat(executable_path, &st) == 0)
        {
            if (execve(executable_path, command, environ) == -1)
            {
                // printf("\n=====2\n");
                free(executable_path);
                freeLinkedList(paths_head);
                free2DArrays(command);
                perror("execve");
                exit(EXIT_FAILURE);
            }
            // printf("\n=====3\n");
            free(executable_path);
            return;
        }
        // printf("\n=====4\n");
        paths_head = paths_head->next;
        free(executable_path);
    }

    _perror(command[0], command_number);
    exit(EXIT_FAILURE);
}
int main(void)
{
    char *line = NULL;
	size_t length = 0;
	ssize_t nread;
	pid_t child_pid;
	int command_number = 1;
	linked_paths *paths_head = generate_linked_paths_list();

    if (!paths_head)
        return (0);
 
	while (1)
	{
		write(STDOUT_FILENO, "$ ", 2);

		nread = getline(&line, &length, stdin);

		if (nread == -1)
        {
			perror("getline");
            break;
        }
		
		if (strcmp(line, "exit\n") == 0)
		{
			printf("Goodbay\n");
			break;
		}

		char **command = _splited_line(line);


        if (command[0] != 0)
        {

            child_pid = fork();
            
            if (child_pid == -1)
            {
                // free2DArrays(command);
                // freeLinkedList(paths_head);
                
                perror("fork");
                exit(EXIT_FAILURE);
            }

            if (child_pid == 0)
            {
                execute(command, paths_head, command_number);

                // printf("\n=====5\n");
                free2DArrays(command);
            }
            else
            {
                wait(NULL);
            }
            

        }
        
		command_number++;
        line = NULL;
	}
    freeLinkedList(paths_head);
	return (EXIT_SUCCESS); 

}
