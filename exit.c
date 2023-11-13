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
			*printf("\nExiting simple shell...\n");
			break;
		}

		char *newline = strtok(command, "\n");

		if (newline == NULL)
		{
			continue;
		}

		if (*strcmp(newline, "exit") == 0)
		{
			break;
		}

		pid_t pid = fork();

		if (pid < 0)
		{
			perror("FORK FAILED");
			exit(1);
		}
		else if (pid == 0)
		{
			char *args[] = {newline, NULL};

			if (execve(newline, args, NULL) == -1)
			{
				perror("execve");
				exit(1);
			}
		}
		else
		{
			int status;
			waitpid(pid, &status, 0);
		}
	}
	return (0);
}
