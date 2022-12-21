#include "mystr.h"

/**
 * _strlen - calculate the length of a target str
 * @str: target string
 * Return: the length
 */
size_t _strlen(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
		;
	return (i);
}

/**
 * _strcmp - compare two strings
 * @str1: first str
 * @str2: second str
 * Return: the difference
 */

int _strcmp(char *str1, char *str2)
{
	size_t i;
	int diff = 0;

	for (i = 0; str1[i] != '\0' || str2[i] != '\0'; i++)
	{
		/* check is str2 is longer than str1 */
		if (!str1[i] && str2[i])
			return (-1);

		/* check if str1 is longer that str1 */
		if (str1[i] && !str2[i])
			return (1);
		/* calculate the difference between them */
		diff += str1[i] - str2[i];
	}

	if (diff < 0)
		return (-1);
	if (diff > 0)
		return (1);
	return (0);
}

/**
 * _strncmp - compare two strings
 * @str1: first str
 * @str2: second str
 * @n: string length to compare
 * Return: the difference
 */

int _strncmp(char *str1, char *str2, size_t n)
{
	size_t i;
	int diff = 0;

	for (i = 0; (str1[i] != '\0' || str2[i] != '\0') || i < n; i++)
	{
		/* check is str2 is longer than str1 */
		if (!str1[i] && str2[i])
			return (-1);

		/* check if str1 is longer that str1 */
		if (str1[i] && !str2[i])
			return (1);
		/* calculate the difference between them */
		diff += str1[i] - str2[i];
	}

	if (diff < 0)
		return (-1);
	if (diff > 0)
		return (1);
	return (0);
}

/**
 * _strcpy - copy two string
 * @dest: destination of the copy
 * @src:  source of the copy
 * Return: a character array
 */
char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}
	dest[i] = '\0';
	return (dest);
}

/**
 * _strncpy - copy two string
 * @dest: destination of the copy
 * @src:  source of the copy
 * @n: length of copy
 * Return: a character array
 */
char *_strncpy(char *dest, char *src, size_t n)
{
	size_t i;

	for (i = 0; src[i] != '\0' && i < n; i++)
	{
		dest[i] = src[i];
	}
	dest[i] = '\0';
	return (dest);
}
