#include "main.h"
/**
 * cust_from_len - print custom func strlen
 * @line_char: this is a char
 *
 * Return: the value of len
*/

int cust_from_len(const char *line_char)
{

	int line_count = 0;

	if (!line_char)
	{

		return (0);

	}
	while (line_char[line_count] != '\0')
	{

		line_count++;

	}

	return (line_count);
}
