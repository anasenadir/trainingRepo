#include "main.h"
#include <stdio.h>
#include <stdlib.h>


char *generate_env_val(const char *name, const char *value)
{
	int name_len = _strlen(name);
       	int value_len = _strlen(value);
	size_t result_len = name_len + 1 + value_len+ 1;

	char *result = malloc(result_len * sizeof (char *));
	
	if (!result)
	{
		fprintf(stderr, "memory allcoation failed");
		exit(EXIT_FAILURE);
	}
	
	strncpy(result, name, name_len);

	result[name_len] = '=';
	
	strncpy(result + name_len + 1, value, value_len);

	result[result_len - 1] = '\0';
	return (result);
}	
int _setenv(const char *name, const char *value, int overwrite)
{
	char *is_exist = _getenv(name);
	char *result = generate_env_val(name, value);
	extern char **environ;
	int environ_len = 0, index = 0;
	
	while (environ[environ_len] != NULL)
		environ_len++;


	if (is_exist == "" || overwrite)
	{
			
		/*if the env var  exist*/
		if (is_exit != "")
		{
			while (environ[index] != NULL)
			{
				if (strncmp(environ[index], name, _strlen(name)) == 0)
				{
					free(environ[index]);
					environ[index] = result;
					return (0);
				}
			}
		}
		/*if the env var doesn't exist*/
		else
		{
			environ[environ_len] = result;
			environ[environ_len + 1] = NULL;
			return (0);
		}


	}
	return (0);
}
