#include "monty.h"
/**
 * free_all - free all dynamic memory.
 */
void free_all(void)
{

	if (global_var.file_lines != NULL)
	{
		free(global_var.file_lines);
		global_var.file_lines = NULL;
	}

	if (global_var.container != NULL)
	{
		free_container(&(global_var.container));
		global_var.container = NULL;
	}
}

/**
 * free_file_lines - free the file lines
 * @file_lines: the file lines
 */
void free_file_lines(char **file_lines)
{
	int i = 0;

	while (file_lines[i] != NULL)
	{
		free(file_lines[i]);
		i++;
	}
	free(file_lines);
}
