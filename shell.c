#include "shell.h"
#include "utils.h"
#include "string_op.h"

/**
 * shell - Runs the shell in an infinite loop
 *
 */
void shell(void)
{
	while (1)
	{
		char *line;
		size_t len = 0;

		write_string("($): ");
		if (getline(&line, &len, stdin) != -1)
		{
			if (_strcmp(line, "exit\n") == 0)
			{
				free(line);
				exit(0);
			}
			execute(line);
			free(line);
		}
		else
		{
			free(line);

			break;
		}
	}
}

/**
 * execute - take the command string, tokenize it and
 * excute it in a new child process
 *
 * @line: the string containing the command
 */
void execute(char *line)
{

	__pid_t pid;
	int wait_status;

	pid = fork();
	if (pid == 0)
	{
		char *command = strip_newline(line);
		char **c_args = tokenize(command);

		if (execve(c_args[0], c_args, NULL) == -1)
		{
			perror("hsh");
			_exit(-1);
		};
	}
	if ((pid != 0) && (wait(&wait_status) == -1))
	{
		write_string("an error occured\n");
	}
}
