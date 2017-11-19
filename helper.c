#include "holberton.h"
int failure(void);
/**
 * get_fmt_func - Finds the necessary function for format specifier
 * @s: Char of format spec
 * Return: a function
 */

int (*builtin(char *s))(void)
{
	int i = 0;

	cmnd_t comms[] = {
		{"env", printenv},		/*{arg, func},*/
/*		{"exit", exit},*/
		{NULL, NULL}
	};

	while (comms[i].arg != NULL) /*Loops through struct until NULL*/
	{
		if (_strcmp(comms[i].arg, s) == 0) /*Compares *s to see if it is equal to*/
			return (comms[i].func); /*Returns function associated with*/
						  /*format specifier*/
		i++;
	}
	return (failure); /*If no match returns NULL*/
}
int failure(void)
{
	return (1);
}
