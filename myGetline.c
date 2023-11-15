#include "shell.h"

/**
 * myGetline - read lines of text from a file or afile stream
 * @lineptr: pointer to character array
 * @n: pointer to size variable
 * @fd: file descriptor from which to read
 * Return: number of characters read
 */

#define INITIAL_BUFFER_SIZE 128
ssize_t my_getline(char **lineptr, size_t *n, int fd)
{
    if (!lineptr || !n)
    {
        errno = EINVAL;
        return -1;
    }

    if (*lineptr == NULL)
    {
        *n = INITIAL_BUFFER_SIZE;
        *lineptr = malloc(*n);
        if (*lineptr == NULL)
        {
            return -1;
        }
    }

    size_t pos = 0;
    ssize_t num_read;
    char ch;
    while ((num_read = read(fd, &ch, 1)) > 0)
    {

        if (pos + 1 >= *n)
        {
            *n *= 2;
            char *new_lineptr = realloc(*lineptr, *n);
            if (!new_lineptr)
            {
                return -1;
            }
            *lineptr = new_lineptr;
        }

        (*lineptr)[pos++] = ch;

        if (ch == '\n')
        {
            break;
        }
    }

    if (num_read == -1)
    {
        return -1;
    }
    else if (num_read == 0 && pos == 0)
    {
        return -1;
    }
    else
    {
        (*lineptr)[pos] = '\0';
        return pos;
    }
}

