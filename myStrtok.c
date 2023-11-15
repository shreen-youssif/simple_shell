#include "shell.h"
char *myStrtok(char *str, const char *delimiters)
{
	static char *currentPosition = NULL;
	char *start = currentPosition;

	if (str != NULL)
	{
		currentPosition = str;
	}
	else if (currentPosition == NULL)
	{
		return NULL;
	}
	while (*currentPosition && strchr(delimiters, *currentPosition))
	{
		currentPosition++;
	}
	if (*currentPosition == '\0')
	{
		return NULL;
	}
	while (*currentPosition && !strchr(delimiters, *currentPosition))
	{
		currentPosition++;
	}
	if (*currentPosition != '\0')
	{
		*currentPosition = '\0';
		currentPosition++;
	}
	return start;
}
