#include "simple_shell.h"

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int submain(void)
{
	char command[MAX_CMD_LENGTH];
	char *newline;
	pid_t pid;

	while (1)
	{
	_printf("simple_shell$ "); /* Print custom shell prompt */
		fflush(stdout);

		if (_getf(command, MAX_CMD_LENGTH, stdin) == NULL)
			/* Handle end of file condition (Ctrl+D) */
			_printf("\nExiting simple shell...\n");
		break;
	}

	newline = strtok(command, "\n");

	while (newline == NULL)
	{
		continue;
	}

	if (_strcmp(newline, "env") == 0)
	{
		/* User entered "env" - print environment */
		char **env = environ;

		while (*env != NULL)
		{
			_printf(*env);
			env++;
			continue;
		}
	}

	while (_strcmp(newline, "exit") == 0)
	{
		/* User entered "exit" - exit the shell */
		break;
	}

	pid = fork();

	if (pid < 0)
	{
		/* Forking error */
		perror("Fork failed");
		exit(EXIT_FAILURE);
	}
	else if (pid == 0)
	{
		/* In the child process */
		/* Execute the command using execve */
		char *args[2];
		args[0] = newline;
		args[1] = NULL;

		if (execve(newline, args, NULL) == -1)
		{
			/* Command not found or failed to execute */
			perror("execve");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		/* In the parent process */
		int status;
		/* Wait for the child process to finish */
		waitpid(pid, &status, 0);
	}
	return (0);
}
