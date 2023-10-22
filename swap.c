#include"monty.h"
/**
 * swap_func - swap two numbers
 * @stack: Double pointer to the stack
 * @line_number: the number of lines
 */
void swap_func(stack_t **stack, unsigned int line_number)
{
	int value;
	*stack = global_var._buffer;

	if (*stack == NULL || (*stack)->prev == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		free_all();
		exit(EXIT_FAILURE);
	}
	(*stack) = (*stack)->prev;
	value = global_var._buffer->n;
	global_var._buffer->n = (*stack)->n;
	(*stack)->n = value;
}
