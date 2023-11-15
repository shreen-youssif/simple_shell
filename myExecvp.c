#include "shell.h"
/**
 * myExecvp - execute a program
 * @program: Name of the program to execute.
 * @argv: Argument vector for the program to be executed.
 * Return: -1 in all cases (successful execution will terminate the process)
 */
int myExecvp(const char *program, char *const argv[])
{
    char full_path[PATH_MAX];
    char *dir;
    int execve_status = -1;
    char *path = myGetenv("PATH");
    char *path_copy = myStrdup(path);
    
    if (program == NULL) {
        write(STDERR_FILENO, "hsh: NULL command received\n", 28);
        return -1;
    }
    if (myStrchr(program, '/') != NULL) {
        execve(program, argv, environ);
        perror("hsh");
        return -1;
    }
    if (path == NULL) {
        write(STDERR_FILENO, "hsh: PATH not set\n", 18);
        return -1;
    } 
    if (!path_copy) {
        perror("hsh");
        return -1;
    }
    for (dir = strtok(path_copy, ":"); dir != NULL; dir = strtok(NULL, ":")) {
        myMemset(full_path, 0, PATH_MAX);
        myStrcpy(full_path, dir);

        if (full_path[myStrlen(full_path) - 1] != '/') {
            myStrcat(full_path, "/");
        }
        myStrcat(full_path, program);

        if (access(full_path, X_OK) == 0) {
            execve(full_path, argv, environ);
            execve_status = errno;
            break;
        }
    }
    free(path_copy);
    if (execve_status != -1) {
        errno = execve_status;
        perror("hsh");
    } else {
        write(STDERR_FILENO, "hsh: command not found: ", 24);
        write(STDERR_FILENO, program, myStrlen(program));
        write(STDERR_FILENO, "\n", 1);
    }

    return -1;
}

