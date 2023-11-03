#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>


char *_getenv(const char *name)
{
	extern char **environ;
	int i;
	char *current;
	i = 0;

	while (environ[i] != NULL)
	{
		current = strtok(environ[i], "=");
		if(strcmp(current, name) == 0)
			return (strtok(NULL, "="));
		i++;
	}
	return ("");
}
int main(int argc, char **argv)
{
	char *value;

	if (argc != 2)
	{
		printf("Arguments Error\n");
		exit(EXIT_FAILURE);
	}
	value = _getenv(argv[1]);

	printf("the value of %s is \n", argv[1]);
	printf("%s\n", value);
}
