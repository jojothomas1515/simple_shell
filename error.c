#include "errors.h"

/**
 * exec_error - compile and print error message
 * @cm: command executed
 * @hist
*/

void exec_error(char *cm, char *hist, char **av, char *err_msg, int c)
{
        hist = _itoa(c);
        _strcpy(err_msg, av[0]);
        _strcat(err_msg, ": ");
        _strcat(err_msg, hist);
        _strcat(err_msg, ": ");
        _strcat(err_msg, cm);
        _strcat(err_msg, ": not found\n");
        write(2, err_msg, _strlen(err_msg));
        
}
