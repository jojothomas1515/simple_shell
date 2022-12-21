#include "main.h"

int stop_check(int *, char *);
char *tokenize(char *);
int whitespace(char *);

/**
 * main - simple shell program
 * Return: 0 on exit success
 */

int main(int ac, char **av)
{
	/* getline parameters */
	FILE *stream = stdin;
	char *line, *command;
	size_t len;
	int status = 0;
	/* for child process */
	__pid_t cpid, wstatus;
	int exec_status;
	char err_msg[100];
	/* to count the number of commands */
	static int counts;
	/* for execve */
	char *arguments[] = {NULL};

	(void)ac;

	while (1)
	{
		printf("($) ");
		status = getline(&line, &len, stream);
		stop_check(&status, line) == -1 ? exit(EXIT_SUCCESS) : (void)NULL;
		counts++;

		if (whitespace(line))
			continue;
		command = tokenize(line);

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
				sprintf(err_msg, "%s: %d: %s",av[0], counts, command);
				perror(err_msg);
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

	if (strcmp(line, "exit\n") == 0)
		return (-1);

	return (0);
}
/**
 * tokenize - split stdin string to tokens of command and arguments
 * @line: string from stdin
 *
 */
char *tokenize(char *line)
{
	char *arr;

	arr = strtok(line, " ");
	arr = strtok(line, "\n");

	return (arr);
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
