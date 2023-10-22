#include"monty.h"
/**
 * free_all - free the stack
 */
void free_all(void)
{
	free(global_var.container);
	if (global_var._buffer != NULL)
	{
		while (global_var._buffer->prev != NULL)
		{
			global_var._buffer = global_var._buffer->prev;
			free(global_var._buffer->next);
		}
		free(global_var._buffer);
	}
	fclose(global_var.file_open);
}
