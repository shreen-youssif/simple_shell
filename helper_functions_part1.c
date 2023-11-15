#include "shell.h"
/**
 * myGetenv - gets the value of the global variable
 * @var_name: name of the global variable
 * Return: string of value
 */
char *myGetenv(const char *var_name)
{
	int env_index, char_index;
	char *env_value;

	if (!var_name)
		return (NULL);
	for (env_index = 0; environ[env_index]; env_index++)
	{
		char_index = 0;
		if (var_name[char_index] == environ[env_index][char_index])
		{
			while (var_name[char_index])
			{
				if (var_name[char_index] != environ[env_index][char_index])
					break;

				char_index++;
			}
			if (var_name[char_index] == '\0')
			{
				env_value = (environ[env_index] + char_index + 1);
				return (env_value);
			}
		}
	}
	return (0);
}

/**
 * mySetenv - add or modify environment variable
 * @env_args: array of strings
 * Return: 1 on success
 */
int mySetenv(char **env_args)
{
	int env_index, key_index, value_index;

	if (!env_args[1] || !env_args[2])
	{
		perror(myGetenv("_"));
		return (1);
	}

	for (env_index = 0; environ[env_index]; env_index++)
	{
		key_index = 0;
		if (env_args[1][key_index] == environ[env_index][key_index])
		{
			while (env_args[1][key_index])
			{
				if (env_args[1][key_index] != environ[env_index][key_index])
					break;

				key_index++;
			}
			if (env_args[1][key_index] == '\0')
			{
				value_index = 0;
				while (env_args[2][value_index])
				{
					environ[env_index][key_index + 1 + value_index]
						= env_args[2][value_index];
					value_index++;
				}
				environ[env_index][key_index + 1 + value_index] = '\0';
				return (1);
			}
		}
	}
	if (!environ[env_index])
	{
		environ[env_index] = concatThree(env_args[1], "=", env_args[2]);
		environ[env_index + 1] = '\0';
	}
	return (1);
}

/**
 * myUnsetenv - Remove an environment variable
 * @env_args: array of entered words
 * Return: on sucess (1)
 */
int myUnsetenv(char **env_args)
{
	int env_index, key_index;

	if (!env_args[1])
	{
		perror(myGetenv("_"));
		return (1);
	}
	for (env_index = 0; environ[env_index]; env_index++)
	{
		key_index = 0;
		if (env_args[1][key_index] == environ[env_index][key_index])
		{
			while (env_args[1][key_index])
			{
				if (env_args[1][key_index] != environ[env_index][key_index])
					break;

				key_index++;
			}
			if (env_args[1][key_index] == '\0')
			{
				free(environ[env_index]);
				environ[env_index] = environ[env_index + 1];
				while (environ[env_index])
				{
					environ[env_index] = environ[env_index + 1];
					env_index++;
				}
				return (1);
			}
		}
	}
	return (1);
}
