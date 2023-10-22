#include"monty.h"
/**
 * nop_func - it doesn't do anything
 * @stack: the stack itself
 * @line_number: the number of lines in the stack
 */
void nop_func(stack_t **stack, unsigned int line_number)
{
	(void) line_number;
	(void) **stack;
}

/**
 * pop_func - deletes the value of the stack
 * @stack: pointer to array of stack
 * @line_number: the number of lines in the stack
 */
void pop_func(stack_t **stack, unsigned int line_number)
{
	*stack = global_var._buffer;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		free_all();
		exit(EXIT_FAILURE);
	}
	global_var._buffer = global_var._buffer->prev;
	free(*stack);
}
