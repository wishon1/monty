#include "monty.h"
/**
 *
 */
void free_all(void)
{
	stack_t *temp = NULL;
	int i = 0;

	if (glob_var.all_lines != NULL)
	{
		while (global_var.all_lines[i] != NULL)
        	{
            		free(global_var.all_lines[i]);
            		i++;
        	}
        	free(global_var.all_lines);
		glob.all_lines = NULL;
	}
	
	/* free the stack from here */
	if (global_var.stack != NULL)
		while (global_var.stack != NULL)
		{
			temp = global_var.stack->next;
			free(global_var.stack);
			global_var.stack = temp;
		}
		global_var.stack = NULL;
	}
}
