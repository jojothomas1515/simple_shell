#include "shell.h"
#include "string_op.h"

/**
 * main - entry point
 * Return: 0 on success
 */
int main(void)
{

	if (isatty(STDIN_FILENO) == 1)
	{
		shell();
	}
	else
	{
		shell();
	}
	return (0);
}
