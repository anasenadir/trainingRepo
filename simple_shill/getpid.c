#include <stdio.h>
#include <unistd.h>

int main(void)
{
	pid_t my_current_pid;

	my_current_pid = getpid();
	printf("%u", my_current_pid);
	return(0);
}
