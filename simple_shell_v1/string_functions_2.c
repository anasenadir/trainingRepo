#include "main.h"

/**
 * _strcat - concatenates two strings.
 * @dest: where the reasult should be placed
 * @src: the string to be added to the string
 * Return: Always 0.
 */
char *_strcat(char *dest, char *src)
{
	int str1len, str2len;

	str1len = 0;
	str2len = 0;

	while (*(dest + str1len) != '\0')
	{
		str1len++;
	}

	while (*(src + str2len) != '\0')
	{
		*(dest + str1len) = *(src + str2len);
		str1len++;
		str2len++;
	}

	*(dest + str1len) = '\0';

	return (dest);
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

/**
 * _strcmp - compare 2 strings.
 * @s1: string to be compared.
 * @s2: string for comparation.
 * Return: Difference.
 */
int _strcmp(char *s1, char *s2)
{
	int i = 0, s1char, s2char;


	while (s1[i] != '\0' || s2[i] != '\0')
	{
		if (*(s1 + i) != *(s2 + i))
		{
			s1char = *(s1 + i);
			s2char = *(s2 + i);
			return (s1char - s2char);
		}
		i++;
	}

	return (0);
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
