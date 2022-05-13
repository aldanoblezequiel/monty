#include "monty.h"

/**
 * getfunc - selects fu
 * @lines: array
 * Return: ptr
 */
void *getfunc(char **lines)
{
	unsigned int pos = 0, i = 0, check;
	char *command;
	instruction_t instruct[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"add", _add},
		{"nop", _nop},
		{"sub", _sub},
		{"mul", _mul},
		{"div", _div},
		{"mod", _mod},
		{"pstr", _pstr},
		{"pchar", _pchar},
		{"rotl", _rotl},
		{"rotr", _rotr},
		{"queue", _queue},
		{"stack", _stack},
		{NULL, NULL}
	};
	for (pos = 0; lines[pos]; pos++)
	{
		check = checkcomm(lines[pos]);
		if (check == 1 || lines[pos][0] == '\n')
			continue;
		i = 0;
		command = strtok(lines[pos], " ");
		while (instruct[i].opcode)
		{
			if ((strcmp(instruct[i].opcode, command) == 0))
			{
				instruct[i].f(&global.head, (pos + 1));
				break;
			}
			i++;
		}
		if (instruct[i].opcode == NULL)
		{
			fprintf(stderr, "L%u: unknown instruction %s\n", (pos + 1), command);
			exit(EXIT_FAILURE);
		}
	}
	free_dlistint(global.head);
	return (NULL);
}
/**
 * _getcommand - gexd
 * @token_list: pointer
 * @line: po
 * Return: 0
 */
int _getcommand(char *token_list[], char *line)
{
	char *token = NULL, *delim = "\n\t\r";
	int pos_tok = 0;

	token = strtok(line, delim);
	while (token != NULL)
	{
		token_list[pos_tok] = malloc(sizeof(char) * (strlen(token) + 1));
		if (!token_list[pos_tok])
		{
			fprintf(stderr, "Error: malloc failed\n");
			exit(EXIT_FAILURE);
		}

		strcpy(token_list[pos_tok], token);
		pos_tok++;
		token = strtok(NULL, delim);
	}
	token_list[pos_tok] = NULL;
	return (0);
}
/**
 * findfunc - finds
 * @lines: instr
 * @instruct: struct
 * Return: vd
 */
void findfunc(char *lines[], instruction_t instruct[])
{
	unsigned int pos = 0, i = 0, check;
	char *command;
	stack_t *head = NULL;

	for (pos = 0; lines[pos]; pos++)
	{
		check = checkcomm(lines[pos]);
		if (check == 1 || lines[pos][0] == '\n')
			continue;
		i = 0;
		command = strtok(lines[pos], " ");
		while (instruct[i].opcode)
		{
			if ((strcmp(instruct[i].opcode, command) == 0))
			{
				instruct[i].f(&head, (pos + 1));
				break;
			}
			i++;
		}
		if (instruct[i].opcode == NULL)
		{
			fprintf(stderr, "L%u: unknown instruction %s\n", (pos + 1), command);
			exit(EXIT_FAILURE);
		}
	}
}
