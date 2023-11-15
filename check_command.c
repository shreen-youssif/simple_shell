#include "shell.h"

/**
 * check_command - checks if command is built-in or external process
 * @cmd_params: command and its arguments
 *
 * Return: 1 on success, 0 otherwise
 */
int check_command(char **cmd_params)
{
	char *command_list[] = {
	"cd",
	"env",
	"help",
	"exit",
	"setenv",
	"unsetenv"};
	int (*command_funcs[])(char **) = {
	&myCd,
	&myEnv,
	&myHelp,
	&myExit,
	&mySetenv,
	&myUnsetenv};
	size_t index = 0;

	if (cmd_params[0] == NULL)
	{
		return (-1);
	}
	for (; index < sizeof(command_list) / sizeof(char *); index++)
	{
		if (myStrcmp(cmd_params[0], command_list[index]) == 0)
		{
			return ((*command_funcs[index])(cmd_params));
		}
	}
	return (add_process(cmd_params));
}
