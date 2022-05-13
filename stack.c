#include "monty.h"
/**
 * _stack - sestack
 * @head: ptr
 * @line_number: otr
 * Return: null
 */
void _stack(stack_t **head, unsigned int line_number)
{
	(void)head;
	(void)line_number;

	global.mode = 1;
}
/**
 * _queue - sexd
 * @head: pointer
 * @line_number: line
 * Return: null
 */
void _queue(stack_t **head, unsigned int line_number)
{
	(void)head;
	(void)line_number;

	global.mode = 0;
}
