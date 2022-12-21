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
	int i, diff = 0;

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
