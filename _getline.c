#include "simple_shell.h"

/**
 * _getline - Reads a line from an input stream and stores it in a buffer
 * @buffer: Pointer to the buffer where the line will be stored
 * @maxSize: Maximum number of characters to read into the buffer
 * @inputStream: File stream from which to read the input
 *
 * Return: Pointer to the buffer containing the read line, or NULL on failure
 */

char *_getline(char *buffer, size_t maxSize, FILE *inputStream)
{
	int ch;
	size_t index = 0;
	static char input_buffer[BUFFER_SIZE];
	static size_t buffer_position;

	if (buffer == NULL || maxSize == 0 || inputStream == NULL)
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

		while (index < maxSize - 1)
		{
			ch = input_buffer[buffer_position++];
			buffer[index++] = ch;
			if (ch == '\n' || ch == '\0')
			{
				buffer[index] = '\0';
				return (buffer);
			}
		}
	}
}
