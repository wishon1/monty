#include "monty.h"
char **file_access(int line_len, char *arg);
/**
 * file_access - access, and tokenize each line.
 * @line_len: lenth of line in the file
 * @arg: name of the file.
 * Return: doc lines
 */
char **file_access(int line_len, char *arg)
{
	FILE *_monty;
	ssize_t get_byte = 0;
	int index = 0;
	char *buf_ptr, **doc_lines, *line_ptr = NULL;
	size_t get_size = 1;

	_monty = fopen(arg, "r");
	if (_monty == NULL)
		monty_len_err(arg);

	doc_lines = malloc(sizeof(char *) * line_len + 1);
	if (doc_lines == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free(doc_lines);
		fclose(_monty);
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		get_byte = getline(&line_ptr, &get_size, _monty);
		if (get_byte == -1)
			break;
		buf_ptr = strtok(line_ptr, "\n");
		if (buf_ptr == NULL)
			continue;
		doc_lines[index] = strdup(buf_ptr);
		index++;
	}
	free(line_ptr);
	doc_lines[index] = NULL;

	return (doc_lines);
}
