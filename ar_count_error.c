#include "monty.h"
/**
 * ar_count_error - handle error if argc != 2
 */
void ar_count_error(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
}
