#include "monty.h"
/**
 * swap_func - function that swaps value in the stack
 * @stack: the stack itself.
 * @line_number: the line contaning the command
 */
void swap_func(stack_t **stack, unsigned int line_number)
{
	stack_t *currentNode = *stack, *temp = NULL;

	if (currentNode == NULL || currentNode->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		free_all();
		exit(EXIT_FAILURE);
	}

	while (currentNode->next != NULL)
		currentNode = currentNode->next;
	perform_swap(currentNode, temp);
}

/**
 * nop_func - the function does nothing
 * @stack: the stack itself
 * @line_number: the line containing the command
 */
void nop_func(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
