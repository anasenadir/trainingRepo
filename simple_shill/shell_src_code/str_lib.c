#include "main.h"
int _strlen(char *str)
{
        int len = 0;

        if (!str || str == "")
                return (0);

        while (str[len] != '\0')
                len++;
        return (len);
}

char **_splited_line(char *line)
{
	char **array = NULL;
	int index = 0;
	char *current;

	array = malloc(sizeof(char *));

	if (!array)
		perror("memory allocation failed"),exit(EXIT_FAILURE);
	array[index] = strtok(line, " \n\t");

	while ((current = strtok(NULL, " \n\t")) != NULL)
	{
		index++;
		array = realloc(array, (index + 1) * sizeof(char *));

		if (!array)
			perror("memory reallocation failed"), exit(EXIT_FAILURE);
		array[index] = current;
	}

	index++;
	array = realloc(array, (index + 1) * sizeof(char *));

	if (!array)
		perror("memory reallocation failed for null termination"), exit(EXIT_FAILURE);

	array[index] = NULL;

	return (array);
}


int _str_exist(char *src, char ch)
{
	while (*src)
	{
		if (*src == ch)
			return (1);
		src++;
	}
	return (0);
}


char *_itoc(int num)
{
	char *result;
	int numDigits = 0;
	int temp = num;
	
	while (temp  > 0)
	{
		temp = temp / 10;
		numDigits++;
	}

	result = malloc(sizeof(char) * (numDigits + 1));
	if (!result)
		return (NULL);

	result[numDigits] = '\0';


	for (int i = numDigits - 1; i >= 0; i--) {
        result[i] = '0' + (num % 10); // Convert each digit to a character
        num /= 10;
    }

	return (result);
}
/*

_itoc // integer to char
_strcpy // string copy
_strdup // copy a string using malloc
_strcmp // comparing two strings
_strncmp // comparing n character of two strings
_strcat // concatinate two strings

*/
