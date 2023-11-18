#include "simple_shell.h"

/**
 * _setMemory - Fills a block of memory with a specific byte value.
 * @memBlock: Pointer to the memory area to be filled.
 * @byteVal: The byte value to fill @memBlock with.
 * @bytesNum: The number of bytes to be filled.
 *
 * Return: A pointer to the memory area @memBlock.
 */
char *_setMemory(char *memBlock, char byteVal, unsigned int bytesNum)
{
	unsigned int i;

	for (i = 0; i < bytesNum; i++)
		memBlock[i] = byteVal;

	return (memBlock);
}

/**
 * freeStringArray - Frees a string of strings and the array itself.
 * @strArray: The string of strings to free.
 */
void freeStringArray(char **strArray)
{
	char **temp = strArray;

	if (!strArray)
		return;

	while (*strArray)
		free(*strArray++);

	free(temp);
}

/**
 * _memrealloc - Reallocates a block of memory.
 * @prevBlock: Pointer to the previous malloc'ed block.
 * @prevSize: Byte size of the previous block.
 * @newSize: Byte size of the new block.
 *
 * Return: Pointer to the reallocated memory block.
 */
void *_memrealloc(void *prevBlock, unsigned int prevSize, unsigned int newSize)
{
	char *newBlock;

	if (!prevBlock)
		return (malloc(newSize));

	if (!newSize)
		return (free(prevBlock), NULL);

	if (newSize == prevSize)
		return (prevBlock);

	newBlock = malloc(newSize);

	if (!newBlock)
		return (NULL);

	prevSize = prevSize < newSize ? prevSize : newSize;

	while (prevSize--)
		newBlock[prevSize] = ((char *)prevBlock)[prevSize];

	free(prevBlock);
	return (newBlock);
}
