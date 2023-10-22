#include"monty.h"
/**
 * push_func - push an element into stack
 * @stack: double pointer to the stack
 * @line_number: the number of lines
 */
void push_func(stack_t **stack, unsigned int line_number)
{
	stack_t *current = NULL;

	(void) line_number;

	current = malloc(sizeof(stack_t));
	if (current == NULL)
	{
		printf("Error: malloc failed\n");
		free_all();
		exit(EXIT_FAILURE);
	}
	current->n = global_var.value;
	*stack = global_var._buffer;

	if (*stack == NULL)
	{
		current->next = NULL;
		current->prev = NULL;
		*stack = current;
	}
	else
	{
		current->next = (*stack)->next;
		(*stack)->next = current;
		current->prev = *stack;
		*stack = current;
	}
	global_var._buffer = *stack;
}
