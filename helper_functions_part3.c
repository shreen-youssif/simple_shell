#include "shell.h"

/**
 * concatThree - concats 3 strings together
 * @name: first string
 * @sep: second string
 * @value: Third string
 * Return: pointer to the new string
 */
char *concatThree(char *name, char *sep, char *value)
{
	char *result;
	int l1, l2, l3, i, k;

	l1 = myStrlen(name);
	l2 = myStrlen(sep);
	l3 = myStrlen(value);

	result = malloc(l1 + l2 + l3 + 1);
	if (!result)
		return (NULL);

	for (i = 0; name[i]; i++)
		result[i] = name[i];
	k = i;

	for (i = 0; sep[i]; i++)
		result[k + i] = sep[i];
	k = k + i;

	for (i = 0; value[i]; i++)
		result[k + i] = value[i];
	k = k + i;

	result[k] = '\0';

	return (result);
}
/**
 * myStrcmp - Compares two strings
 * @str1: first strang
 * @str2: second strang
 *
 * Return: 0 if equal, <0 if str1 < str2, >0 if str1 > str2
 */
int myStrcmp(char *str1, char *str2)
{
	while (*str1 && *str2 && *str1 == *str2)
	{
		str1++;
		str2++;
	}
	return (*str1 - *str2);
}
/**
 * myStrlen - it gives the length of a string
 * @s: pointer to the string
 * Return: the length of string
 */
int myStrlen(const char *s)
{
	int i = 0;

	while (*(s + i) != '\0')
	{
		i++;
	}
	return (i);
}

/**
 * myPutChar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int myPutChar(char c)
{
	return (write(1, &c, 1));
}

/**
 * myPuts - prints a string
 * @str: pointer to string
 */

void myPuts(char *str)
{
	int i = 0;

	while (str[i])
	{
		myPutChar(str[i]);
		i++;
	}
}

