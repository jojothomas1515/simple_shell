#ifndef MAIN_H
#define MAIN_H

/* includes */
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <errno.h>

/* my includes */
#include "mystr.h"
#include "errors.h"

/* global variable */
extern char **environ;

/* parsers */
int stop_check(int *, char *);
char *tokenize(char *, char **);
int whitespace(char *);

/* structures */

typedef struct paths
{
	char *key;
	char *value;
	struct paths *next;
} paths_t;

typedef struct OPS
{
	char *arr;
	void (*func)();
} opt_t;

/* builtins */
void print_env(void);

/* builtin function pointers */
int check_builtin(char *arg);

#endif /* MAIN_H */
