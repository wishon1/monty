#ifndef MAIN_H
#define MAIN_H

#define _GNU_SOURCE

#include<stdio.h>
#include<unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct glob_var - doubly linked list representation of a stack (or queue)
 * @value: integer
 * @global_var: points to stack
 * @file_open: file streamto open file
 * @container: the buffer
 * @print_ptr: prints the pointer value
 * @_buffer: the
 *
 * Description: doubly linked list node structure
 */
typedef struct glob_var
{
	int value;
	FILE *file_open;
	char *container;
	stack_t *print_ptr;
	stack_t *_buffer;
} stack_var;

extern stack_var global_var;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

stack_var global_var;

void add_func(stack_t **stack, unsigned int line_number);
void pint_func(stack_t **stack, unsigned int line_number);
void pall_func(stack_t **stack, unsigned int line_number);
void pop_func(stack_t **stack, unsigned int line_number);
void nop_func(stack_t **stack, unsigned int line_number);
void push_func(stack_t **stack, unsigned int line_number);
void swap_func(stack_t **stack, unsigned int line_number);
void interprete_byteCode(char *index_1, char *index_2, int line_number);
int space_checker(void);
void free_all(void);
void ar_count_error(void);
void fopen_error(char *fopen);
int is_digit(char *str);

#endif
