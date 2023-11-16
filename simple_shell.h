#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H

/*HEADERS*/
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/stat.h>
#include <ctype.h>

/*MACROS*/
#define MAX_CMD_LENGTH 100
#define BUFFER_SIZE 1024

extern char **environ;

/*PROTOTYPES & STRING HELPERS*/
int _atoi(const char *inputString);
int _isspace(char ch);
int _isdigit(char ch);
void _printf(const char *form, ...);
char *_getf(char *inputString, int maxSize, FILE *inputStream);
int _strcmp(const char *str1, const char *str2);
char *_getline(char *buffer, size_t maxSize, FILE *inputStream);
char *_strtok(char *inputString, const char *delim, char **saveptr);
char *_strchr(char *s, char character);
int _strlen(char *s);

/*ENVIRON VARIABLES*/
int _setenv(char **argv);
int _unsetenv(char *name);
void _env(char **env);

#endif
