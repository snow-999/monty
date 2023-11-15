#include "monty.h"
stack_t *head = NULL;
/***/
int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	op_file(argv[1]);
	free_nodes();
	return (0);
}
/***/
stack_t *create_stack(int n)
{
	stack_t *node;

	node = malloc(sizeof(stack_t));
	if (node == NULL)
		err_msg(4);
	node->next = NULL;
	node->prev = NULL;
	node->n = n;
	return (node);
}
/***/
void free_nodes(void)
{
	stack_t *temp;

	if (head == NULL)
		return;

	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}
/***/
void add_to_queue(stack_t **new_node, unsigned int ln)
{
	stack_t *temp;

	(void)ln;
	if (new_node == NULL || *new_node == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *new_node;
		return;
	}
	temp = head;
	while (temp->next != NULL)
		temp = temp->next;

	temp->next = *new_node;
	(*new_node)->prev = temp;

}
