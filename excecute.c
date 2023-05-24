#include "monty.h"

/**
*m_execute - ...
*@head: ...
*@content: ...
*@c: ...
*@file: ...
*Return: ...
*/
int m_execute(char *content, stack_t **head, unsigned int c, FILE *file)
{
	instruction_t command[] = {
					{"push", m_push},
					{"pall", m_pall},
					{NULL, NULL}
					};
	unsigned int i = 0;
	char *op;

	op = strtok(content, " \n\t");
	if (op && op[0] == '#')
	{
		return (0);
	}
	bus.arg = strtok(NULL, " \n\t");
	while (command[i].opcode && op)
	{
		if (strcmp(op, command[i].opcode) == 0)
		{
			command[i].f(head, c);
			return (0);
		}
		i++;
	}
	if (op && command[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", c, op);
		fclose(file);
		free(content);
		exit(EXIT_FAILURE);
	}
	return (1);
}
