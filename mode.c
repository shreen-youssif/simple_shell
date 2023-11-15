#include "shell.h"
/**
 * interactive_mode - unix command line interpreter
 *
 * Return: void
 */
void interactive_mode(void)
{
  char *input_line;
  char **args;
  int executionStatus = -1;
  do
  {
    display_prompt();
    input_line = read_line();
    args = split_input(input_line);
    executionStatus = check_command(args);
    free(input_line);
    free(args);
    if (executionStatus >= 0)
    {
      exit(executionStatus);
    }
  } while (executionStatus == -1);
}

/**
 * non_interactive_mode - unix command line interpreter
 *
 * Return: void
 */
void non_interactive_mode(void)
{
  char *input_line;
  char **args;
  int exectutionStatus = -1;

  do
  {
    input_line = parsing_input();
    args = split_input(input_line);
    exectutionStatus = check_command(args);
    free(input_line);
    free(args);
    if (exectutionStatus >= 0)
    {
      exit(exectutionStatus);
    }
  } while (exectutionStatus == -1);
}
