#include "main.h"

/**
 * main - simple shell program
 * Return: 0 on exit success
 */

int main(void)
{
	/* getline parameters */
	FILE *stream = stdin;
	char *line;
	size_t len;
	int status = 0;

	/* for child process */
	pid_t cpid;

	/* to count the number of commands */
	static int counts;

	while (1)
	{
		printf("$: ");
		status = getline(&line, &len, stream);

		if (status == -1)
			break;
		counts++;

		if (strcmp(line, "exit\n") == 0)
			break;

		


	}
	return (0);
}
