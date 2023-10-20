#include "monty.h"
/**
 * append_node - append the nodes
 * @endNode: the last node.
 * @transverseNode: node used to iterate the list
 */
void append_node(stack_t *endNode, stack_t *transverseNode)
{
	endNode->prev = transverseNode;
	transverseNode->next = endNode;
	endNode->next = NULL;

	global_var.topOfStackValue1 = endNode->n;
	global_var.topOfStackValue2 = endNode->prev->n;
	global_var.stack_top = endNode;
	global_var.bottom = endNode->prev;
}
