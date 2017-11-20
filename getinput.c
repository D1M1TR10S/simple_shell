#include "holberton.h"


char *getinput(void)
{
	char *buffer;
	int check;
	size_t length = 1;

	buffer = malloc(sizeof(char) * length);
	if (buffer == NULL)
	{
		perror("Error");
	}
	while (1)
	{
		write(1, "($) ", 4);
		check = getline(&buffer, &length, stdin);
		if (check == -1)
		{
			write(1, "\n", 1);
			exit(EXIT_SUCCESS);
		}
		return (buffer);
	}
	perror("Error");
}
