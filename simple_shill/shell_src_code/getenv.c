#include "main.h"
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
