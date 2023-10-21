#ifndef MONTY_H
#define MONTY_H
#define _GNU_SOURCE

/* Header files of all functions */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include <stddef.h>
#include <fcntl.h>
#include <ctype.h>
#include <sys/stat.h>
#include <sys/type.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
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
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f:function to handle the opcode
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct _global - represents a stack and related information.
 * @topOfStackValue1: Represents the value of the top of stack 1
 * @topOfStackValue2: Represents the value of the top of stack 2
 * @bottom: Pointer to the bottom of the stack.
 * @stack_top: Pointer to the top of the stack.
 * @container: Container for the stack elements.
 * @arr_ptr: Pointer to an array of characters.
 * @file_lines: Pointer to an array of strings representing file lines.
 */
typedef struct _global
{
	int topOfStackValue1;
	int topOfStackValue2;
	stack_t *bottom;
	stack_t *stack_top;
	stack_t *container;
	char **arr_ptr;
	char **file_lines;
} global_t;

void ar_count_error(void);
char **file_access(int line_len, char *arg);
void free_all(void);
void interprete_lines(char **file_lines);
void monty_len_err(char *arg);
void add_func(stack_t **stack, unsigned int line_number);
stack_t *deleteNode_end(stack_t **head_ptr);
stack_t *add_node_end(stack_t **stack_head, const int n);
void append_node(stack_t *endNode, stack_t *transverseNode);
void push_func(stack_t **stack, unsigned int line_number);
void pall_func(stack_t **stack, unsigned int line_number);
void pop_func(stack_t **stack, unsigned int line_number);
void pint_func(stack_t **stack, unsigned int line_number);

extern global_t global_var;

void nop_func(stack_t **stack, unsigned int line_number);
void swap_func(stack_t **stack, unsigned int line_number);

global_t global_var;

void perform_swap(stack_t *currentNode, stack_t *temp);

#endif /* monty.h */
