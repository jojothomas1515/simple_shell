#include "mystr.h"

/**
 * _strcat - concatenate to strings
 * @dest: destination string
 * @src: src string
 * Return: pointer to destination string
 */

char *_strcat(char *dest, char *src)
{
	int c, j;

	for (c = 0; dest[c] != '\0'; c++)
		;

	for (j = 0; src[j] != '\0'; j++)
		dest[c + j] = src[j];
	dest[c + j] = '\0';

	return (dest);
}

/**
 * _strncat - concatenate to strings
 * @dest: destination string
 * @src: src string
 * @n: concat length
 * Return: pointer to destination string
 */

char *_strncat(char *dest, char *src, size_t n)
{
	size_t c, j;

	for (c = 0; dest[c] != '\0'; c++)
		;

	for (j = 0; src[j] != '\0' && j < n; j++)
		dest[c + j] = src[j];
	dest[c + j] = '\0';

	return (dest);
}

/**
 * num_length - the lenght of a number as string
 * @num: target number
 * Return: length
 */

int num_length(int num)
{
	int n = 0;

	if (num < 0)
		n++;
	while (num > 0)
	{
		num /= 10;
		n++;
	}
	return (n);
}

/**
 * _itoa - convert integer to string
 * @num: num to convert
 * Return: a string
 */

char *_itoa(int num)
{
	int len = num_length(num), i = len - 1;
	char *str = malloc(sizeof(char) * (len + 1));

	if (str == NULL)
		return (NULL);
	str[len] = '\0';

	while (i != -1)
	{
		str[i] = (num % 10) + '0';
		num /= 10;
		i--;
	}
	return (str);
}
