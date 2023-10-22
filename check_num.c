#include "monty.h"
/**
 * check_num - check the number.
 * @arr: pointer
 */
void check_num(char **arr)
{
	if (*arr != NULL)
	{
		if (is_digit(*arr) == 0)
			*arr = NULL;
	}
}

/**
 * is_digit - check if the number is a string
 * @arr: the number to check
 *
 * Return: return 0 if the number is not an interger else it
 * returns 0.
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
