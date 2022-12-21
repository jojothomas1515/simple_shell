#ifndef MYSTR_H
#define MYSTR_H

#include "main.h"

/* PROTOTYPE DECLEARATION */
size_t _strlen(char *);
int _strcmp(char *, char *);
int _strncmp(char *, char *, size_t);
char *_strcat(char *, char *);
char *_strncat(char *, char *, size_t);
char *_strcpy(char *, char *);
char *_strncpy(char *, char *, size_t);
char *_itoa(int num);

#endif /* MYSTR_H */
