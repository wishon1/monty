#include"monty.h"
/**
 * pall_func - print all elements of the list
 * @stack: is a pointer for the list
 * @line_number: the number of lines
 */
void pall_func(stack_t **stack, unsigned int line_number)
{
	(void) line_number;

	*stack = global_var._buffer;
	while (*stack != NULL)
	{
		printf("%d\n", (*stack)->n);
		*stack = (*stack)->prev;
	}
}

/**
 * pint_func - print the stack
 * @stack: the stack
 * @line_number: the number of lines
 */
void pint_func(stack_t **stack, unsigned int line_number)
{
	*stack = global_var._buffer;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		free_all();
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
