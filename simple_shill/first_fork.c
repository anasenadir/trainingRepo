#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void)
{
	pid_t my_pid;
	pid_t child_pid;

	printf("Before fork\n");
	child_pid = fork();

	if (child_pid == -1)
		perror("fork"), exit(EXIT_FAILURE);
	if (child_pid == 0)
		printf("this is the child process => %u\n", getpid());
	else
	{
		wait(NULL);
		printf("this is the process id of the parent => %u, and child pid => %u\n", getpid(), child_pid);
	}
	printf("after fork\n");
	return (EXIT_SUCCESS);
}
