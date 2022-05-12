#include "monty.h"

global_t global;
/**
 * start_global - init global variables
 * Return: null
 */
void start_global(void)
{
	global.mode = 1;
	global.head = NULL;
}

/**
 * main - the monty shell itself
 * @argc: counter
 * @argv: array
 * Return: 1
 */
int main(int argc, char **argv)
{
	int op, rd;
	char *lines[1024];
	char buffer[1024];

	*lines = NULL;
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}
	op = open(argv[1], O_RDONLY);
	if (op < 0)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}
	start_global();
	rd = read(op, buffer, 1024);
	buffer[rd - 1] = '\0';
	_getcommand(lines, buffer);
	getfunc(lines);
	if (lines[0])
		free_strlist(lines);
	return (0);
}
