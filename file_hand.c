#include "monty.h"
/***/
void op_file(char *file_name)
{
	FILE *fd = fopen(file_name, "r");

	if (file_name == NULL || fd == NULL)
	{
		err_msg(2, file_name);
	}
	rd_file(fd);
	fclose(fd);
}
/***/
void rd_file(FILE *fd)
{
	int line_number, f = 0;
	char *buf = NULL;
	size_t len = 0;

	for (line_number = 1; getline(&buf, &len, fd) != -1; line_number++)
	{
		f = spar_line(buf, line_number, f);
	}
	free(buf);
}
/***/
int spar_line(char *buf, int line_number, int f)
{
	char *opcode, *val;
	const char *del = "\n";

	if (buf == NULL)
	{
		err_msg(4);
	}
	opcode = strtok(buf, del);
	if (opcode == NULL)
	{
		return (f);
	}
	val = strtok(NULL, del);
	if (strcmp(opcode, "stack") == 0)
	{
		return (0);
	}
	if (strcmp(opcode, "queue") == 0)
	{
		return (1);
	}
	find_fun(opcode, val, line_number, f);
	return (f);
}
/***/
void find_fun(char *opcode, char *val, int ln, int f)
{
	int x;
	int flg;

	instruction_t fun_list[] = {
		{"push", addto_stack},
		{"pall", print_stack},
		{"pop", del_top},
		{"pint", print_top},
		{"swap", swap_stack},
		{"nop", nop},
		{"add", add_stack},
		{NULL, NULL}
	};

	if (opcode[0] == '#')
	{
		return;
	}
	for (flg = 1, x = 0; fun_list[x].opcode != NULL; x++)
	{
		if (strcmp(opcode, fun_list[x].opcode) == 0)
		{
			call_fun(fun_list[x].f, opcode, val, ln, f);
			flg = 0;
		}
	}
	if (flg == 1)
	{
		err_msg(3, ln, opcode);
	}
}
/***/
void call_fun(op_fun fun, char *op, char *val, int ln, int f)
{
	stack_t *node;
	int flag;
	int x;

	flag = 1;
	if (strcmp(op, "push") == 0)
	{
		if (val != NULL && val[0] == '-')
		{
			val += 1;
			flag = -1;
		}
		if (val == NULL)
		{
			err_msg(5, ln);
		}
		for (x = 0; val[x] != '\0'; x++)
		{
			if (isdigit(val[x]) == 0)
			{
				err_msg(5, ln);
			}
		}
		node = create_stack(atoi(val) * flag);
		if (f == 0)
		{
			fun(&node, ln);
		}
		if (f == 1)
		{
			add_to_queue(&node, ln);
		}
	}
	else
	{
		fun(&head, ln);
	}
}
