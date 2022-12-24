#include "main.h"

/**
 * print_env - print the current enviromental variables
 */
void print_env(void)
{
	int i = 0;
	int len = 0;

	for (i = 0; environ[i]; i++)
	{
		len = _strlen(environ[i]);
		write(1, environ[i], len);
		write(1, "\n", 1);
	}
}
