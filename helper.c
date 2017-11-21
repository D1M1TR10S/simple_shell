#include "holberton.h"
/**
 * get_fmt_func - Finds the necessary function for format specifier
 * @s: Char of format spec
 * Return: a function
 */
int builtin(char *s)
{
	int i = 0;

	cmnd_t comms[] = {
		{"env", printenv},		/*{arg, func},*/
		{"exit", exitshell},
		{NULL, NULL}
	};

	while (comms[i].arg != NULL) /*Loops through struct until NULL*/
	{
		if (_strcmp(comms[i].arg, s) == 0
				&& (_strlen(comms[i].arg) == _strlen(s))) /*Compares *s to see if it is equal to*/
			return (comms[i].func()); /*Returns function associated with*/
		
		i++;
	}
	return (1); /*If no match return 1*/
}
