#include "shell.h"

/**
 * parsing_input - read a line from the stream
 *
 * Return: pointer that points the the read line
 */
char *parsing_input(void)
{
	int old_size, character, int buffer_size = 1024;
	int i = 0;
	char *line = malloc(sizeof(char) * buffer_size);
	char *error_message = "allocation error in parsing_input";

	if (line == NULL)
	{
		write(STDERR_FILENO, error_message, myStrlen(error_message));
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		character = myGetchar();
		if (character == EOF)
		{
			free(line);
			exit(EXIT_SUCCESS);
		}
		else if (character == '\n')
		{
			line[i] = '\0';
			return (line);
		}
		else
			line[i] = character;
		i++;
		if (i >= buffer_size)
		{
			old_size = buffer_size;
			buffer_size += buffer_size;
			line = myRealloc(line, old_size, buffer_size);
			if (line == NULL)
			{
				write(STDERR_FILENO, error_message, myStrlen(error_message));
				exit(EXIT_FAILURE);
			}
		}
	}
}
