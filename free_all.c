#include "monty.h"
/**
 * free_all - free all dynamic memory.
 */
void free_all(void)
{
	stack_t *temp = NULL;
	int i = 0;

	if (global_var.file_lines != NULL)
	{
		while (global_var.file_lines[i] != NULL)
		{
			free(global_var.file_lines[i]);
			i++;
		}
		free(global_var.file_lines);
		global_var.file_lines = NULL;
	}

	/* free the stack from here */
	if (global_var.container != NULL)
		while (global_var.container != NULL)
		{
			temp = global_var.container->next;
			free(global_var.container);
			global_var.container = temp;
		}
	global_var.container = NULL;
}
