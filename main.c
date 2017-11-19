#include "holberton.h"

int main(void)
{
	char *argv[5];
	char *token, *buffer;
	size_t length = 1;
	struct stat statbuff;
	pid_t child;
	int check, status, x = 0;

	buffer = malloc(sizeof(char) * length);
	if (buffer == NULL)
	{
		printf("Error: Could not malloc\n");
		return (1);
	}
	while (1)
	{
		printf("($) ");
		check = getline(&buffer, &length, stdin);
		if (check == -1)
		{
			printf("Logout\n");
			return (1);
		}
		token = strtok(buffer, TOK_DELIM);
		do
		{
			argv[x] = _strdup(token);
			x++;
			token = strtok(NULL, TOK_DELIM);
		} while (token != NULL);

		if (builtin(argv[0]) == 0)
			return (0);

		if (stat(argv[0], &statbuff) != 0)
			argv[0] = findpath(argv[0]);

		child = fork();
		if (child < 0)
		{
			printf("Error: Could not fork\n");
			return (1);
		}
		if (child == 0)
		{
			if (execve(argv[0], argv, NULL) == -1)
			{
				printf("%s\n", argv[0]);
				printf("Error: Could not exec()\n");
				return (1);
			}
		}
		else
			wait(&status);
		x = 0;
	}
	if (read(STDIN_FILENO, buffer, length))
	{
		free(buffer);
		return (0);
	}
}
