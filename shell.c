#include "shell.h"
#include "utils.h"
#include "string_op.h"
#include "sys/wait.h"

/**
 * shell - Runs the shell in an infinite loop
 * @args: arguments array
 *
 * Return: execute status code
 */
int shell(char **args)
{
	int status_code = 0;
	unsigned int hist_count = 0;

	while (1)
	{
		char *line;
		size_t len = 0;

		hist_count++;

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

				status_code = execute(line, args, hist_count);
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
 * path_checker - parse command so it can run
 * Description: check if the command passed is and absolute path
 * to the executable , if not append command to path
 * @str: the command string
 * Return: NULL or the proper string
 *
 */
char *path_checker(char *str)
{
	if (_strncmp(str, "/", 1) == 0)
	{
		return (str);
	}
	return (NULL);
}

/**
 * execute - take the command string, tokenize it and
 * excute it in a new child process
 *
 * @line: the string containing the command
 * @args: arguments array
 * @hist_count: number of the current command
 *
 * Return: execute status code
 */
int execute(char *line, char **args, unsigned int hist_count)
{

	__pid_t pid;
	int wait_status;

	pid = fork();
	if (pid == 0)
	{
		char **c_args;
		char *command = path_checker(line);

		command = strip_newline(line);
		c_args = tokenize(command);

		execve(c_args[0], c_args, NULL);

		write_string(args[0]);
		write_string(": ");
		write_string(itoa(hist_count));
		write_string(": ");
		write_string(c_args[0]);
		write_string(": not found");
		write_char('\n');
	}
	if ((pid != 0) && (waitpid(pid, &wait_status, WEXITSTATUS(0)) == -1))
	{
		write_string("an error occured\n");
	}
	return (wait_status);
}
