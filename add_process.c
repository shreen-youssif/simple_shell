#include "shell.h"

/**
 * add_process - add a new process
 * @args: array of strings
 *
 * Return: 1 if success, 0 otherwise.
 */
int add_process(char **args)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == 0)
	{

		if (myExecvp(args[0], args) == -1)
		{
			perror("error in child process");
		}
			exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		perror("error in forking");
	}
	else
	{
		do {
			waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}
	return (-1);
}
