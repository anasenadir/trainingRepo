#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv, char **env)
{
	extern char **environ;
	
	printf("the address of env is => %p\n", env);
	printf("the address of environ is  => %p\n", environ);
	
	return (EXIT_SUCCESS);
}
