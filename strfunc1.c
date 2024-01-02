#include "string_op.h"

/**
 * _strncmp - compare string by number of index specified
 *
 * @s1: string one
 * @s2: string two
 * @size: the number of characters to compare
 *
 * Return: 0 if both strings are the same, else return any signed int
 */
int _strncmp(char *s1, char *s2, unsigned int size)
{
	int result = 0;
	int i;

	if ((s1 == NULL) || (s2 == NULL))
	{
		return (-1);
	}

	for (i = 0; (i < (int)size) && (s1[i] != '\0') && (s2[i] != '\0'); i++)
	{
		result += s1[i] - s2[i];
	}

	return (result);
}