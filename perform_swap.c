#include "monty.h"
/**
 * perform_swap - function that swaps the codes.
 * @currentNode: the currentNode
 * @temp :the
 */
void perform_swap(stack_t *currentNode, stack_t *temp)
{
	temp = currentNode->prev;

	temp->next = currentNode->next;
	currentNode->prev = temp->prev;
	currentNode->next = temp;
	temp->prev = currentNode;
}
