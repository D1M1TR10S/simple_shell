#include "shell.h"

int main(void)
{
	char *argv[5], *token, *buffer;
	size_t length = 1;
	pid_t child;
	int status, x = 0;

	signal(SIGINT, _sigign);
	while (1)
	{
		argv[0] = NULL;
		x = 0;
		buffer = NULL;
		token = NULL;
		buffer = getinput();
		token = strtok(buffer, TOK_DELIM);
		do
		{
			argv[x] = _strdup(token);
			x++;
			token = strtok(NULL, TOK_DELIM);
		} while (token != NULL);
		argv[x] = NULL;

		if (argv != NULL && argv[0] != NULL)
		{
			builtin(argv[0]);
			argv[0] = findpath(argv[0]);
			child = fork();
			if (child < 0)
				perror("Error");
			if (child == 0)
			{
				if (execve(argv[0], argv, NULL) == -1)
				{
					perror("Error");
					exit(1);
				}
			}
			wait(&status);
		}
		free(buffer);
		free(token);
	}
	if (read(STDIN_FILENO, buffer, length))
	{
		free(buffer);
		return (0);
	}
}
