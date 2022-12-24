#include "main.h"

/**
 * main - simple shell program
 * @ac: arguments count
 * @av: arguments array
 * Return: 0 on exit success
 */

int main(__attribute__((unused)) int ac, char **av)
{
	FILE *stream = stdin;
	char *line = NULL, *command = NULL, *arguments[10] = {NULL};
	size_t len = 0;
	int status = 0, i, counts = 0, exec_status = 0, b_in;
	__pid_t cpid = 0, wstatus = 0;

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
		b_in = check_builtin(command);
		if (b_in)
			continue;
		cpid = fork();
		if (cpid == -1)
			break;
		if (cpid == 0)
		{
			exec_status = execve(command, arguments, environ);

			if (exec_status == -1)
			{
				exec_error(command, av, counts);
				if (line != NULL)
					free(line);
				_exit(1);
			}
		}
		else
		{
			wait(&wstatus);
			if (WIFEXITED(wstatus))
				exec_status = WEXITSTATUS(wstatus);
			if (!WIFEXITED(wstatus))
				kill(cpid, 9);
		}
	}
	for (i = 0; arguments[i] != NULL; i++)
		;
	if (line != NULL)
		free(line);
	return (exec_status);
}
