#include "simple_shell.h"

char *_getline(char *buffer, size_t size, FILE *stream)
{
	int ch;
	size_t i = 0;
	static char input_buffer[BUFFER_SIZE];
	static size_t buffer_position;

	if (buffer == NULL || size == 0 || stream == NULL)
		return (NULL);

	while (1)
	{
		if (buffer_position == 0)
		{
			ssize_t bytes_read = read(STDIN_FILENO, input_buffer, BUFFER_SIZE);
			if (bytes_read <= 0)
				return (NULL);

			buffer_position = (size_t)bytes_read;
		}

		while (i < size - 1)
		{
			ch = input_buffer[buffer_position++];
			buffer[i++] = ch;
			if (ch == '\n' || ch == '\0')
			{
				buffer[i] = '\0';
				return (buffer);
			}
		}
	}
}

int main(void)
{
	char command[MAX_CMD_LENGTH];

	while (1)
	{
		_printf("simple_shell$ ");
		fflush(stdout);

		if (*_getline(command, MAX_CMD_LENGTH, stdin) == NULL)
		{
			_printf("\nExiting simple shell...\n");
			break;
		}

		char *newline = strtok(command, "\n");

		if (newline == NULL)
			continue;

		if (_strcmp(newline, "emv") == 0)
		{
			char **env = environ;
			while (*env != NULL)
			{
				_printf("%s\n", *env);
				env++;
			}
			continue;
		}

		if (_strcmp(newline, "exit") == 0)
			break;

		pid_t pid = fork();

		if (pid < 0)
		{
			perror("Fork failed");
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
