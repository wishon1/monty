#include"monty.h"
/**
 * interprete_byteCode - interpretes the bytecode file
 * @index_1: is the opcode
 * @index_2: is the number
 * @line_number: the number of lines.
 */
void interprete_byteCode(char *index_1, char *index_2, int line_number)
{
	instruction_t arr[] = {
		{"push", push_func},
		{"pall", pall_func},
		{"pint", pint_func},
		{"pop", pop_func},
		{"swap", swap_func},
		{"add", add_func},
		{"nop", nop_func},
		{NULL, NULL}
	};
	int index = 0;

	while (arr[index].opcode != NULL)
	{
		if (strcmp(index_1, arr[index].opcode) == 0)
		{
			if (strcmp(index_1, "push") == 0)
			{
				if (index_2 == NULL || is_digit(index_2) == 0)
				{
					fprintf(stderr, "L%d: usage: push integer\n", line_number);
					free_all();
					exit(EXIT_FAILURE);
				}
				global_var.value = atoi(index_2);
			}
			arr[index].f(&global_var.print_ptr, line_number);
			return;
		}
		index++;
	}
	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, index_1);
	free_all();
	exit(EXIT_FAILURE);
}
