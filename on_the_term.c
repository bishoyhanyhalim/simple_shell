#include "main.h"
/**
 * on_the_term - this func to check if in interactive
 * @sizeing: the size of buffer
 * @now_on_termi: check the terminal now
 *
 * Return: return the value check terminal
 */

void on_the_term(char *sizeing, int now_on_termi)
{

	if (now_on_termi)
	{
		for_print_char("$ ");
		fflush(stdout);
	}

	if (now_on_termi)
	{
		if (line_get_ADD(sizeing, ALL_SPASE, stdin) == NULL)
		{

			exit(127);

		}
	}

	else
	{

		if (line_get_ADD(sizeing, ALL_SPASE, stdin) == NULL)
		{

			exit(0);

		}
	}
}
