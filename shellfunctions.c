#include "holberton.h"
/**
 * *_getenv - Get environment value
 * @Name of environment variable
 * Return: Value of variable
 */

char *_getenv(const char *name)
{
	extern char **environ;
	char *match = NULL;
	unsigned int x = 0, y = 0, z = 0, m = 0;

	while (environ[y] != NULL)
	{
		while (name[z] != '\0')
		{
			if (name[z] == environ[y][x])
			{
				z++, x++;
			}
			else
				break;
		}
		if (name[z] == '\0')
		{
			x++;
			match = malloc(sizeof(char) * strlen(environ[y]) - x + 1);
			while (environ[y][x] != '\0')
			{

				match[m] = environ[y][x];
				m++, x++;
			}
			return (match);
		}
		else
			z = x = 0, y++;
	}
	free(match);
	return ("No matches found");
}

void _sigign(int sig)
{
	if (sig == SIGINT)
		write(1, "\n$ ", 3);
}
