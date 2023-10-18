#include "monty.h"
/**
 *
 *
 */
void interprete_lines(char **file_lines)
{
	int index = 0, dex = 0;
	char *tok = NULL, *token[2] = {NULL, NULL};
	stack_t **_stack, *temp;  

	instruction_t m_func[] = {
		{"push", push_func}
		{"pall", pall_func}
		{"pint", pint_func}
		{"pop", pop_func}
		{"swap", swap_func}
		{"add", add_func}
		{"nop", nop_func}
		{NULL, NULL}};

	while (file_lines[dex] !=  NULL)
	{
		tok = strtok(file_line[dex], " ");
		token[0] = tok;
		tok = strtok(NULL, " ");
		token[1] = tok, global_avar.arr_ptr = token;	
		
		while (m_func[index].opcode != NULL)
		{
			sig = 0;
			if (strcmp(token[0], m_func[index].opcode) == 0)
			{
				m_func[index].f(&_stack, dex + 1), sig = 1;
				break;
			}
			global_var.stack = _stack;
		}
		if (sig == 0)
		{
			printf("L%d: unknown instruction %s\n", dex + 1, m_func[0]);
			free(file_line);
			while (global_var.stack != NULL)
			{
				temp = global_var.stack->next;
				free(global_var.stack);
				global_var.stack = temp
			}
			exit(EXIT_FAILURE);
		}
		dex++;
	}
	free_all();
}
