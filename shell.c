#include "shell.h"

void shell()
{
    while (1)
    {
        char *line;
        size_t len = 0;

        printf("hsh: ");
        if (getline(&line, &len, stdin) != -1)
        {

            printf("the arg passed is %s", line);

            free(line);
        }
        else
        {
            free(line);

            break;
        }
    }
}