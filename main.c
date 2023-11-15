#include "shell.h"
/**
 * main - Entry point
 *
 * Return: 0 on success
 */
int main(void)
{
	if (isatty(STDIN_FILENO) == 1)
	{
		interactive_mode();
	}
	else
	{
		non_interactive_mode();
	}
	return (0);
}

