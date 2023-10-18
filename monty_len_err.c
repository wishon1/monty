#include "monty.h"
/**
 *
 */
void monty_len_err(char *arg)
{
	fprintf(stderr, "Error: Can't open file %s\n", arg);
	exit(EXIT_FAILURE);
}
