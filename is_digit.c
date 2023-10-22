#include "monty.h"
/**
 * is_digit - check the number if its an interger.
 * @arr: pointer
 * Return: return 0 if its an interger else returns 0
 */
int is_digit(char *arr)
{
	unsigned long int index = 0;

	while (index < strlen(arr))
	{
		if (!isdigit(arr[index]) && arr[index] != '-')
			return (0);
		index++;
	}
	return (1);
}
