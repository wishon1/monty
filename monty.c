#include "monty.h"
/**
 *
 *
 */
int main(int ar_count, char **ar_vec)
{
	FILE *monty_len, *_monty;
	char **file_lines = NULL, *line_ptr = NULL;
	size_t line_size = 0;;
	int get_byte, line_len;

	if (ar_count != 2)
		ar_count_error();

	monty_len = fopen(argv[1], "r");
	if (_monty == NULL)
		monty_len_err(ar_vec[1]);

	while (1)
	{
		get_byte = getline(&line_ptr, &line_size, _monty);
		if (get_byte == -1)
			break;
		line_len = line_len + 1;
	}
	free(line_ptr);
	fclose(monty_len);

	file_lines = file_access(line_len, ar_vec[1]);
	glob_var.file_lines = file_lines;

	interprete_line(file_lines);
}
