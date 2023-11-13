#include "shell.h"


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
 * *_strcpy - copies the string pointed to by src
 * including the terminating null byte (\0)
 * to the buffer pointed to by dest
 * @dest: pointer to the buffer in which we copy the string
 * @src: string to be copied
 *
 * Return: the pointer to dest
 */
char *_strcpy(char *dest, char *src)
{
	int i = 0;

    if (!src || dest == src)
        return (dest);

    while (*src)
    {
        dest[i] = src[i];
        i++;
    }
    
	return (dest);
}


/**
 * _strncpy - copiy a string
 * @dest: string with concatenation
 * @src: string to be concatenated
 * @n: size of second string
 * Return: pointer to the resulting string dest
 */
char *_strncpy(char *dest, char *src, int n)
{
	int i = 0;

	while (i < n && *(src + i) != '\0')
	{
		*(dest + i) = *(src + i);
		i++;
	}

	while (i < n)
	{
		*(dest + i) = '\0';
		i++;
	}

	return (dest);
}


/**
 * *_strdup - duplicate a string
 * @src: string to be duplicate
 *
 * Return: the pointer to dest
 */
char *_strdup(char *src)
{
    int i = 0;
    char *dest;

    if (!src)
        return (NULL);

    dest = malloc(sizeof(char) * _strlen(src) + 1);

    if (!dest)
        return (NULL);   
    
    while (src)
    {
        dest[i] = src[i];
        i++;
    }

    dest[i] = src[i];
    return (dest);   
}


/**
 * _strcat - concatenates two strings.
 * @dest: where the reasult should be placed
 * @src: the string to be added to the string
 * Return: Always 0.
 */
char *_strcat(char *dest, char *src)
{
    char *res = dest;
    
    while (*dest)
        dest++;
    while (*src)
        *dest++ = *src++;
    *dest = *src;
    return (res);
}


/**
 * _strncat - concatenate strings, defining the size of second string.
 * @dest: string with concatenation
 * @src: string to be concatenated
 * @n: size of second string
 * Return: pointer to the resulting string dest
 */
char *_strncat(char *dest, char *src, int n)
{
	int str1len = 0, str2len = 0;

	str1len = 0;
	str2len = 0;

	if (n <= 0)
		return (dest);

	while (*(dest + str1len) != '\0')
	{
		str1len++;
	}

	while (str2len < n && *(src + str2len) != '\0')
	{
		*(dest + str1len + str2len) = *(src + str2len);
		str2len++;
	}

	return (dest);
}
