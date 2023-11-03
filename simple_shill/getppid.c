#include <stdio.h>
#include <unistd.h>

int main(void)
{
	pid_t my_pid, my_parent_pid;

	my_pid = getpid();
	my_parent_pid = getppid();

	printf("my current pid = %u\n", my_pid);
	printf("my parent ppid = %u\n", my_parent_pid);
	return (0);
}
