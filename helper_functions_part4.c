#include "shell.h"
/**
 * myStrcat - appends the string
 *
 * @dest: pointer to the destination string
 * @src: pointer to the source of data to be appended
 *
 * Return: pointer to the resulting string
*/

char *myStrcat(char *dest, const char *src)
{
	char *ptr = dest + myStrlen(dest);

	if (!dest || !src)
	{
		return (NULL);
	}

	while (*src != '\0')
	{
		*ptr++ = *src++;
	}

		*ptr = '\0';
	return (dest);
}
/**
 * myStrchr - Entry point
 *
 * @s: input
 * @c: input
 *
 * Return: Always 0 (Success)
 */
const char *myStrchr(const char *s, char c)
{
	int i = 0;

	for (; s[i] >= '\0'; i++)
	{
		if (s[i] == c)
			return (&s[i]);
	}
	return (0);
}
/**
 * myStrdup - Duplicates a string
 *
 * @str: the string to be duplicated
 *
 * Return: A pointer to the duplicated string,
 * or NULL if insufficient memory was available
 */
char *myStrdup(const char *str)
{
	char *duplicateString;
	int index, length = 0;

	if (str == NULL)
	{
		return (NULL);
	}
	while (str[length])
	{
		length++;
	}
	duplicateString = (char *)malloc(sizeof(char) * (length + 1));


	if (duplicateString == NULL)
	{
		return (NULL);
	}

	for (index = 0; index < length; index++)
	{
		duplicateString[index] = str[index];
	}
	duplicateString[index] = '\0';

	return (duplicateString);
}

/**
 * myMemset - fill a block of memory with a specific value
 * @s: starting address of memory to be filled
 * @b: the desired value
 * @n: number of bytes to be changed
 *
 * Return: changed array with new value for n bytes
 */
char *myMemset(char *s, char b, unsigned int n)
{
	int i = 0;

	for (; n > 0; i++)
	{
		s[i] = b;
		n--;
	}
	return (s);
}
/**
 * myStrcpy - Copy string
 *
 * @dest: pointer to the destination buffer
 * @src: pointer to the source of data to be copied
 *
 * Return: pointer to the destination string dest
*/

char *myStrcpy(char *dest, const char *src)
{
	char *temp = dest;

	if (!dest || !src)
	{
		return (NULL);
	}

	while (*src != '\0')
	{
	*dest = *src;
	dest++;
	src++;
	}

	*dest = '\0';

	return (temp);
}
