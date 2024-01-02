#ifndef STRING_OP_H
#define STRING_OP_H

#include "shell.h"
#include "utils.h"

size_t _strlen(char *);

char *strip_newline(char *);

int _strcmp(char *, char *);

char *_strrev(char *);

char *itoa(int);

int _strncmp(char *, char *, unsigned int);

#endif /* STRING_OP_H */
