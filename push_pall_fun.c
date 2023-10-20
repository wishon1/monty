#include "monty.h"
/**
 * push_func - add a number to the stack
 * @stack: the stack itself
 * @line_number: the lines in the files.
 */
void push_func(stack_t **stack, unsigned int line_number)
{
	int num = 0;

	(void)stack, (void)line_number;

	if (global_var.arr_ptr[1] == NULL || (atoi(global_var.arr_ptr[1]) == -99))
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		free_all();
		exit(EXIT_FAILURE);
	}
	num = atoi(global_var.arr_ptr[1]);
	add_node_end(stack, num);
}
/**
 * pall_func - Pushes an item on the stack
 * @stack: The Stack itself
 * @line_number: Line where command is found
 */
void pall_func(stack_t **stack, unsigned int line_number)
{
	stack_t *stack_top = NULL, *currentNode = NULL;

	(void)line_number;

	if (*stack == NULL)
		return;
	currentNode = *stack;

	while (currentNode->next != NULL)
		currentNode = currentNode->next;

	stack_top = currentNode;
	while (stack_top != NULL)
	{
		printf("%d\n", stack_top->n);
		stack_top = stack_top->prev;
	}
}
