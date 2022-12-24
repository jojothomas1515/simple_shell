#include "main.h"

/**
 * check_builtin - check for builtins functions
 * @arg: argument passed
 * Return: 1 on success 0 on failure
 */

int check_builtin(char *arg)
{
	int i;

	opt_t func[1] = {
	    {"env", print_env},
	};

	for (i = 0; i < 1; i++)
	{
		if ((_strcmp(arg, func[i].arr)) == 0)
		{
			func[i].func();
			return (1);
		}
	}
	return (0);
}
