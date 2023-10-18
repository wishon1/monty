#include "monty.h"
/**
 *
 *
 */
char **file_access(int line_len, char *arg)
{
	FILE *_monty;
	int get_byte, index = 0;
	char *buf_ptr, **file_lines, *line_ptr = NULL;
	size_t *get_size = 0; 

	_monty = fopen(arg, "r");
	if (_monty == NULL)
		monty_len_err(arg);

	file_lines = malloc(sizeof(char *) * line_len + 1);
	if (file_lines == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}	

	while(1)
	{
		get_byte = get(&line_ptr, &get_size, _monty)
		if (get_byte == -1)
			break;

		buf_ptr = strtok(line_ptr, "\n");
		if (buf_ptr == NULL)
			continue;
	
		file_lines[index] = strdup(buf_ptr);
		index++;
	}
	free(line_ptr);
	file_lines[index] = NULL;
	fclose(_monty);
	return (file_lines)
}
