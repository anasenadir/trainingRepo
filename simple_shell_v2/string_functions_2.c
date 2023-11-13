#include "shell.h"


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
* _putchar - print the char c to the screan
* @c: The char c to be printed
* Return: On Success 1.
* on failure: -1 is returned
*/
int _putchar(int c)
{
	static int i;
	static char buffer[OUT_BUF_SIZE];

	if (c == BUF_FLUSH || i >= OUT_BUF_SIZE)
	{
		write(1, buffer, i);
		i = 0;
	}

	if (c != BUF_FLUSH)
		buffer[i++] = c;
	return (1);
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


/**
 * _itoa - converts a integer to an string
 * @i: int to be converted
 *
 * Return: the int converted from the string
 */
char* _itoa(int i) {
    int digit_num = 0;
    int temp;
    char *result;
    int is_negative = 0;

    if (!i || i == 0) {
        return (NULL);
    }

    if (i < 0) {
        i = -i;
        is_negative = 1;
    }

    temp = i;
    while (temp >= 1) {
        digit_num++;
        temp /= 10;
    }

    if (is_negative)
        digit_num++;

    temp = digit_num;

    result = malloc(sizeof(char ) * digit_num);
    if (!result)
        return (NULL);

    while (digit_num > 0) {
        if (is_negative && digit_num == 1) {
            result[--digit_num] = '0';
            break;
        }

        result[--digit_num] = (i % 10) + '0';
        i /= 10;
    }

    result[temp] = '\0';
    return (result);
}
