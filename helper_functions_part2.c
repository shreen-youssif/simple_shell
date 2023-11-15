#include "shell.h"
/**
 * myRealloc - reallocates a memory block
 * @original_ptr: pointer to the memory previously allocated
 * @current_size: current size of the memory block
 * @new_size: new size of the memory block
 *
 * Return: void pointer to the newly allocated memory
 */
void *myRealloc(void *original_ptr, unsigned int current_size, unsigned int new_size)
{
	char *new_ptr;
	char *old_ptr;
	unsigned int index;

	if (original_ptr == NULL)
		return (malloc(new_size));
	if (new_size == current_size)
		return (original_ptr);
	if (new_size == 0 && original_ptr != NULL)
	{
		free(original_ptr);
		return (NULL);
	}
	new_ptr = malloc(new_size);
	old_ptr = original_ptr;
	if (new_ptr == NULL)
		return (NULL);
	if (new_size > current_size)
	{
		for (index = 0; index < current_size; index++)
			new_ptr[index] = old_ptr[index];
		free(original_ptr);
		for (index = current_size; index < new_size; index++)
			new_ptr[index] = '\0';
	}
	if (new_size < current_size)
	{
		for (index = 0; index < new_size; index++)
			new_ptr[index] = old_ptr[index];
		free(original_ptr);
	}
	return (new_ptr);
}

/**
 * myGetchar - Reads a single character from standard input.
 * Return: the character read as an unsigned char cast to an int or EOF on end of file or error
 */
int myGetchar(void)
{
	char charRead;
	int readStatus = read(STDIN_FILENO, &charRead, 1);

	if (readStatus > 0)
	{
		return (int)charRead;
	}
	else if (readStatus == 0 || readStatus == -1)
	{
		return EOF;
	}
}

