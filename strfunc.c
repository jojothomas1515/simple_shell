#include "string_op.h"

/**
 * strip_newline - removes newline character from the end of the string
 * Note: This function free the memorry of str
 *
 * @str: the string to be striped of newline character
 * Return: new string
 */
char *strip_newline(char *str)
{
	int i;
	size_t len = _strlen(str);
	char *new_str = malloc(sizeof(char) * ((int)len - 1));

	for (i = 0; str[i] != '\0'; i++)
	{
		if (str[i] != '\n')
		{
			new_str[i] = str[i];
		}
		else
		{
			new_str[i] = '\0';
		}
	}
	free(str);
	return (new_str);
}

/**
 * _strlen - calculate the length of string
 * @str: target string
 * Return: length of the string
 */
size_t _strlen(char *str)
{
	size_t i;

	if (str == NULL)
		return (0);

	for (i = 0; str[i] != '\0'; i++)
		;
	return (i);
}

/**
 * _strcmp - Test if the two string are identical
 * @str1: target 1
 * @str2: target 2
 * Return: 0 if both strings are identical
 */
int _strcmp(char *str1, char *str2)
{
	int i;
	int len1, len2;

	if (str1 == NULL || str2 == NULL)
	{
		return (-1);
	}

	len1 = _strlen(str1);
	len2 = _strlen(str2);

	if (len1 != len2)
	{
		return (-1);
	}

	for (i = 0; i < len1; i++)
	{
		if ((int)(str1[i] - str2[i]) != 0)
		{
			return ((int)(str1[i] - str2[i]));
		}
	}

	return (0);
}

/**
 * itoa - convert int to string (char*)
 * @num: number to convert
 * Return: char *
 */
char *itoa(int num)
{
	char *val;
	int malloc_size = 0;
	int temp_num = num, index, mod_val;

	for (; (temp_num /= 10) != 0;)
	{
		malloc_size++;
	}

	val = malloc((malloc_size + 1) * sizeof(char));
	if (val == NULL)
	{
		return (NULL);
	}
	temp_num = num;

	for (index = 0; temp_num != 0; index++)
	{
		mod_val = temp_num % 10;
		val[index] = mod_val + '0';
		temp_num /= 10;
	}
	val[index] = '\0';

	return (_strrev(val));
}

/**
 * _strrev - reverse string
 * @str: string to be reversed
 * Return: reversed string
 */
char *_strrev(char *str)
{
	int len = strlen(str);
	int i;
	char temp;

	for (i = 0; i < (len / 2); i++)
	{
		temp = str[len - (i + 1)];
		str[len - (i + 1)] = str[i];
		str[i] = temp;
	}

	return (str);
}
