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

/*OTHER INCLUDES AND DEFINITIONS*/
typedef struct
{
	int cmdBufType;
	int status;
}
info_t;


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
char *_strdup(const char *inputString);
char *cmd_pathfinder(char *cmd);
int freePointer(void **pointer);
char *_setMemory(char *memBlock, char byteVal, unsigned int bytesNum);
void freeStringArray(char **strArray);
void *_memrealloc(void *prevBlock, unsigned int prevSize, unsigned int newSize);
void continueChain(info_t *info, char *buffer, size_t *pos,
		size_t startIndex, size_t length);
int replaceAlias(info_t *info);
int replaceVariables(info_t *info);
int replaceStr(char **oldStr, char *newStr);
int display_history(info_t *info);
int unset_alias(info_t *info, char *str);
int set_alias(info_t *info, char *str);
int print_alias(list_t *node);
int manage_alias(info_t *info);

/*ENVIRON VARIABLES*/
int _setenv(char **argv);
int _unsetenv(char *name);
void _env(char **env);

#endif
