#include "errors.h"

/**
 * exec_error - compile and print error message
 * @command: command executed
 * @av:arguments variable
 * @counts: hist count
 */

void exec_error(char *command, char **av, int counts)
{
	char err_msg[100], *hist;

	hist = _itoa(counts);
	_strcpy(err_msg, av[0]);
	_strcat(err_msg, ": ");
	_strcat(err_msg, hist);
	_strcat(err_msg, ": ");
	_strcat(err_msg, command);
	_strcat(err_msg, ": not found\n");
	write(2, err_msg, _strlen(err_msg));
	free(hist);
}
