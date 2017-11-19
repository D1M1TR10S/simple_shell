#include "holberton.h"

int env(void)
{
	extern char **environ;
	int line;

	for (line = 0; environ[line] != NULL; line++)
		printf("%s\n", environ[line]);
	return (0);
}

int sexit(void)
{
	exit(EXIT_SUCCESS);
}
