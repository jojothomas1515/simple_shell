#include "main.h"

int stop_check(int *, char *);
char *tokenize(char *, char **);
int whitespace(char *);

/**
 * main - simple shell program
 * @ac: arguments count
 * @av: arguments array
 * Return: 0 on exit success
 */

int main(int ac, char **av)
{
	/* getline parameters */
	FILE *stream = stdin;
	char *line = NULL, *command = NULL;
	size_t len = 0;
	int status = 0, i;
	/* for child process */
	__pid_t cpid = 0, wstatus = 0;
	int exec_status = 0;
	char err_msg[100], *hist;
	/* to count the number of commands */
	static int counts = 0;
	/* for execve */
	char *arguments[10] = {NULL};

	(void)ac;
	while (1)
	{
		isatty(STDIN_FILENO) ? write(STDIN_FILENO, "$ ", 3) : 0;
		status = getline(&line, &len, stream);
		if (stop_check(&status, line) == -1)
			break;
		counts++;

		if (whitespace(line))
			continue;
		command = tokenize(line, arguments);

		cpid = fork();

		if (cpid == -1)
		{
			perror("sh: ");
			break;
		}
		if (cpid == 0)
		{
			exec_status = execve(command, arguments, environ);
			if (exec_status == -1)
			{
				hist = _itoa(counts);
				_strcpy(err_msg, av[0]);
				_strcat(err_msg, ": ");
				_strcat(err_msg, hist);
				_strcat(err_msg, ": ");
				_strcat(err_msg, command);
				_strcat(err_msg, ": not found\n");
				write(2, err_msg, _strlen(err_msg));
				free(hist);
				free(line);
				_exit(errno);
			}
		}
		else
		{
			wait(&wstatus);
			if (wstatus != 0)
				kill(cpid, 9);
		}
	}

	for (i = 0; arguments[i] != NULL; i++)
		free(arguments[i]);
	return (0);
}

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
