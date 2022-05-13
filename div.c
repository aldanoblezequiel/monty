#include "monty.h"

/**
 * _div - di
 * @head: pointe
 * @line_number: counter
 * Return: noll
 */
void _div(stack_t **head, unsigned int line_number)
{
	if (!*head || !(*head)->next)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		if ((*head)->n == 0)
		{
			fprintf(stderr, "L%u: division by zero\n", line_number);
			exit(EXIT_FAILURE);
		}
		(*head)->next->n = (*head)->next->n / (*head)->n;
		_pop(head, line_number);
	}
}
/**
 * free_strlist - frees a char *list[]
 * @list: list to free
 * Return: 0 on success or -1 on failure
 */
int free_strlist(char *list[])
{
	int aux;

	if (!*list)
	{
		perror("no list to free");
		return (-1);
	}
	for (aux = 0; list[aux]; aux++)
		free(list[aux]);
	return (0);
}
/**
 * free_dlistint - frees
 * @head: head
 * Return: voi
 */
void free_dlistint(stack_t *head)
{
	stack_t *temp;

	if (head)
	{
		while (head->prev != NULL)
			head = head->prev;
	}

	while ((temp = head) != NULL)
	{
		head = head->next;
		free(temp);
	}
}
/**
 * _mod - rest
 * @head: pointer
 * @line_number: counte
 * Return: noll
 */
void _mod(stack_t **head, unsigned int line_number)
{
	if (!*head || !(*head)->next)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		if ((*head)->n == 0)
		{
			fprintf(stderr, "L%u: division by zero\n", line_number);
			exit(EXIT_FAILURE);
		}
		(*head)->next->n = (*head)->next->n % (*head)->n;
		_pop(head, line_number);
	}
}

/**
 * _pstr - print nd
 * @head: pointer
 * @line_number: counter
 * Return: noll
 */
void _pstr(stack_t **head, unsigned int line_number)
{
	stack_t *aux;

	(void)line_number;

	aux = *head;

	while (aux && aux->n > 0 && aux->n < 128)
	{
		putchar(aux->n);
		aux = aux->next;
	}
	putchar(10);
}
