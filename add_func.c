#include "monty.h"
/**
 * add_func - add the values in the stack
 * @stack: the stacks.
 * @line_number: line containing the commands
 */
void add_func(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;
	int num;

	if (current == NULL || current->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		free_all();
		exit(EXIT_FAILURE);
	}

	num = 0;
	while (current->next != NULL)
		current = current->next;

	num = current->prev->n + current->n;
	current->prev->n = num;
	deleteNode_end(stack);
}
