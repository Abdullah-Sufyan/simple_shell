#include "simple_shell.h"

/**
 * cmd_pathfinder - Get the cmd path from environment
 * @cmd: the cmd
 *
 * Return: path to the cmd, NULL if not found
 */
char *cmd_pathfinder(char *cmd)
{
	char *path = NULL, *path_copy = NULL, *file_path = NULL;
	char *token = NULL;
	int cmd_len = 0, dir_len = 0;
	struct stat fileState;

	path = getenv("PATH");
	if (!path)
		return (NULL);

	path_copy = strdup(path);
	cmd_len = _strlen(cmd);
	token = strtok(path_copy, ":");

	while (token != NULL)
	{
		dir_len = _strlen(token);
		file_path = malloc(cmd_len + dir_len + 2);
		if (!file_path)
		{
			free(path_copy);
			return (NULL);
		}

		strcpy(file_path, token);
		strcat(file_path, "/");
		strcat(file_path, cmd);
		strcat(file_path, "\0");

		if (stat(file_path, &fileState) == 0)
		{
			free(path_copy);
			return (file_path);
		}
		else
		{
			free(file_path);
			token = strtok(NULL, ":");
		}
	}

	free(path_copy);
	if (stat(cmd, &fileState) != 0)
		return (NULL);

	return (cmd);
}
