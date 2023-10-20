#include "monty.h"
/**
 * monty_len_err - handle error if file can't open
 * @arg: name of file
 */
void monty_len_err(char *arg)
{
	fprintf(stderr, "Error: Can't open file %s\n", arg);
	exit(EXIT_FAILURE);
}
