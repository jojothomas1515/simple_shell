#include "shell.h"
#include "utils.h"

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
