#include "main.h"

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(int c)
{
    static char buffer[MAX_BUF_SIZE];

    static int i = 0;


    if (c == BUF_FLUSH || i >= MAX_BUF_SIZE)
    {
        write(1, buffer, MAX_BUF_SIZE);
        i = 0;
    }

    if (c != BUF_FLUSH)
    {
        buffer[i] = c;
        i++;
    }        

	return (1);
}


/**
* _puts - prints a string with newline
* @str: the string that we need to print
*
* Return: void
*/
int _puts(char *str)
{
	char *a = str;

	while (*str)
		_putchar(*str++);
	return (str - a);
}

/**
 * _strlen - return the length of a string
 * @s: the array of charachers
 *
 * Return: (int) the number of characters of a string
 */
int _strlen(char *s)
{
	int i;

	i = 0;

	while (s[i] != '\0')
	{
		i++;
	}

	return (i);
}


/**
* starts_with - chack if the haystack starts with needle
* @haystack: the string to be checked
* @needle: the substring to find
* Return : the next address of the haystack or null
*/
char *starts_with(const char *haystack, const char *needle)
{
	while (*haystack)
	{
		if (*haystack++  != *needle++)
		{
			return (NULL);
		}
	}

	return ((char *)haystack);
}

/**
 * _strcat - concatenates two strings.
 * @dest: where the reasult should be placed
 * @src: the string to be added to the string
 * Return:  pointer of the dest string
 */
char *_strcat(char *dest, char *src)
{
	while (*dest)
		*dest++;

	while(*str)
		*dest++ = *str++;
	*dest = *str;
	return (dest);	
}	
/**
 * _atoi - converts a string to an integer
 * @s: string to be converted
 *
 * Return: the int converted from the string
 */
int _atoi(char *s)
{
	int i, d, n, len, f, digit;

	i = 0;
	d = 0;
	n = 0;
	len = 0;
	f = 0;
	digit = 0;

	while (s[len] != '\0')
		len++;

	while (i < len && f == 0)
	{
		if (s[i] == '-')
			++d;

		if (s[i] >= '0' && s[i] <= '9')
		{
			digit = s[i] - '0';
			if (d % 2)
				digit = -digit;
			n = n * 10 + digit;
			f = 1;
			if (s[i + 1] < '0' || s[i + 1] > '9')
				break;
			f = 0;
		}
		i++;
	}

	if (f == 0)
		return (0);

	return (n);
}
