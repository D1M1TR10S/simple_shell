#include "shell.h"
/**
 * findpath - Find the path for a specific command
 * @name: Command
 * Return: Path name ending in command
 */
char *findpath(char *name)
{
	const char *path = "PATH";
	char *value, *token;
	char *dir[8];
	struct stat statbuff;
	int num = 0;

	value = _getenv(path);
	token = strtok(value, TOK_DELIM);
	do
	{
		dir[num] = NULL;
		dir[num] = _strdup(token);
		dir[num] = str_concat(dir[num], name);
		if (name[0] == '/')
			break;
		if (_strcmp(name, "./") == 0)
			break;
		if (stat(dir[num], &statbuff) == 0)
		{
			free(value);
			return (dir[num]);
		}
		else
			num++;
		token = strtok(NULL, TOK_DELIM);
	} while (token != NULL);
	free(dir[num]);
	free(value);
	return (name);
}
