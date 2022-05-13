#include "monty.h"
/**
 * _swap - swap xd
 * @head: ptr
 * @line_number: counter
 * Return: noll
 */
void _swap(stack_t **head, unsigned int line_number)
{
	stack_t *aux;
	int auxC, auxB;

	if (!(*head) ||	!(*head)->next)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	aux = *head;
	auxC = aux->next->n;
	auxB = aux->n;
	aux->next->n = auxB;
	aux->n = auxC;
}

/**
 * _add - add the top two elements of the stack
 * @head: pointer to pointer to head
 * @line_number: counter of line
 * Return: nothing
 */
void _add(stack_t **head, unsigned int line_number)
{

	if (!*head || !(*head)->next)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		(*head)->next->n += (*head)->n;
		_pop(head, line_number);
	}
}

/**
 * _nop - opcode nop doesn’t do anything
 * @head: pointer to pointer to head
 * @line_number: counter of line
 * Return: nothing
 */
void _nop(stack_t **head, unsigned int line_number)
{
	(void)head;
	(void)line_number;
}

/**
 * _sub - sub the top two elements of the stack
 * @head: pointer to pointer to head
 * @line_number: counter of line
 * Return: nothing
 */
void _sub(stack_t **head, unsigned int line_number)
{

	if (!*head || !(*head)->next)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		(*head)->next->n -= (*head)->n;
		_pop(head, line_number);
	}
}

/**
 * _mul - mul
 * @head: ptr
 * @line_number: counter
 * Return: null
 */
void _mul(stack_t **head, unsigned int line_number)
{

	if (!*head || !(*head)->next)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		(*head)->next->n *= (*head)->n;
		_pop(head, line_number);
	}
}
