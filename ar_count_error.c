#include "monty.h"
/**
 * ar_count_error - print error message
 * and exit the program
 */
void ar_count_error(void)
{
	fprintf(stderr, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
}

/**
 * fopen_error - print error meessage if the file can't open
 * @fopen: pointer to the name of the file
 */
void fopen_error(char *fopen)
{
	fprintf(stderr, "Error: Can't open file %s\n", fopen);
	exit(EXIT_FAILURE);
}
