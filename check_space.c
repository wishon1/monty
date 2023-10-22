#include "monty.h"
/**
 * space_checker - check if the command is spaces
 * only without any letters
 * Return: 1 if the string has no letters and only spaces
 * else it returns 0;
 */
int space_checker(void)
{
	char *arr = global_var.container;
	unsigned int index = 0;

	while (index < strlen(arr) - 1)
	{
		if (arr[index] != ' ')
		{
			return (0);
		}
		index = index + 1;
	}
	return (1);
}
