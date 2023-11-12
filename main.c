#include "shell.h"

/**
 * main - entry point
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
