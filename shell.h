#ifndef SHELL_H
#define SHELL_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>

int shell(char **);

int execute(char *, char **, unsigned int);

#endif /*SHELL_H*/
