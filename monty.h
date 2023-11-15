#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>


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
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern stack_t *head;
typedef void (*op_fun)(stack_t **, unsigned int);

/* opcode */
void addto_stack(stack_t **node, unsigned int ln);
void print_stack(stack_t **stack, unsigned int ln);
void del_top(stack_t **stack, unsigned int ln);
void print_top(stack_t **stack, unsigned int ln);
void nop(stack_t **stack, unsigned int line_number);
void swap_stack(stack_t **stack, unsigned int line_number);
void add_stack(stack_t **stack, unsigned int line_number);

/* error handling */

void err_msg(int error_code, ...);
void more_err_msg(int error_code, ...);
void str_err(int error_code, ...);

/* file handling */

void op_file(char *file_name);
void rd_file(FILE *fd);
int spar_line(char *buf, int line_number, int f);
void find_fun(char *opcode, char *val, int ln, int f);
void call_fun(op_fun fun, char *op, char *val, int ln, int f);


/* main functions */

stack_t *create_stack(int n);
void free_nodes(void);
void add_to_queue(stack_t **new_node, unsigned int ln);



#endif /* MONTY_H */
