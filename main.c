#include"monty.h"
int is_digit(char *arr);
/**
 * main - monty compiler to interprete monty bytecodes
 * @ar_count: number of arguements
 * @ar_vec: array of arguements in strings
 * Return: 0
 */
int main(int ar_count, char **ar_vec)
{
	int index;
	unsigned int line_number = 1;
	char *buf[3];
	size_t len = 0;
	ssize_t byte;

	if (ar_count != 2)
		ar_count_error();

	global_var.file_open = fopen(ar_vec[1], "r");
	if (global_var.file_open == NULL)
		fopen_error(ar_vec[1]);

	while (1)
	{
		byte = getline(&global_var.container, &len, global_var.file_open);
		if (byte == -1)
			break;
		if (space_checker() == 1)
		{
			line_number++;
			continue;
		}

		buf[0] = strtok(global_var.container, " \n\t");
		index = 0;
		while (buf[index] != NULL && index < 1)
		{
			index++;
			buf[index] = strtok(NULL, " \n");
		}
		if (buf[1] != NULL)
		{
			if (is_digit(buf[1]) == 0)
				buf[1] = NULL;
		}
		interprete_byteCode(buf[0], buf[1], line_number);
		line_number++;
	}
	free_all();
	return (0);
}
