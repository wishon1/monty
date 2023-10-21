#include "monty.h"
void interprete_lines(char **file_lines);
/**
 * interprete_lines - interpretes each line of code
 * @file_lines: All individual lines of the file
 */
void interprete_lines(char **file_lines)
{
	int index, sig = 0, dex = 0;
	char *tok = NULL, *token[2] = {NULL, NULL};
	stack_t *_stack = NULL;

	instruction_t m_func[] = {
		{"push", push_func},
		{"pall", pall_func},
		{"pint", pint_func},
		{"pop", pop_func},
		{"swap", swap_func},
		{"add", add_func},
		{"nop", nop_func},
		{NULL, NULL}};

	while (file_lines[dex] !=  NULL)
	{
		tok = strtok(file_lines[dex], " ");
		token[0] = tok;
		tok = strtok(NULL, " ");
		token[1] = tok;
		global_var.arr_ptr = token;

		index = 0;
		while (m_func[index].opcode != NULL)
		{
			sig = 0;
			if (strcmp(token[0], m_func[index].opcode) == 0)
			{
				m_func[index].f(&_stack, dex + 1), sig = 1;
				break;
			}
			index++;
		}
		global_var.container = _stack;
		if (sig == 0)
		{
			printf("L%d: unknown instruction %s\n", dex + 1, token[0]);

			free_file_lines(file_lines);
			free_container(&(global_var.container));
			exit(EXIT_FAILURE);
		}
		dex++;
	}
	free_all();
}
