#include "shell.h"

/**
 * myCd - change the current directory
 * @args: List of args. args[0] is "cd". args[1] is the directory.
 * Return: 1 if successful, -1 if error.
 */
int myCd(char **args)
{
    char *error_message = "myCd: expected argument to \"cd\"\n";

    if (args[1] == NULL) 
    {
         write(STDERR_FILENO, error_message, myStrlen(error_message));
    } else {
        if (chdir(args[1]) != 0) {
            perror("myCd");
            return -1;
        }
    }
    return 1;
}
 
/**
 * myExit - exit the shell
 * @args: List of args. Not really used in this function.
 * Return: Exits the process, does not return.
 */
int myExit(char **args)
{
    exit(EXIT_SUCCESS);
}

/**
 * myEnv - prints the current environment
 * @args: List of args. Not really used in this function.
 * Return: 1 if successful.
 */
int myEnv(char **args)
{
    extern char **environ;
    int i = 0;

    while (environ[i]) {
        myPuts(environ[i]);
        myPuts("\n");
        i++;
    }
    return 1;
}
/**
 * own_help - display help for builtin commands
 * @args: List of args. Not really used in this function.
 * Return: 1 if successful.
 */
int myHelp(char **args)
{
    myPuts("Type program names and arguments, and hit enter.\n");
    myPuts("The following are built in:\n");

    myPuts("  cd\n");
    myPuts("  exit\n");
    myPuts("  env\n");
    myPuts("  help\n");

    myPuts("Use the man command for information on other programs.\n");
    return (1);
}

