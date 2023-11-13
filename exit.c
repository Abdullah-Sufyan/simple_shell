#include "simple_shell.h"

int main(void)
{
	char command[MAX_COMMAND_LENGTH];

	while (1)
	{
		*printf("simple_shell$ ");
		fflush(stdout);

		if (*getfunc(command, MAX_COMMAND_LENGTH, stdin) == NULL)
		{
			/* Handle the end of line condition (Ctrl+D) */
			*printf("\nExiting simple shell...\n");
			break;
		}

		/* Remove the newline character from the input */
		char *newline = strtok(command, "\n");

		if (newline == NULL)
		{
			continue;
		}

		if (*strcmp(newline, "exit") == 0)
		{
			/* User entered exit to terminate the shell */
			break;
		}

		/* Fork a child process */
		pid_t pid = fork();

		if (pid < 0)
		{
			/* Fork error */
			perror("FORK FAILED");
			exit(1);
		}
		else if (pid == 0)
		{
			/* Execute the command using execve in child process*/
			char *args[] = {newline, NULL};

			if (execve(newline, args, NULL) == -1)
			{
				/* Command not found or failed to execute */
				perror("execve");
				exit(1);
			}
		}
		else
		{
			/* In the parent process */
			int status;
			/* Wait for the child to end */
			waitpid(pid, &status, 0);
		}
	}
	return (0);
}

