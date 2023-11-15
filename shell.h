#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <errno.h>
#include <signal.h>

#define TOK_DELIM " \t\r\n\a\""
#define PATH_MAX 4096
#define BUFFER_SIZE 1024

extern char **environ;

void interactive_mode(void);
void non_interactive_mode(void);
char *read_line(void);
char **split_input(char *line);
int check_command(char **args);
int myExecvp(const char *program, char *const argv[]);
int add_process(char **args);
char *parsing_input(void);
int myCd(char **args);
int myExit(char **args);
int myEnv(char **args);
int myHelp(char **args);
void display_prompt(void);
char *concatThree(char *name, char *sep, char *value);
int myStrcmp(char *str1, char *str2);
int myStrlen(const char *s);
int myPutChar(char c);
void myPuts(char *str);
int mySetenv(char **arv);
int myUnsetenv(char **arv);
void *myRealloc(void *ptr, unsigned int old_size, unsigned int new_size);
void freeArray(char **arv);
int myGetchar(void);
char *myGetenv(const char *name);
const char *myStrchr(const char *s, char c);
char *myStrcat(char *dest, const char *src);
char *myStrdup(const char *str);
char *myMemset(char *s, char b, unsigned int n);
char *myStrcpy(char *dest, const char *src);
ssize_t my_getline(char **lineptr, size_t *n, int fd);
char *custom_strtok(char *str, const char *delimiters);
int executeProgramWithPaths(const char *program, char *const argv[],
		char *path_copy);

#endif
