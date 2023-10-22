#include"monty.h"
/**
 * add_func - add the result of addition of two numbers to stack
 * @stack: is a pointer
 * @line_number: is an int
 */
void add_func(stack_t **stack, unsigned int line_number)
{
	int result = 0;
	*stack = global_var._buffer;

	if (*stack == NULL || (*stack)->prev == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		free_all();
		exit(EXIT_FAILURE);
	}
	(*stack) = (*stack)->prev;
	result = (*stack)->n + global_var._buffer->n;
	pop_func(&global_var.print_ptr, line_number);
	pop_func(&global_var.print_ptr, line_number);
	global_var.value = result;
	push_func(&global_var.print_ptr, line_number);
}
