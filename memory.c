#include "simple_shell.h"

/**
 * freePointer - Frees memory and sets pointer to NULL.
 * @pointer: Address of the pointer to be freed.
 *
 * This function frees the allocated memory at *ptr and
 * sets the pointer to NULL to prevent accessing invalid memory.
 *
 * Return: 1 if memory was freed, otherwise 0.
 */
int freePointer(void **pointer)
{
	if (pointer && *pointer)
	{
		free(*pointer);
		*pointer = NULL;
		return (1);
	}
	return (0);
}
