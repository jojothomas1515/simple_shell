#include "shell.h"
#include "utils.h"
#include "string_op.h"

/**
 * shell - Runs the shell in an infinite loop
 * @args: arguments array
 *
 * Return: execute status code
 */
int shell(char **args)
{
	int status_code = 0;

	while (1)
	{
		char *line;
		size_t len = 0;

		write_string("($) ");
		if (getline(&line, &len, stdin) != -1)
		{
			if (_strcmp(line, "exit\n") == 0)
			{
				free(line);
				_exit(0);
			}
			if (strcmp(line, "\n") != 0)
			{
				status_code = execute(line, args);
			}
			free(line);
		}
		else
		{
			free(line);

			break;
		}
	}

	return (status_code);
}

/**
 * execute - take the command string, tokenize it and
 * excute it in a new child process
 *
 * @line: the string containing the command
 * @args: arguments array
 *
 * Return: execute status code
 */
int execute(char *line, char **args)
{

	__pid_t pid;
	int wait_status;
	int execute_status;

	pid = fork();
	if (pid == 0)
	{
		char *command = strip_newline(line);
		char **c_args = tokenize(command);

		execute_status = execve(c_args[0], c_args, NULL);

		if (execute_status == -1)
		{
			perror(args[0]);
			_exit(-1);
		};
	}
	if ((pid != 0) && (wait(&wait_status) == -1))
	{
		write_string("an error occured\n");
	}

	return (execute_status);
}
