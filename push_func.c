#include "monty.h"

/**
*m_push - ...
*@head: ...
*@c: ...
*Return: ...
*/
void m_push(stack_t **head, unsigned int c)
{
	int n, i = 0, m = 0;

	if (bus.arg)
	{
		if (bus.arg[0] == '-')
		{
			i++;
		}
		for (; bus.arg[i] != '\0'; i++)
		{
			if (bus.arg[i] > 57 || bus.arg[i] < 48)
			{
				m = 1;
			}
		}
		if (m == 1)
		{
			fprintf(stderr, "L%d: usage: push integer", c);
			fclose(bus.file);
			free(bus.content);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer", c);
			fclose(bus.file);
			free(bus.content);
			exit(EXIT_FAILURE);
	}
	n = atoi(bus.arg);
	addnode(head, n);
}
