#include "shell.h"
/**
 * split_input - divide input line into tokens
 * @line: the input string
 * Return: the resulting tokens
 */
char **split_input(char *line)
{
	int buf_size = 64;
	int old_size;
	int i = 0;
	char **tokens = malloc(buf_size * sizeof(char *));
	char *token;
	char *error_message = "allocation error\n";

	if (!tokens)
	{
		write(STDERR_FILENO, error_message, myStrlen(error_message));
		exit(EXIT_FAILURE);
	}
	token = strtok(line, TOK_DELIM);
	while (token != NULL)
	{
		if (token[0] == '#')
		{
			break;
		}
	tokens[i] = token;
	i++;
	if (i >= buf_size)
	{
		old_size = buf_size;
		buf_size *= 2;
		tokens = myRealloc(tokens, old_size * sizeof(char *),
				buf_size * sizeof(char *));
		if (!tokens)
		{
			write(STDERR_FILENO, error_message, myStrlen(error_message));
			exit(EXIT_FAILURE);
		}
	}
	token = strtok(NULL, TOK_DELIM);
	}
	tokens[i] = NULL;
	return (tokens);
}
