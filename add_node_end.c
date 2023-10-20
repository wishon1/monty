#include "monty.h"
/**
 * add_node_end - add a node at the end of the list
 * @stack_head: the first node.
 * @n: the value in the node.
 * Return: return the endnode.
 */
stack_t *add_node_end(stack_t **stack_head, const int n)
{
	stack_t *endNode = NULL, *transverseNode = *stack_head;

	endNode = malloc(sizeof(stack_t));
	if (endNode == NULL)
	{
		free_all();
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	endNode->n = n;

	if (*stack_head == NULL)
	{
		endNode->prev = *stack_head;
		endNode->next = NULL;
		*stack_head = endNode;
		global_var.topOfStackValue1 = endNode->n;
		global_var.stack_top = endNode;
		global_var.bottom = endNode->prev;
	}
	else
	{
		while (transverseNode->next != NULL)
			transverseNode = transverseNode->next;
		append_node(endNode, transverseNode);
	}
	return (endNode);
}
