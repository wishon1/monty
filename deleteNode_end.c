#include "monty.h"
/**
 * deleteNode_end - delete the node at the end of the list
 * @head_ptr: a double pointer to the head node.
 * Return: return null or a new address(endNode)
 */
stack_t *deleteNode_end(stack_t **head_ptr)
{
	stack_t *endNode = NULL;
	stack_t *current_node = *head_ptr;

	if (current_node == NULL)
		return (NULL);

	while (current_node->next != NULL)
		current_node = current_node->next;

	if (current_node->prev == NULL)
	{
		global_var.topOfStackValue1 = -99;
		global_var.topOfStackValue2 = -99;
		global_var.stack_top = NULL;
		global_var.bottom = NULL;
		free(current_node);
		*head_ptr = NULL;
	}
	else
	{
		endNode = current_node->prev;
		endNode->next = current_node->next;
		global_var.topOfStackValue1 = endNode->n;

		if (endNode->prev != NULL)
			global_var.topOfStackValue2 = endNode->prev->n;

		global_var.stack_top = endNode;
		global_var.bottom = endNode->prev;

		free(current_node);
	}
	return (endNode);
}
