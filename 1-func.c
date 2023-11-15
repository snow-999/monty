#include "monty.h"
/***/
void addto_stack(stack_t **node, unsigned int ln)
{
	stack_t *temp;

	(void)ln;
	if (node == NULL || *node == NULL)
	{
		exit(EXIT_FAILURE);
	}
	if (head == NULL)
	{
		head = *node;
		return;
	}
	temp = head;
	head = *node;
	head->next = temp;
	temp->prev = head;
}
/***/
void print_stack(stack_t **stack, unsigned int ln)
{
	stack_t *temp;

	(void) ln;
	if (stack == NULL)
	{
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
/***/
void del_top(stack_t **stack, unsigned int ln)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL)
	{
		more_err_msg(7, ln);
	}
	temp = *stack;
	*stack = temp->next;
	if (*stack != NULL)
	{
		(*stack)->prev = NULL;
	}
	free(temp);
}
void print_top(stack_t **stack, unsigned int ln)
{
	if (stack == NULL || *stack == NULL)
	{
		more_err_msg(6, ln);
	}
	printf("%d\n", (*stack)->n);
}
