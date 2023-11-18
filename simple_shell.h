#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H

/*HEADERS*/
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <ctype.h>
#include <string.h>

/*MACROS*/
#define MAX_CMD_LENGTH 100
#define BUFFER_SIZE 1024
#define MAX_EN_VAR 101

extern char **environ;

/*PROTOTYPES & STRING HELPERS*/
int _atoi(const char *inputString);
int _isspace(char c);
int _isdigit(char c);
void _printf(const char *form, ...);
char *_getf(char *inputString, int maxSize, FILE *inputStream);
int _strcmp(const char *stringA, const char *stringB);
char *_getline(char *buffer, size_t maxSize, FILE *inputStream);
char *_strtok(char *inputString, const char *delimiter, char **pointer);
char *_strchr(const char *inputString, char character);
int _strlen(const char *inputString);

/*ENVIRON VARIABLES*/
int _setenv(char **argv);
int _unsetenv(char *name);
void _env(char **env);

#endif
