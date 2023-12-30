#include "shell.h"
#include "string_op.h"

/**
 * main - entry point
 * @argc: arguments count
 * @args: arguments array
 * Return: 0 on success
 */
int main(int argc, char **args)
{

	(void)argc;

	if (isatty(STDIN_FILENO) == 1)
	{
		shell(args);
	}
	else
	{
		shell(args);
	}
	return (0);
}
