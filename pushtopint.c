#include "monty.h"
/**
 * _push - puts a nodes at the begining
 * @head: ptr
 * @line_number: gives the line of the op
 * Return: 1 o -1
 */
void _push(stack_t **head, unsigned int line_number)
{
	int pos;
	char *val;

	val = strtok(NULL, " ");
	if (val == NULL)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	pos = atoi(val);
	if (global.mode == 1)
		add_dnodeint(head, pos, line_number);
	if (global.mode == 0)
		add_dnodeint_end(head, pos, line_number);
}
/**
 * add_dnodeint - Agrega nodo at the start
 * @head: ptr
 * @num: stored in the node
 * @line_number: fail line number
 * Return: 0
 */
void add_dnodeint(stack_t **head, int num, unsigned int line_number)
{
	stack_t *new, *tmp;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "L%u: usage: can't malloc\n", line_number);
		exit(EXIT_FAILURE);
	}
	new->n = num;
	new->prev = NULL;
	tmp = *head;

	if (tmp != NULL)
	{
		while (tmp->prev != NULL)
			tmp = tmp->prev;
	}
	new->next = tmp;
	if (tmp != NULL)
		tmp->prev = new;
	*head = new;
}
/**
 * _pall - Ptimts the nodes
 * @head: ptr
 * @line_number: Liner
 * Return: null
 */
void _pall(stack_t **head, unsigned int line_number)
{
	stack_t *var;

	(void)line_number;
	if (*head)
	{
		var = *head;
		while (var->prev != NULL)
		{
			var = var->prev;
		}
		while (var != NULL)
		{
			printf("%u\n", var->n);
			var = var->next;
		}
	}
}

/**
 * _pint - Head node
 * @head: ptr
 * @line_number: liner count
 * Return: null
 */
void _pint(stack_t **head, unsigned int line_number)
{
	if (!head)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%u\n", (*head)->n);
}

/**
 * _pop - Errase head
 * @head: ptr
 * @line_number: liner count2
 * Return: null
 */
void _pop(stack_t **head, unsigned int line_number)
{

	if (!(*head))
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	if (!(*head)->next)
	{
		free(*head);
		*head = NULL;
	}
	else
	{
		*head = (*head)->next;
		free((*head)->prev);
		(*head)->prev = NULL;
	}
}
