#include "shell.h"
#include "utils.h"
#include "string_op.h"

/**
 * tokenize - take a string and tokenize it using ''(space) as the delimeter
 * @line: string to tokenize
 *
 * Return: an array of token
 */
char **tokenize(char *line)
{
	int i;
	char **arr = malloc(sizeof(char *) * 10);
	char *command = strtok(line, " ");

	arr[0] = command;

	for (i = 1; (arr[i] = strtok(NULL, " ")) != NULL; i++)
		;

	return (arr);
}

/**
 * write_string - print out string to the standard output
 *
 * @str: the string to write out
 *
 * Return: size of what was written
 */
ssize_t write_string(char *str)
{
	int len;

	if (str == NULL)
		return (0);
	len = _strlen(str);

	return (write(0, str, len));
}
/**
 * write_char - print out a single character to the standard output
 *
 * @c: the character to write out
 *
 * Return: size of what was written
 */
ssize_t write_char(char c)
{
	return (write(0, &c, 1));
}
