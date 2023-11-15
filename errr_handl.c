#include "monty.h"
/***/
void err_msg(int error_code, ...)
{
	va_list arg;
	char *op;
	int line_num;

	va_start(arg, error_code);
	switch (error_code)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 2:
			fprintf(stderr, "Error: Can't open file %s\n",
				va_arg(arg, char *));
			break;
		case 3:
			line_num = va_arg(arg, int);
			op = va_arg(arg, char *);
			fprintf(stderr, "L%d: unknown instruction %s\n", line_num, op);
			break;
		case 4:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		case 5:
			fprintf(stderr, "L%d: usage: push integer\n", va_arg(arg, int));
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}
/***/
void more_err_msg(int error_code, ...)
{
	va_list arg;
	char *op;
	int line_num;

	va_start(arg, error_code);
	switch (error_code)
	{
		case 6:
			fprintf(stderr, "L%d: can't pint, stack empty\n",
				va_arg(arg, int));
			break;
		case 7:
			fprintf(stderr, "L%d: can't pop an empty stack\n",
				va_arg(arg, int));
			break;
		case 8:
			line_num = va_arg(arg, unsigned int);
			op = va_arg(arg, char *);
			fprintf(stderr, "L%d: can't %s, stack too short\n", line_num, op);
			break;
		case 9:
			fprintf(stderr, "L%d: division by zero\n",
				va_arg(arg, unsigned int));
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}
/***/
void str_err(int error_code, ...)
{
	va_list arg;
	int line_num;

	va_start(arg, error_code);
	line_num = va_arg(arg, int);
	switch (error_code)
	{
		case 10:
			fprintf(stderr, "L%d: can't pchar, value out of range\n", line_num);
			break;
		case 11:
			fprintf(stderr, "L%d: can't pchar, stack empty\n", line_num);
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}
