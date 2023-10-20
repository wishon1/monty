#include "monty.h"

/**
 * pop_func - removes the last value from the stack
 * @stack: The stack itself
 * @line_number: the line containing the command
 */
void pop_func(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		free_all();
		exit(EXIT_FAILURE);
	}

	deleteNode_end(stack);
}

/**
 * pint_func - prints the content of the stack
 * @stack: The stack itself
 * @line_number: the line containing the command
 */
void pint_func(stack_t **stack, unsigned int line_number)
{
	(void)stack, (void)line_number;

	if (global_var.topOfStackValue1 == -99)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		free_all();
		exit(EXIT_FAILURE);
	}

	printf("%d\n", global_var.topOfStackValue1);
}
