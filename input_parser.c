#include "main.h"

/**
 * stop_check - checks the EOF or exit
 * @status: getline status is -1 on EOF
 * or len og argument read on stdin
 * @line: stdin string
 * Return: 0 to continue, 1 to stop
 */
int stop_check(int *status, char *line)
{
	if (*status == -1)
		return (-1);

	if (_strcmp(line, "exit\n") == 0)
		return (-1);

	return (0);
}
/**
 * tokenize - split stdin string to tokens of command and arguments
 * @line: string from stdin
 * @args: argrument array to puth all tokens
 * Return: address of the command
 */
char *tokenize(char *line, char **args)
{
	char *arr;
	int i = 1;

	args[0] = strtok(line, " ");

	while ((arr = strtok(NULL, " ")) != NULL)
	{
		args[i++] = arr;
	}
	args[i] = NULL;

	for (i = 0; args[i] != NULL; i++)
		args[i] = strtok(args[i], "\n");

	return (args[0]);
}

/**
 * whitespace - checks if the stdin string passed is only
 * whitespace of newline
 * @line: string from stdin
 * Return: 0 if the entire string is not only whitespace on newline
 */

int whitespace(char *line)
{
	int i, skip_flag;

	for (i = 0; line[i] != '\0'; i++)
	{
		if (line[i] == ' ' || line[i] == '\n')
			skip_flag = 1;
		else
		{
			skip_flag = 0;
			break;
		}
	}

	return (skip_flag);
}
