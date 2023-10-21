#include "monty.h"
/**
 * main - monty bytecode interpreter program
 * @ar_count: count of the command line arguement
 * @ar_vec: command line arguements
 * Return: return the interpreted code.
 */
int main(int ar_count, char *ar_vec[])
{
	FILE *monty_len;
	char **file_lines = NULL, *line_ptr = NULL;
	size_t line_size = 1;
	ssize_t get_byte = 0;
	int line_len = 0;

	if (ar_count != 2)
		ar_count_error();

	global_var.topOfStackValue1 = -99;
	monty_len = fopen(ar_vec[1], "r");
	if (monty_len == NULL)
		monty_len_err(ar_vec[1]);

	line_len = 0;
	while (1)
	{
		get_byte = getline(&line_ptr, &line_size, monty_len);
		if (get_byte == -1)
			break;

		line_len = line_len + 1;
	}
	free(line_ptr);
	fclose(monty_len);

	file_lines = file_access(line_len, ar_vec[1]);
	global_var.file_lines = file_lines;
	interprete_lines(file_lines);

	return (0);
}
