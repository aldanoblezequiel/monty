#include "monty.h"
#include <stdlib.h>
#include <stddef.h>

/**
 * _strdup - Gives you a ptr to a new memory address
 *
 * @str: String
 *
 * Return: ptr or NULL
 */
char *_strdup(char *str)
{
	unsigned int e = 0;
	char *dup = NULL;

	e = 0;
	if (!str)
		return (NULL);
	for (e = 0; str[e]; e++)
		;
	dup = malloc(a + 1);
	if (!dup)
		return (NULL);
	for (e = 0; str[e]; e++)
		dup[e] = str[e];
	dup[e] = 0;
	return (dup);
}

/**
 * _strtok - Gives you a list
 *
 * @str: String
 * @separator: Separator xd
 *
 * Return: Null
 */

char **_strtok(char *str, char separator)
{
	char *tokList[1024], **tokListReturn, auxTok[1024];
	int ex = 0, i = 0, j = 0, k = 0, y = 0, tokLen = 0;

	*tokList = NULL, tokListReturn = NULL;
	for (i = 0; ex == 0; i++)
	{
		if (str[i] != separator)
			tokLen++;
		if (str[i] == separator)
			if (tokLen != 0)
			{
				j = i - tokLen;
				for (y = 0; y < tokLen; y++, j++)
					auxTok[y] = str[j];
				tokList[k] = _strdup(auxTok);
				freezer(auxTok);
				tokLen = 0, k++;
			}

		if (!str[i + 1])
		{
			j = (i + 1) - tokLen;

			for (y = 0; y < tokLen; y++, j++)
				auxTok[y] = str[j];
			tokList[k] = _strdup(auxTok);
			freezer(auxTok);
			tokList[k + 1] = 0;
			ex++;
		}
	}
	tokListReturn = tokList;
	return (tokListReturn);
}

/**
 * freezer - All to null
 *
 * @str: String
 *
 * Return: 0
 */

int freezer(char *str)
{
	int n = 0;

	if (!str)
		return (-1);
	for (n = 0; str[n]; n++)
	{
		str[n] = 0;
	}
	return (0);
}
